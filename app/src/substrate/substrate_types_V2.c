/*******************************************************************************
 *  (c) 2019 Zondax GmbH
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
#include <zxmacros.h>

#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxformat.h"

parser_error_t _readCompactAssignments_V2(parser_context_t *c, pd_CompactAssignments_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V2(parser_context_t *c, pd_CompactEraIndex_V2_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMemberCount_V2(parser_context_t *c, pd_CompactMemberCount_V2_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V2(parser_context_t *c, pd_CompactMoment_V2_t *v) { return _readCompactInt(c, v); }

parser_error_t _readCompactProposalIndex_V2(parser_context_t *c, pd_CompactProposalIndex_V2_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactRegistrarIndex_V2(parser_context_t *c, pd_CompactRegistrarIndex_V2_t *v) {
    return _readCompactInt(c, v);
}

parser_error_t _readCompactWeight_V2(parser_context_t *c, pd_CompactWeight_V2_t *v) { return _readCompactInt(c, v); }

parser_error_t _readAccountId_V2(parser_context_t *c, pd_AccountId_V2_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readAccountIndex_V2(parser_context_t *c, pd_AccountIndex_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAmountOf_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_AmountOf_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readAsOriginId_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_AsOriginId_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readBabeEquivocationProof_V2(__Z_UNUSED parser_context_t *c,
                                             __Z_UNUSED pd_BabeEquivocationProof_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readCallOf_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_CallOf_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readChangesTrieConfiguration_V2(parser_context_t *c, pd_ChangesTrieConfiguration_V2_t *v) {
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCompactPerBill_V2(parser_context_t *c, pd_CompactPerBill_V2_t *v) {
    return _readCompactInt(c, &v->value);
}

parser_error_t _readCurrencyIdOf_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_CurrencyIdOf_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readCurrencyId_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_CurrencyId_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readDispatchTime_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_DispatchTime_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readEcdsaSignature_V2(__Z_UNUSED parser_context_t *c,
                                      __Z_UNUSED pd_EcdsaSignature_V2_t *v){GEN_DEF_READARRAY(65)}

parser_error_t _readEraIndex_V2(parser_context_t *c, pd_EraIndex_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readEvmAddress_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_EvmAddress_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readGrandpaEquivocationProof_V2(__Z_UNUSED parser_context_t *c,
                                                __Z_UNUSED pd_GrandpaEquivocationProof_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityFields_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_IdentityFields_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readIdentityInfo_V2(parser_context_t *c, pd_IdentityInfo_V2_t *v) {
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

parser_error_t _readIdentityJudgement_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_IdentityJudgement_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_KeyOwnerProof_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readKeyValue_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_KeyValue_V2_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readKey_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Key_V2_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readKeys_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Keys_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readLockDuration_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_LockDuration_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readLookupSource_V2(__Z_UNUSED parser_context_t *c,
                                    __Z_UNUSED pd_LookupSource_V2_t *v){GEN_DEF_READARRAY(32)}

parser_error_t _readMemberCount_V2(parser_context_t *c, pd_MemberCount_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readNextConfigDescriptor_V2(__Z_UNUSED parser_context_t *c,
                                            __Z_UNUSED pd_NextConfigDescriptor_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readOpaqueCall_V2(parser_context_t *c, pd_OpaqueCall_V2_t *v) {
    // Encoded as Byte[], array size comes first
    uint8_t size;
    CHECK_ERROR(_readUInt8(c, &size))
    return _readCall(c, &v->call);
}

parser_error_t _readPalletsOrigin_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_PalletsOrigin_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readPerbill_V2(parser_context_t *c, pd_Perbill_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPercent_V2(parser_context_t *c, pd_Percent_V2_t *v) { return _readCompactInt(c, &v->value); }

parser_error_t _readPeriod_V2(parser_context_t *c, pd_Period_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readPriority_V2(parser_context_t *c, pd_Priority_V2_t *v) {
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V2(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readRegistrarIndex_V2(parser_context_t *c, pd_RegistrarIndex_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRewardDestination_V2(parser_context_t *c, pd_RewardDestination_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readScheduleTaskIndex_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_ScheduleTaskIndex_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readSignature_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_Signature_V2_t *v){GEN_DEF_READARRAY(64)}

parser_error_t _readStreamDependency_V2(parser_context_t *c, pd_StreamDependency_V2_t *v) {
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTimepoint_V2(parser_context_t *c, pd_Timepoint_V2_t *v) {
    CHECK_ERROR(_readBlockNumber(c, &v->height))
    CHECK_ERROR(_readu32(c, &v->index))
    return parser_ok;
}

parser_error_t _readTupleAccountIdData_V2(__Z_UNUSED parser_context_t *c, __Z_UNUSED pd_TupleAccountIdData_V2_t *v) {
    return parser_not_supported;
}

parser_error_t _readValidatorPrefs_V2(parser_context_t *c, pd_ValidatorPrefs_V2_t *v) {
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill_V2(c, &v->commission));
    CHECK_ERROR(_readbool(c, &v->blocked))
    return parser_ok;
}

parser_error_t _readWeight_V2(parser_context_t *c, pd_Weight_V2_t *v) {
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readVecAccountId_V2(parser_context_t *c, pd_VecAccountId_V2_t *v){GEN_DEF_READVECTOR(AccountId_V2)}

parser_error_t _readVecKeyValue_V2(parser_context_t *c, pd_VecKeyValue_V2_t *v){GEN_DEF_READVECTOR(KeyValue_V2)}

parser_error_t _readVecKey_V2(parser_context_t *c, pd_VecKey_V2_t *v){GEN_DEF_READVECTOR(Key_V2)}

parser_error_t
    _readVecLookupSource_V2(parser_context_t *c, pd_VecLookupSource_V2_t *v){GEN_DEF_READVECTOR(LookupSource_V2)}

parser_error_t _readVecTupleAccountIdData_V2(parser_context_t *c, pd_VecTupleAccountIdData_V2_t *v){
    GEN_DEF_READVECTOR(TupleAccountIdData_V2)}

parser_error_t _readOptionAccountId_V2(parser_context_t *c, pd_OptionAccountId_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAccountId_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration_V2(parser_context_t *c, pd_OptionChangesTrieConfiguration_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionCurrencyId_V2(parser_context_t *c, pd_OptionCurrencyId_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readCurrencyId_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPercent_V2(parser_context_t *c, pd_OptionPercent_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPercent_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V2(parser_context_t *c, pd_OptionPeriod_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V2(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTimepoint_V2(parser_context_t *c, pd_OptionTimepoint_V2_t *v) {
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTimepoint_V2(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactEraIndex_V2(const pd_CompactEraIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMemberCount_V2(const pd_CompactMemberCount_V2_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V2(const pd_CompactMoment_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex_V2(const pd_CompactProposalIndex_V2_t *v, char *outValue,
                                                uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactRegistrarIndex_V2(const pd_CompactRegistrarIndex_V2_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactWeight_V2(const pd_CompactWeight_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V2(const pd_AccountId_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V2(const pd_AccountIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAmountOf_V2(__Z_UNUSED const pd_AmountOf_V2_t *v, __Z_UNUSED char *outValue,
                                    __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                    __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringAsOriginId_V2(__Z_UNUSED const pd_AsOriginId_V2_t *v, __Z_UNUSED char *outValue,
                                      __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                      __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringBabeEquivocationProof_V2(__Z_UNUSED const pd_BabeEquivocationProof_V2_t *v,
                                                 __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                                                 __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringCallOf_V2(__Z_UNUSED const pd_CallOf_V2_t *v, __Z_UNUSED char *outValue,
                                  __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                  __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringChangesTrieConfiguration_V2(const pd_ChangesTrieConfiguration_V2_t *v, char *outValue,
                                                    uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
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

parser_error_t _toStringCompactPerBill_V2(const pd_CompactPerBill_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount) {
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCurrencyIdOf_V2(__Z_UNUSED const pd_CurrencyIdOf_V2_t *v, __Z_UNUSED char *outValue,
                                        __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                        __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringCurrencyId_V2(__Z_UNUSED const pd_CurrencyId_V2_t *v, __Z_UNUSED char *outValue,
                                      __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                      __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringDispatchTime_V2(__Z_UNUSED const pd_DispatchTime_V2_t *v, __Z_UNUSED char *outValue,
                                        __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                        __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringEcdsaSignature_V2(__Z_UNUSED const pd_EcdsaSignature_V2_t *v, __Z_UNUSED char *outValue,
                                          __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                          __Z_UNUSED uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65);
    return parser_ok;
}

parser_error_t _toStringEraIndex_V2(const pd_EraIndex_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEvmAddress_V2(__Z_UNUSED const pd_EvmAddress_V2_t *v, __Z_UNUSED char *outValue,
                                      __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                      __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringGrandpaEquivocationProof_V2(__Z_UNUSED const pd_GrandpaEquivocationProof_V2_t *v,
                                                    __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                                                    __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityFields_V2(__Z_UNUSED const pd_IdentityFields_V2_t *v, __Z_UNUSED char *outValue,
                                          __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                          __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityInfo_V2(const pd_IdentityInfo_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9];
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

    if (pageIdx > *pageCount) {
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

parser_error_t _toStringIdentityJudgement_V2(__Z_UNUSED const pd_IdentityJudgement_V2_t *v, __Z_UNUSED char *outValue,
                                             __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                             __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V2(__Z_UNUSED const pd_KeyOwnerProof_V2_t *v, __Z_UNUSED char *outValue,
                                         __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                         __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V2(__Z_UNUSED const pd_KeyValue_V2_t *v, __Z_UNUSED char *outValue,
                                    __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                    __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V2(__Z_UNUSED const pd_Key_V2_t *v, __Z_UNUSED char *outValue,
                               __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                               __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V2(__Z_UNUSED const pd_Keys_V2_t *v, __Z_UNUSED char *outValue,
                                __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLockDuration_V2(__Z_UNUSED const pd_LockDuration_V2_t *v, __Z_UNUSED char *outValue,
                                        __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                        __Z_UNUSED uint8_t *pageCount) {
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLookupSource_V2(const pd_LookupSource_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemberCount_V2(const pd_MemberCount_V2_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringNextConfigDescriptor_V2(__Z_UNUSED const pd_NextConfigDescriptor_V2_t *v,
                                                __Z_UNUSED char *outValue, __Z_UNUSED uint16_t outValueLen,
                                                __Z_UNUSED uint8_t pageIdx, __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringOpaqueCall_V2(const pd_OpaqueCall_V2_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPalletsOrigin_V2(__Z_UNUSED const pd_PalletsOrigin_V2_t *v, __Z_UNUSED char *outValue,
                                         __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                         __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringPerbill_V2(const pd_Perbill_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent_V2(const pd_Percent_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount) {
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPeriod_V2(const pd_Period_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPriority_V2(const pd_Priority_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V2(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency_V2(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringRegistrarIndex_V2(const pd_RegistrarIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount) {
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination_V2(const pd_RewardDestination_V2_t *v, char *outValue, uint16_t outValueLen,
                                             __Z_UNUSED uint8_t pageIdx, uint8_t *pageCount) {
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
        default:
            return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringScheduleTaskIndex_V2(__Z_UNUSED const pd_ScheduleTaskIndex_V2_t *v, __Z_UNUSED char *outValue,
                                             __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                             __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringSignature_V2(__Z_UNUSED const pd_Signature_V2_t *v, __Z_UNUSED char *outValue,
                                     __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                     __Z_UNUSED uint8_t *pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64);
    return parser_ok;
}

parser_error_t _toStringStreamDependency_V2(const pd_StreamDependency_V2_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t *)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
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

parser_error_t _toStringTimepoint_V2(const pd_Timepoint_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBlockNumber(&v->height, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->index, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
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

parser_error_t _toStringTupleAccountIdData_V2(__Z_UNUSED const pd_TupleAccountIdData_V2_t *v, __Z_UNUSED char *outValue,
                                              __Z_UNUSED uint16_t outValueLen, __Z_UNUSED uint8_t pageIdx,
                                              __Z_UNUSED uint8_t *pageCount) {
    return parser_print_not_supported;
}

parser_error_t _toStringValidatorPrefs_V2(const pd_ValidatorPrefs_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactPerBill_V2(&v->commission, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactPerBill_V2(&v->commission, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->blocked, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringWeight_V2(const pd_Weight_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V2(const pd_VecAccountId_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(AccountId_V2);
}

parser_error_t _toStringVecKeyValue_V2(const pd_VecKeyValue_V2_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V2);
}

parser_error_t _toStringVecKey_V2(const pd_VecKey_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(Key_V2);
}

parser_error_t _toStringVecLookupSource_V2(const pd_VecLookupSource_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(LookupSource_V2);
}

parser_error_t _toStringVecTupleAccountIdData_V2(const pd_VecTupleAccountIdData_V2_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    GEN_DEF_TOSTRING_VECTOR(TupleAccountIdData_V2);
}

parser_error_t _toStringOptionAccountId_V2(const pd_OptionAccountId_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAccountId_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration_V2(const pd_OptionChangesTrieConfiguration_V2_t *v,
                                                          char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                                          uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionCurrencyId_V2(const pd_OptionCurrencyId_V2_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringCurrencyId_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPercent_V2(const pd_OptionPercent_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPercent_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V2(const pd_OptionPeriod_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTimepoint_V2(const pd_OptionTimepoint_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount) {
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTimepoint_V2(&v->contained, outValue, outValueLen, pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
