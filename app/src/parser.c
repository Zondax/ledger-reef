/*******************************************************************************
 *   (c) 2019 Zondax AG
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include "parser.h"

#include <stdio.h>
#include <zxformat.h>
#include <zxmacros.h>

#include "app_mode.h"
#include "coin.h"
#include "substrate_dispatch.h"

#define FIELD_FIXED_TOTAL_COUNT 7

#define FIELD_METHOD 0
#define FIELD_NETWORK 1
#define FIELD_NONCE 2
#define FIELD_TIP 3
#define FIELD_ERA_PHASE 4
#define FIELD_ERA_PERIOD 5
#define FIELD_BLOCK_HASH 6

#define EXPERT_FIELDS_TOTAL_COUNT 5

parser_error_t parser_parse(parser_context_t *ctx, const uint8_t *data, size_t dataLen, parser_tx_t *tx_obj) {
    CHECK_PARSER_ERR(parser_init(ctx, data, dataLen))
    ctx->tx_obj = tx_obj;
    ctx->tx_obj->nestCallIdx.slotIdx = 0;
    ctx->tx_obj->nestCallIdx._lenBuffer = 0;
    ctx->tx_obj->nestCallIdx._ptr = NULL;
    ctx->tx_obj->nestCallIdx._nextPtr = NULL;
    ctx->tx_obj->nestCallIdx.isTail = true;
    parser_error_t err = _readTx(ctx, ctx->tx_obj);
    CTX_CHECK_AVAIL(ctx, 0)

    return err;
}

__Z_INLINE bool parser_show_expert_fields() { return app_mode_expert(); }

bool parser_show_tip(const parser_context_t *ctx) {
    if (ctx->tx_obj->tip.value.len <= 4) {
        uint64_t v;
        _getValue(&ctx->tx_obj->tip.value, &v);
        if (v == 0) {
            return false;
        }
    }
    return true;
}

parser_error_t parser_validate(const parser_context_t *ctx) {
    // Iterate through all items to check that all can be shown and are valid
    uint8_t numItems = 0;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems))

    char tmpKey[40];
    char tmpVal[40];

    for (uint8_t idx = 0; idx < numItems; idx++) {
        uint8_t pageCount = 0;
        CHECK_PARSER_ERR(parser_getItem(ctx, idx, tmpKey, sizeof(tmpKey), tmpVal, sizeof(tmpVal), 0, &pageCount))
    }

    return parser_ok;
}

parser_error_t parser_getNumItems(const parser_context_t *ctx, uint8_t *num_items) {
    uint8_t methodArgCount = _getMethod_NumItems(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx,
                                                 ctx->tx_obj->callIndex.idx);

    uint8_t total = FIELD_FIXED_TOTAL_COUNT;
    if (!parser_show_tip(ctx)) {
        total -= 1;
    }
    if (!parser_show_expert_fields()) {
        total -= EXPERT_FIELDS_TOTAL_COUNT;

        for (uint8_t argIdx = 0; argIdx < methodArgCount; argIdx++) {
            bool isArgExpert = _getMethod_ItemIsExpert(
                ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx, ctx->tx_obj->callIndex.idx, argIdx);
            if (isArgExpert) {
                methodArgCount--;
            }
        }
    }

    *num_items = total + methodArgCount;
    return parser_ok;
}

parser_error_t parser_getItem(const parser_context_t *ctx, uint8_t displayIdx, char *outKey, uint16_t outKeyLen,
                              char *outVal, uint16_t outValLen, uint8_t pageIdx, uint8_t *pageCount) {
    MEMZERO(outKey, outKeyLen);
    MEMZERO(outVal, outValLen);
    snprintf(outKey, outKeyLen, "?");
    snprintf(outVal, outValLen, "?");
    *pageCount = 1;

    uint8_t numItems;
    CHECK_PARSER_ERR(parser_getNumItems(ctx, &numItems))
    CHECK_APP_CANARY()

    if (displayIdx >= numItems) {
        return parser_no_data;
    }

    parser_error_t err = parser_unexpected_error;
    if (displayIdx == FIELD_METHOD) {
        snprintf(outKey, outKeyLen, "%s",
                 _getMethod_ModuleName(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx));
        snprintf(outVal, outValLen, "%s",
                 _getMethod_Name(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx,
                                 ctx->tx_obj->callIndex.idx));
        return parser_ok;
    }

    // VARIABLE ARGUMENTS
    uint8_t methodArgCount = _getMethod_NumItems(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx,
                                                 ctx->tx_obj->callIndex.idx);
    // Adjust offset when displayIdx > 0
    uint8_t argIdx = displayIdx - 1;

    if (!parser_show_expert_fields()) {
        // Search for the next non expert item
        while ((argIdx < methodArgCount) &&
               _getMethod_ItemIsExpert(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx,
                                       ctx->tx_obj->callIndex.idx, argIdx)) {
            argIdx++;
            displayIdx++;
        }
    }

    if (argIdx < methodArgCount) {
        snprintf(outKey, outKeyLen, "%s",
                 _getMethod_ItemName(ctx->tx_obj->transactionVersion, ctx->tx_obj->callIndex.moduleIdx,
                                     ctx->tx_obj->callIndex.idx, argIdx));

        return _getMethod_ItemValue(ctx->tx_obj->transactionVersion, &ctx->tx_obj->method,
                                    ctx->tx_obj->callIndex.moduleIdx, ctx->tx_obj->callIndex.idx, argIdx, outVal,
                                    outValLen, pageIdx, pageCount);
    } else {
        // CONTINUE WITH FIXED ARGUMENTS
        displayIdx -= methodArgCount;
        if (displayIdx == FIELD_NETWORK) {
            if (_getAddressType() == PK_ADDRESS_TYPE) {
                if (parser_show_expert_fields()) {
                    snprintf(outKey, outKeyLen, "Chain");
                    snprintf(outVal, outValLen, COIN_NAME);
                    return parser_ok;
                }
            } else {
                snprintf(outKey, outKeyLen, "Genesis Hash");
                return _toStringHash(&ctx->tx_obj->genesisHash, outVal, outValLen, pageIdx, pageCount);
            }
        }

        if (!parser_show_expert_fields()) {
            displayIdx++;
        }

        if (displayIdx == FIELD_NONCE && parser_show_expert_fields()) {
            snprintf(outKey, outKeyLen, "Nonce");
            return _toStringCompactIndex(&ctx->tx_obj->nonce, outVal, outValLen, pageIdx, pageCount);
        }

        if (!parser_show_expert_fields()) {
            displayIdx++;
        }

        if (displayIdx == FIELD_TIP && parser_show_tip(ctx)) {
            snprintf(outKey, outKeyLen, "Tip");
            err = _toStringCompactBalance(&ctx->tx_obj->tip, outVal, outValLen, pageIdx, pageCount);
            if (err != parser_ok) return err;
            number_inplace_trimming(outVal, 1);
            return err;
        }

        if (!parser_show_tip(ctx)) {
            displayIdx++;
        }

        if (displayIdx == FIELD_ERA_PHASE && parser_show_expert_fields()) {
            snprintf(outKey, outKeyLen, "Era Phase");
            uint64_to_str(outVal, outValLen, ctx->tx_obj->era.phase);
            return parser_ok;
        }

        if (!parser_show_expert_fields()) {
            displayIdx++;
        }

        if (displayIdx == FIELD_ERA_PERIOD && parser_show_expert_fields()) {
            snprintf(outKey, outKeyLen, "Era Period");
            uint64_to_str(outVal, outValLen, ctx->tx_obj->era.period);
            return parser_ok;
        }

        if (!parser_show_expert_fields()) {
            displayIdx++;
        }

        if (displayIdx == FIELD_BLOCK_HASH && parser_show_expert_fields()) {
            snprintf(outKey, outKeyLen, "Block");
            return _toStringHash(&ctx->tx_obj->blockHash, outVal, outValLen, pageIdx, pageCount);
        }

        return parser_no_data;
    }
}
