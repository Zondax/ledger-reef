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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "parser_common.h"
#include "substrate_methods_V2.h"
#include "substrate_types_V2.h"

// Read functions
parser_error_t _readAccountId_V2(parser_context_t *c, pd_AccountId_V2_t *v);
parser_error_t _readAccountIndex_V2(parser_context_t *c, pd_AccountIndex_V2_t *v);
parser_error_t _readAmountOf_V2(parser_context_t *c, pd_AmountOf_V2_t *v);
parser_error_t _readAsOriginId_V2(parser_context_t *c, pd_AsOriginId_V2_t *v);
parser_error_t _readBabeEquivocationProof_V2(parser_context_t *c, pd_BabeEquivocationProof_V2_t *v);
parser_error_t _readCallOf_V2(parser_context_t *c, pd_CallOf_V2_t *v);
parser_error_t _readChangesTrieConfiguration_V2(parser_context_t *c, pd_ChangesTrieConfiguration_V2_t *v);
parser_error_t _readCompactEraIndex_V2(parser_context_t *c, pd_CompactEraIndex_V2_t *v);
parser_error_t _readCompactMemberCount_V2(parser_context_t *c, pd_CompactMemberCount_V2_t *v);
parser_error_t _readCompactMoment_V2(parser_context_t *c, pd_CompactMoment_V2_t *v);
parser_error_t _readCompactPerBill_V2(parser_context_t *c, pd_CompactPerBill_V2_t *v);
parser_error_t _readCompactProposalIndex_V2(parser_context_t *c, pd_CompactProposalIndex_V2_t *v);
parser_error_t _readCompactRegistrarIndex_V2(parser_context_t *c, pd_CompactRegistrarIndex_V2_t *v);
parser_error_t _readCompactWeight_V2(parser_context_t *c, pd_CompactWeight_V2_t *v);
parser_error_t _readCurrencyIdOf_V2(parser_context_t *c, pd_CurrencyIdOf_V2_t *v);
parser_error_t _readCurrencyId_V2(parser_context_t *c, pd_CurrencyId_V2_t *v);
parser_error_t _readDispatchTime_V2(parser_context_t *c, pd_DispatchTime_V2_t *v);
parser_error_t _readEcdsaSignature_V2(parser_context_t *c, pd_EcdsaSignature_V2_t *v);
parser_error_t _readEraIndex_V2(parser_context_t *c, pd_EraIndex_V2_t *v);
parser_error_t _readEvmAddress_V2(parser_context_t *c, pd_EvmAddress_V2_t *v);
parser_error_t _readGrandpaEquivocationProof_V2(parser_context_t *c, pd_GrandpaEquivocationProof_V2_t *v);
parser_error_t _readIdentityFields_V2(parser_context_t *c, pd_IdentityFields_V2_t *v);
parser_error_t _readIdentityInfo_V2(parser_context_t *c, pd_IdentityInfo_V2_t *v);
parser_error_t _readIdentityJudgement_V2(parser_context_t *c, pd_IdentityJudgement_V2_t *v);
parser_error_t _readKeyOwnerProof_V2(parser_context_t *c, pd_KeyOwnerProof_V2_t *v);
parser_error_t _readKeyValue_V2(parser_context_t *c, pd_KeyValue_V2_t *v);
parser_error_t _readKey_V2(parser_context_t *c, pd_Key_V2_t *v);
parser_error_t _readKeys_V2(parser_context_t *c, pd_Keys_V2_t *v);
parser_error_t _readLockDuration_V2(parser_context_t *c, pd_LockDuration_V2_t *v);
parser_error_t _readLookupSource_V2(parser_context_t *c, pd_LookupSource_V2_t *v);
parser_error_t _readMemberCount_V2(parser_context_t *c, pd_MemberCount_V2_t *v);
parser_error_t _readNextConfigDescriptor_V2(parser_context_t *c, pd_NextConfigDescriptor_V2_t *v);
parser_error_t _readOpaqueCall_V2(parser_context_t *c, pd_OpaqueCall_V2_t *v);
parser_error_t _readOptionAccountId_V2(parser_context_t *c, pd_OptionAccountId_V2_t *v);
parser_error_t _readOptionChangesTrieConfiguration_V2(parser_context_t *c, pd_OptionChangesTrieConfiguration_V2_t *v);
parser_error_t _readOptionCurrencyId_V2(parser_context_t *c, pd_OptionCurrencyId_V2_t *v);
parser_error_t _readOptionPercent_V2(parser_context_t *c, pd_OptionPercent_V2_t *v);
parser_error_t _readOptionPeriod_V2(parser_context_t *c, pd_OptionPeriod_V2_t *v);
parser_error_t _readOptionTimepoint_V2(parser_context_t *c, pd_OptionTimepoint_V2_t *v);
parser_error_t _readPalletsOrigin_V2(parser_context_t *c, pd_PalletsOrigin_V2_t *v);
parser_error_t _readPerbill_V2(parser_context_t *c, pd_Perbill_V2_t *v);
parser_error_t _readPercent_V2(parser_context_t *c, pd_Percent_V2_t *v);
parser_error_t _readPeriod_V2(parser_context_t *c, pd_Period_V2_t *v);
parser_error_t _readPriority_V2(parser_context_t *c, pd_Priority_V2_t *v);
parser_error_t _readRegistrarIndex_V2(parser_context_t *c, pd_RegistrarIndex_V2_t *v);
parser_error_t _readRewardDestination_V2(parser_context_t *c, pd_RewardDestination_V2_t *v);
parser_error_t _readScheduleTaskIndex_V2(parser_context_t *c, pd_ScheduleTaskIndex_V2_t *v);
parser_error_t _readSignature_V2(parser_context_t *c, pd_Signature_V2_t *v);
parser_error_t _readStreamDependency_V2(parser_context_t *c, pd_StreamDependency_V2_t *v);
parser_error_t _readTimepoint_V2(parser_context_t *c, pd_Timepoint_V2_t *v);
parser_error_t _readTupleAccountIdData_V2(parser_context_t *c, pd_TupleAccountIdData_V2_t *v);
parser_error_t _readValidatorPrefs_V2(parser_context_t *c, pd_ValidatorPrefs_V2_t *v);
parser_error_t _readVecAccountId_V2(parser_context_t *c, pd_VecAccountId_V2_t *v);
parser_error_t _readVecKeyValue_V2(parser_context_t *c, pd_VecKeyValue_V2_t *v);
parser_error_t _readVecKey_V2(parser_context_t *c, pd_VecKey_V2_t *v);
parser_error_t _readVecLookupSource_V2(parser_context_t *c, pd_VecLookupSource_V2_t *v);
parser_error_t _readVecTupleAccountIdData_V2(parser_context_t *c, pd_VecTupleAccountIdData_V2_t *v);
parser_error_t _readWeight_V2(parser_context_t *c, pd_Weight_V2_t *v);

