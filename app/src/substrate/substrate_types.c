/*******************************************************************************
 *  (c) 2019 - 2025 Zondax AG
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

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch.h"
#include "substrate_strings.h"

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v) { return _readUInt8(c, v); }

parser_error_t _readu8(parser_context_t *c, pd_u8_t *v) { return _readUInt8(c, v); }

parser_error_t _readu16(parser_context_t *c, pd_u16_t *v) { return _readUInt16(c, v); }

parser_error_t _readu32(parser_context_t *c, pd_u32_t *v) { return _readUInt32(c, v); }

parser_error_t _readu64(parser_context_t *c, pd_u64_t *v) { return _readUInt64(c, v); }

parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v) { return _readUInt32(c, v); }

parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v) { return _readCompactInt(c, v); }

parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v) { return _readCompactInt(c, v); }

parser_error_t _readCallImpl(parser_context_t *c, pd_Call_t *v, pd_MethodNested_t *m) {
    // If it's the first Call, store a pointer to it
    if (c->tx_obj->nestCallIdx._ptr == NULL) {
        c->tx_obj->nestCallIdx._ptr = c->buffer + c->offset;
        c->tx_obj->nestCallIdx._lenBuffer = c->bufferLen - c->offset;
    } else {
        // If _ptr is not null, and landed here, means we're inside a nested call.
        // We stored the pointer to the first Call and now we store
        // the pointer to the 'next' Call.
        if (c->tx_obj->nestCallIdx._nextPtr == NULL) {
            c->tx_obj->nestCallIdx._nextPtr = c->buffer + c->offset;
        }
    }

    // To keep track on how many nested Calls we have
    c->tx_obj->nestCallIdx.slotIdx++;
    if (c->tx_obj->nestCallIdx.slotIdx > MAX_CALL_NESTING_SIZE) {
        return parser_tx_nesting_limit_reached;
    }

    CHECK_ERROR(_readCallIndex(c, &v->callIndex));

    if (!_getMethod_IsNestingSupported(c->tx_obj->transactionVersion, v->callIndex.moduleIdx, v->callIndex.idx)) {
        return parser_tx_nesting_not_supported;
    }

    // Read and check the contained method on this Call
    CHECK_ERROR(_readMethod(c, v->callIndex.moduleIdx, v->callIndex.idx, (pd_Method_t *)m))

    // The instance of 'v' corresponding to the upper call on the stack (persisted variable)
    // will end up having the pointer to the first Call and to the 'next' one if exists.
    v->_txVerPtr = &c->tx_obj->transactionVersion;
    v->nestCallIdx._lenBuffer = c->tx_obj->nestCallIdx._lenBuffer;
    v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
    v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;

    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
parser_error_t _readCompactEraIndex(parser_context_t *c, pd_CompactEraIndex_t *v) { return _readCompactInt(c, v); }
parser_error_t _readCompactMemberCount(parser_context_t *c, pd_CompactMemberCount_t *v) {
    return _readCompactInt(c, v);
}
parser_error_t _readCompactMoment(parser_context_t *c, pd_CompactMoment_t *v) { return _readCompactInt(c, v); }
parser_error_t _readCompactProposalIndex(parser_context_t *c, pd_CompactProposalIndex_t *v) {
    return _readCompactInt(c, v);
}
parser_error_t _readCompactRegistrarIndex(parser_context_t *c, pd_CompactRegistrarIndex_t *v) {
    return _readCompactInt(c, v);
}
parser_error_t _readCompactWeight(parser_context_t *c, pd_CompactWeight_t *v) { return _readCompactInt(c, v); }

parser_error_t _readData(parser_context_t *c, pd_Data_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value <= 1) {
        return parser_ok;
    } else if (v->value <= 37) {
        const uint8_t length = v->value <= 32 ? v->value - 1 : 32;
        GEN_DEF_READARRAY(length)
    } else {
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readTupleDataData(parser_context_t *c, pd_TupleDataData_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readData(c, &v->data1))
    CHECK_ERROR(_readData(c, &v->data2))
    return parser_ok;
}

parser_error_t _readu8_array_20(parser_context_t *c, pd_u8_array_20_t *v){GEN_DEF_READARRAY(20)}

parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v){GEN_DEF_READARRAY(16)}

parser_error_t _readCall(parser_context_t *c, pd_Call_t *v) {
    pd_MethodNested_t _method;
    if (c->tx_obj->nestCallIdx.isTail) {
        c->tx_obj->nestCallIdx.isTail = false;
        v->nestCallIdx.isTail = true;
    } else {
        v->nestCallIdx.isTail = false;
    }

    CHECK_ERROR(_readCallImpl(c, v, &_method))
    if (c->tx_obj->nestCallIdx._ptr != NULL && c->tx_obj->nestCallIdx._nextPtr != NULL) {
        v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
        v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;
    }
    v->nestCallIdx.slotIdx = c->tx_obj->nestCallIdx.slotIdx;
    return parser_ok;
}

parser_error_t _readChangesTrieConfiguration(parser_context_t *c, pd_ChangesTrieConfiguration_t *v) {
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCompactPerBill(parser_context_t *c, pd_CompactPerBill_t *v) {
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCurrencyId(parser_context_t *c, pd_CurrencyId_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readHeader(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Header_t *v) { return parser_not_supported; }

parser_error_t _readKeyValue(parser_context_t *c, pd_KeyValue_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readKey(parser_context_t *c, pd_Key_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readCompactAccountIndex(parser_context_t *c, pd_CompactAccountIndex_t *v) {
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPercent(parser_context_t *c, pd_Percent_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readPeriod(parser_context_t *c, pd_Period_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readStreamDependency(parser_context_t *c, pd_StreamDependency_t *v) {
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTimepoint(parser_context_t *c, pd_Timepoint_t *v) {
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData(parser_context_t *c, pd_TupleAccountIdData_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->id));
    CHECK_ERROR(_readData(c, &v->data));
    return parser_ok;
}

parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v) { return _readBalance(c, &v->value); }

parser_error_t _readIdentityInfo(parser_context_t *c, pd_IdentityInfo_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readVecTupleDataData(c, &v->additional));
    CHECK_ERROR(_readData(c, &v->display));
    CHECK_ERROR(_readData(c, &v->legal));
    CHECK_ERROR(_readData(c, &v->web));
    CHECK_ERROR(_readData(c, &v->riot));
    CHECK_ERROR(_readData(c, &v->email));
    CHECK_ERROR(_readOptionu8_array_20(c, &v->pgp_fingerprint));
    CHECK_ERROR(_readData(c, &v->image));
    CHECK_ERROR(_readData(c, &v->twitter));
    return parser_ok;
}

parser_error_t _readOpaqueCall(parser_context_t *c, pd_OpaqueCall_t *v) {
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readPriority(parser_context_t *c, pd_Priority_t *v) {
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProposal(parser_context_t *c, pd_Proposal_t *v) { return _readCall(c, &v->call); }

parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value == 3) {
        CHECK_ERROR(_readAccountId(c, &v->accountId))
    } else if (v->value > 4) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v) {
    compactInt_t clen;
    pd_Call_t dummy;
    CHECK_PARSER_ERR(_readCompactInt(c, &clen));
    CHECK_PARSER_ERR(_getValue(&clen, &v->_len));

    if (v->_len > MAX_CALL_VEC_SIZE) {
        return parser_tx_call_vec_too_large;
    }

    v->_ptr = c->buffer + c->offset;
    v->_lenBuffer = c->offset;
    if (v->_len == 0) {
        return parser_unexpected_buffer_end;
    }

    for (uint64_t i = 0; i < v->_len; i++) {
        c->tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCall(c, &dummy))
    }
    v->_lenBuffer = c->offset - v->_lenBuffer;
    v->callTxVersion = c->tx_obj->transactionVersion;

    return parser_ok;
}

parser_error_t _readWeight(parser_context_t *c, pd_Weight_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu64(c, &v->refTime))
    CHECK_ERROR(_readCompactu64(c, &v->proofSize))
    return parser_ok;
}

parser_error_t _readAccountIndex(parser_context_t *c, pd_AccountIndex_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAmountOf(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_AmountOf_t *v) {
    return parser_not_supported;
}

parser_error_t _readAsOriginId(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_AsOriginId_t *v) {
    return parser_not_supported;
}

parser_error_t _readBabeEquivocationProof(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_BabeEquivocationProof_t *v) {
    return parser_not_supported;
}

parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v) {
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}

parser_error_t _readLookupSource(parser_context_t *c, pd_LookupSource_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
        case 0:  // Id
            CHECK_ERROR(_readAccountId(c, &v->id))
            break;
        case 1:  // Index
            CHECK_ERROR(_readCompactAccountIndex(c, &v->index))
            break;
        case 2:  // Raw
            CHECK_ERROR(_readBytes(c, &v->raw))
            break;
        case 3:  // Address32
            GEN_DEF_READARRAY(32)
        case 4:  // Address20
            GEN_DEF_READARRAY(20)
        default:
            return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCallOf(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_CallOf_t *v) { return parser_not_supported; }

parser_error_t _readCompactBalanceOf(parser_context_t *c, pd_CompactBalanceOf_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readCompactInt(c, &v->value));
    return parser_ok;
}

parser_error_t _readCurrencyIdOf(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_CurrencyIdOf_t *v) {
    return parser_not_supported;
}

parser_error_t _readDispatchTime(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_DispatchTime_t *v) {
    return parser_not_supported;
}

parser_error_t _readEcdsaSignature(parser_context_t *c, pd_EcdsaSignature_t *v){GEN_DEF_READARRAY(65)}

parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEvmAddress(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_EvmAddress_t *v) {
    return parser_not_supported;
}

parser_error_t _readGrandpaEquivocationProof(__Z_UNUSED parser_context_t *c,
                                             __Z_UNUSED pd_GrandpaEquivocationProof_t *v) {
    return parser_not_supported;
}

parser_error_t _readH256(parser_context_t *c, pd_H256_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readHeartbeat(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Heartbeat_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityFields(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_IdentityFields_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityJudgement(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_IdentityJudgement_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_KeyOwnerProof_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeys(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Keys_t *v) {
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readLockDuration(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_LockDuration_t *v) {
    return parser_not_supported;
}

parser_error_t _readMemberCount(parser_context_t *c, pd_MemberCount_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readNextConfigDescriptor(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_NextConfigDescriptor_t *v) {
    return parser_not_supported;
}

parser_error_t _readPalletsOrigin(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_PalletsOrigin_t *v) {
    return parser_not_supported;
}

parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRegistrarIndex(parser_context_t *c, pd_RegistrarIndex_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readScheduleTaskIndex(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_ScheduleTaskIndex_t *v) {
    return parser_not_supported;
}

parser_error_t _readSignature(parser_context_t *c, pd_Signature_t *v){GEN_DEF_READARRAY(64)}

parser_error_t _readVecHeader(parser_context_t *c, pd_VecHeader_t *v){GEN_DEF_READVECTOR(Header)}

parser_error_t _readVecTupleDataData(parser_context_t *c, pd_VecTupleDataData_t *v){GEN_DEF_READVECTOR(TupleDataData)}

parser_error_t _readVecTupleAccountIdData(parser_context_t *c,
                                          pd_VecTupleAccountIdData_t *v){GEN_DEF_READVECTOR(TupleAccountIdData)}

parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v){GEN_DEF_READVECTOR(AccountId)}

parser_error_t _readVecKeyValue(parser_context_t *c, pd_VecKeyValue_t *v){GEN_DEF_READVECTOR(KeyValue)}

parser_error_t _readVecKey(parser_context_t *c, pd_VecKey_t *v){GEN_DEF_READVECTOR(Key)}

parser_error_t _readVecLookupSource(parser_context_t *c, pd_VecLookupSource_t *v){GEN_DEF_READVECTOR(LookupSource)}

parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v){GEN_DEF_READVECTOR(u32)}

parser_error_t _readOptionu8_array_20(parser_context_t *c, pd_Optionu8_array_20_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8_array_20(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration(parser_context_t *c, pd_OptionChangesTrieConfiguration_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint(parser_context_t *c, pd_OptionTimepoint_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAccountId(parser_context_t *c, pd_OptionAccountId_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionCurrencyId(parser_context_t *c, pd_OptionCurrencyId_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readCurrencyId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPercent(parser_context_t *c, pd_OptionPercent_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPercent(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod(parser_context_t *c, pd_OptionPeriod_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu32(parser_context_t *c, pd_Optionu32_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu32(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);

    *pageCount = 1;
    switch (*v) {
        case 0:
            snprintf(outValue, outValueLen, "False");
            return parser_ok;
        case 1:
            snprintf(outValue, outValueLen, "True");
            return parser_ok;
    }

    return parser_not_supported;
}

parser_error_t _toStringu8(const pd_u8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                           uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBlockNumber(const pd_BlockNumber_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount) {
    return _toStringu32(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu32(const pd_Compactu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu64(const pd_Compactu64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactEraIndex(const pd_CompactEraIndex_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMemberCount(const pd_CompactMemberCount_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment(const pd_CompactMoment_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex(const pd_CompactProposalIndex_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactRegistrarIndex(const pd_CompactRegistrarIndex_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight(const pd_CompactWeight_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringData(const pd_Data_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    *pageCount = 1;
    if (v->value == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    } else if (v->value == 1) {
        snprintf(outValue, outValueLen, "Empty raw");
        return parser_ok;
    } else if (v->value > 37) {
        return parser_unexpected_value;
    }
    const uint8_t length = v->value <= 32 ? v->value - 1 : 32;
    bool allPrintable = true;
    if (v->value <= 33) {
        for (uint8_t i = 0; i < length; i++) {
            allPrintable &= IS_PRINTABLE(v->_ptr[i]);
        }
    }
    if (v->value <= 33 && allPrintable) {
        char bufferUI[40] = {0};
        snprintf(bufferUI, length + 1, "%s", v->_ptr);  // it counts null terminator
        pageString(outValue, outValueLen, (const char *)bufferUI, pageIdx, pageCount);
    } else {
        GEN_DEF_TOSTRING_ARRAY(length)
    }
    return parser_ok;
}

parser_error_t _toStringAccountId(const pd_AccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringTupleDataData(const pd_TupleDataData_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringData(&v->data1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringu8_array_20(const pd_u8_array_20_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount){GEN_DEF_TOSTRING_ARRAY(20)}

parser_error_t
    _toStringBalance(const pd_Balance_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    char bufferUI[200];
    memset(outValue, 0, outValueLen);
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), COIN_AMOUNT_DECIMAL_PLACES) == 0) {
        return parser_unexpected_value;
    }

    number_inplace_trimming(bufferUI, 1);
    number_inplace_trimming(bufferUI, 1);
    if (z_str3join(bufferUI, sizeof(bufferUI), COIN_TICKER, "") != zxerr_ok) {
        return parser_print_not_supported;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    *pageCount = 1;

    parser_context_t ctx;

    const uint8_t *buffer;
    if (v->nestCallIdx.isTail) {
        buffer = v->nestCallIdx._ptr;
    } else {
        buffer = v->nestCallIdx._nextPtr;
    }

    parser_init(&ctx, buffer, v->nestCallIdx._lenBuffer);
    parser_tx_t _txObj;

    pd_Call_t _call;
    _call.nestCallIdx.isTail = false;

    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = *v->_txVerPtr;

    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx.isTail = false;

    // Read the Call, so we get the contained Method
    parser_error_t err = _readCallImpl(&ctx, &_call, (pd_MethodNested_t *)&_txObj.method);
    if (err != parser_ok) {
        return err;
    }

    // Get num items of this current Call
    uint8_t callNumItems = _getMethod_NumItems(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx);

    // Count how many pages this call has (including nested ones if they exists)
    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, _call.callIndex.moduleIdx, _call.callIndex.idx, i, outValue,
                             outValueLen, 0, &itemPages);
        (*pageCount) += itemPages;
    }

    if (pageIdx == 0) {
        snprintf(outValue, outValueLen, "%s", _getMethod_Name(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx));
        return parser_ok;
    }

    pageIdx--;

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i, outValue,
                             outValueLen, 0, &itemPages);

        if (pageIdx < itemPages) {
            uint8_t tmp;
            _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i, outValue,
                                 outValueLen, pageIdx, &tmp);
            return parser_ok;
        }

        pageIdx -= itemPages;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringChangesTrieConfiguration(const pd_ChangesTrieConfiguration_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactPerBill(const pd_CompactPerBill_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurrencyId(const pd_CurrencyId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringHeader(__Z_UNUSED const pd_Header_t *v, __Z_UNUSED char *outValue,
                               __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                               __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue(__Z_UNUSED const pd_KeyValue_t *v, __Z_UNUSED char *outValue,
                                 __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                 __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey(__Z_UNUSED const pd_Key_t *v, __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                            __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringCompactAccountIndex(const pd_CompactAccountIndex_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringLookupSource(const pd_LookupSource_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    switch (v->value) {
        case 0:  // Id
            CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 1:  // Index
            CHECK_ERROR(_toStringCompactAccountIndex(&v->index, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 2:  // Raw
            CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
            break;
        case 3:  // Address32
        {
            GEN_DEF_TOSTRING_ARRAY(32)
        }
        case 4:  // Address20
        {
            GEN_DEF_TOSTRING_ARRAY(20)
        }
        default:
            return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringPercent(const pd_Percent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount) {
    char bufferUI[51];
    char bufferRatio[50];

    uint64_to_str(bufferRatio, sizeof(bufferRatio), v->value);

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", bufferRatio);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPeriod(const pd_Period_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount) {
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringStreamDependency(const pd_StreamDependency_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = {0};
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t *)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t *)&v->weight, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTimepoint(const pd_Timepoint_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountIdData(const pd_TupleAccountIdData_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->data, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->data, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBalanceOf(const pd_BalanceOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    return _toStringBalance(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringIdentityInfo(const pd_IdentityInfo_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9] = {0};
    CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleDataData(&v->additional, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringData(&v->display, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringData(&v->legal, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringData(&v->web, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringData(&v->riot, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringData(&v->email, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionu8_array_20(&v->pgp_fingerprint, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringData(&v->image, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringData(&v->twitter, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOpaqueCall(const pd_OpaqueCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPriority(const pd_Priority_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposal(const pd_Proposal_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount) {
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination(const pd_RewardDestination_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
        case 0:
            snprintf(outValue, outValueLen, "Staked");
            break;
        case 1:
            snprintf(outValue, outValueLen, "Stash");
            break;
        case 2:
            snprintf(outValue, outValueLen, "Controller");
            break;
        case 3:
            CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, pageCount));
            break;
        case 4:
            snprintf(outValue, outValueLen, "None");
            break;
        default:
            return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringValidatorPrefs(const pd_ValidatorPrefs_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringCompactPerBill(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVecCall(const pd_VecCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    /* count number of pages, then output specific */
    *pageCount = 0;
    uint8_t chunkPageCount;
    uint16_t currentPage, currentTotalPage = 0;
    /* We need to do it twice because there is no memory to keep intermediate results*/
    /* First count*/
    parser_context_t ctx;
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    parser_tx_t _txObj;
    pd_Call_t _call;
    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = v->callTxVersion;
    _call._txVerPtr = &v->callTxVersion;
    _call.nestCallIdx.isTail = true;

    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx.isTail = true;

    for (uint64_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t *)&_txObj.method));
        CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, 0, &chunkPageCount));
        (*pageCount) += chunkPageCount;
    }

    /* Then iterate until we can print the corresponding chunk*/
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    for (uint64_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t *)&_txObj.method));
        chunkPageCount = 1;
        currentPage = 0;
        while (currentPage < chunkPageCount) {
            CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, currentPage, &chunkPageCount));
            if (currentTotalPage == pageIdx) {
                return parser_ok;
            }
            currentPage++;
            currentTotalPage++;
        }
    }

    return parser_print_not_supported;
}

parser_error_t _toStringWeight(const pd_Weight_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = {0};
    CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAccountIndex(const pd_AccountIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAmountOf(__Z_UNUSED const pd_AmountOf_t *v, __Z_UNUSED char *outValue,
                                 __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                 __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAsOriginId(__Z_UNUSED const pd_AsOriginId_t *v, __Z_UNUSED char *outValue,
                                   __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                   __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBabeEquivocationProof(__Z_UNUSED const pd_BabeEquivocationProof_t *v, __Z_UNUSED char *outValue,
                                              __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                              __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBytes(const pd_Bytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}

parser_error_t _toStringCallOf(__Z_UNUSED const pd_CallOf_t *v, __Z_UNUSED char *outValue,
                               __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                               __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringCompactBalanceOf(const pd_CompactBalanceOf_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    CHECK_ERROR(_toStringCompactInt(&v->value, COIN_AMOUNT_DECIMAL_PLACES, true, "", COIN_TICKER, outValue, outValueLen,
                                    pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringCurrencyIdOf(__Z_UNUSED const pd_CurrencyIdOf_t *v, __Z_UNUSED char *outValue,
                                     __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                     __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringDispatchTime(__Z_UNUSED const pd_DispatchTime_t *v, __Z_UNUSED char *outValue,
                                     __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                     __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEcdsaSignature(const pd_EcdsaSignature_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount){GEN_DEF_TOSTRING_ARRAY(65)}

parser_error_t _toStringEraIndex(const pd_EraIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEvmAddress(__Z_UNUSED const pd_EvmAddress_t *v, __Z_UNUSED char *outValue,
                                   __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                   __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringGrandpaEquivocationProof(__Z_UNUSED const pd_GrandpaEquivocationProof_t *v,
                                                 __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                                                 __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringH256(const pd_H256_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32);
}

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount){GEN_DEF_TOSTRING_ARRAY(32)}

parser_error_t
    _toStringHeartbeat(__Z_UNUSED const pd_Heartbeat_t *v, __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                       __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields(__Z_UNUSED const pd_IdentityFields_t *v, __Z_UNUSED char *outValue,
                                       __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                       __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityJudgement(__Z_UNUSED const pd_IdentityJudgement_t *v, __Z_UNUSED char *outValue,
                                          __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                          __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof(__Z_UNUSED const pd_KeyOwnerProof_t *v, __Z_UNUSED char *outValue,
                                      __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                      __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeys(__Z_UNUSED const pd_Keys_t *v, __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                             __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount){GEN_DEF_TOSTRING_ARRAY(4 * 32)}

parser_error_t
    _toStringLockDuration(__Z_UNUSED const pd_LockDuration_t *v, __Z_UNUSED char *outValue,
                          __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringMemberCount(const pd_MemberCount_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringNextConfigDescriptor(__Z_UNUSED const pd_NextConfigDescriptor_t *v, __Z_UNUSED char *outValue,
                                             __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                             __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPalletsOrigin(__Z_UNUSED const pd_PalletsOrigin_t *v, __Z_UNUSED char *outValue,
                                      __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                      __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill(const pd_Perbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount) {
    char bufferUI[100] = {0};
    char ratioBuffer[80] = {0};
    memset(outValue, 0, outValueLen);
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringRegistrarIndex(const pd_RegistrarIndex_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringScheduleTaskIndex(__Z_UNUSED const pd_ScheduleTaskIndex_t *v, __Z_UNUSED char *outValue,
                                          __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                          __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringSignature(const pd_Signature_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount){GEN_DEF_TOSTRING_ARRAY(64)}

parser_error_t _toStringVecHeader(const pd_VecHeader_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount){GEN_DEF_TOSTRING_VECTOR(Header)}

parser_error_t _toStringVecTupleDataData(const pd_VecTupleDataData_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(TupleDataData);
}

parser_error_t _toStringVecTupleAccountIdData(const pd_VecTupleAccountIdData_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData);
}

parser_error_t _toStringVecAccountId(const pd_VecAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(AccountId);
}

parser_error_t _toStringVecKeyValue(const pd_VecKeyValue_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(KeyValue);
}

parser_error_t _toStringVecKey(const pd_VecKey_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(Key);
}

parser_error_t _toStringVecLookupSource(const pd_VecLookupSource_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(LookupSource);
}

parser_error_t _toStringVecu32(const pd_Vecu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(u32);
}

parser_error_t _toStringOptionu8_array_20(const pd_Optionu8_array_20_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu8_array_20(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration(const pd_OptionChangesTrieConfiguration_t *v, char *outValue,
                                                       uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint(const pd_OptionTimepoint_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionAccountId(const pd_OptionAccountId_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionCurrencyId(const pd_OptionCurrencyId_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringCurrencyId(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPercent(const pd_OptionPercent_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPercent(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod(const pd_OptionPeriod_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu32(const pd_Optionu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu32(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