// toString functions
parser_error_t _toStringAccountId_V2(const pd_AccountId_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringAccountIndex_V2(const pd_AccountIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAmountOf_V2(const pd_AmountOf_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringAsOriginId_V2(const pd_AsOriginId_V2_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBabeEquivocationProof_V2(const pd_BabeEquivocationProof_V2_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCallOf_V2(const pd_CallOf_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringChangesTrieConfiguration_V2(const pd_ChangesTrieConfiguration_V2_t *v, char *outValue,
                                                    uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactEraIndex_V2(const pd_CompactEraIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactMemberCount_V2(const pd_CompactMemberCount_V2_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactMoment_V2(const pd_CompactMoment_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactPerBill_V2(const pd_CompactPerBill_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactProposalIndex_V2(const pd_CompactProposalIndex_V2_t *v, char *outValue,
                                                uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactRegistrarIndex_V2(const pd_CompactRegistrarIndex_V2_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactWeight_V2(const pd_CompactWeight_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCurrencyIdOf_V2(const pd_CurrencyIdOf_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCurrencyId_V2(const pd_CurrencyId_V2_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringDispatchTime_V2(const pd_DispatchTime_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringEcdsaSignature_V2(const pd_EcdsaSignature_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringEraIndex_V2(const pd_EraIndex_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringEvmAddress_V2(const pd_EvmAddress_V2_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V2(const pd_GrandpaEquivocationProof_V2_t *v, char *outValue,
                                                    uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringIdentityFields_V2(const pd_IdentityFields_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringIdentityInfo_V2(const pd_IdentityInfo_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringIdentityJudgement_V2(const pd_IdentityJudgement_V2_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyOwnerProof_V2(const pd_KeyOwnerProof_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyValue_V2(const pd_KeyValue_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringKey_V2(const pd_Key_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringKeys_V2(const pd_Keys_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringLockDuration_V2(const pd_LockDuration_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringLookupSource_V2(const pd_LookupSource_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMemberCount_V2(const pd_MemberCount_V2_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringNextConfigDescriptor_V2(const pd_NextConfigDescriptor_V2_t *v, char *outValue,
                                                uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOpaqueCall_V2(const pd_OpaqueCall_V2_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionAccountId_V2(const pd_OptionAccountId_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V2(const pd_OptionChangesTrieConfiguration_V2_t *v,
                                                          char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                                          uint8_t *pageCount);

parser_error_t _toStringOptionCurrencyId_V2(const pd_OptionCurrencyId_V2_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionPercent_V2(const pd_OptionPercent_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionPeriod_V2(const pd_OptionPeriod_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionTimepoint_V2(const pd_OptionTimepoint_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPalletsOrigin_V2(const pd_PalletsOrigin_V2_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPerbill_V2(const pd_Perbill_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringPercent_V2(const pd_Percent_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringPeriod_V2(const pd_Period_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringPriority_V2(const pd_Priority_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringRegistrarIndex_V2(const pd_RegistrarIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringRewardDestination_V2(const pd_RewardDestination_V2_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringScheduleTaskIndex_V2(const pd_ScheduleTaskIndex_V2_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSignature_V2(const pd_Signature_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringStreamDependency_V2(const pd_StreamDependency_V2_t *v, char *outValue, uint16_t outValueLen,
                                            uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTimepoint_V2(const pd_Timepoint_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringTupleAccountIdData_V2(const pd_TupleAccountIdData_V2_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs_V2(const pd_ValidatorPrefs_V2_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecAccountId_V2(const pd_VecAccountId_V2_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecKeyValue_V2(const pd_VecKeyValue_V2_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecKey_V2(const pd_VecKey_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecLookupSource_V2(const pd_VecLookupSource_V2_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecTupleAccountIdData_V2(const pd_VecTupleAccountIdData_V2_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringWeight_V2(const pd_Weight_V2_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
