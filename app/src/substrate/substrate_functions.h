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

// Common read functions

parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readu8(parser_context_t *c, pd_u8_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readCompactu64(parser_context_t *c, pd_Compactu64_t *v);
parser_error_t _readCallImpl(parser_context_t *c, pd_Call_t *v, pd_MethodNested_t *m);

parser_error_t _readData(parser_context_t *c, pd_Data_t *v);
parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readTupleDataData(parser_context_t *c, pd_TupleDataData_t *v);
parser_error_t _readu8_array_20(parser_context_t *c, pd_u8_array_20_t *v);
parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readChangesTrieConfiguration(parser_context_t *c, pd_ChangesTrieConfiguration_t *v);
parser_error_t _readCompactPerBill(parser_context_t *c, pd_CompactPerBill_t *v);
parser_error_t _readCurrencyId(parser_context_t *c, pd_CurrencyId_t *v);
parser_error_t _readHeader(parser_context_t *c, pd_Header_t *v);
parser_error_t _readKeyValue(parser_context_t *c, pd_KeyValue_t *v);
parser_error_t _readKey(parser_context_t *c, pd_Key_t *v);
parser_error_t _readLookupSource(parser_context_t *c, pd_LookupSource_t *v);
parser_error_t _readCompactAccountIndex(parser_context_t *c, pd_CompactAccountIndex_t *v);
parser_error_t _readOptionu8_array_20(parser_context_t *c, pd_Optionu8_array_20_t *v);
parser_error_t _readPercent(parser_context_t *c, pd_Percent_t *v);
parser_error_t _readPeriod(parser_context_t *c, pd_Period_t *v);
parser_error_t _readStreamDependency(parser_context_t *c, pd_StreamDependency_t *v);
parser_error_t _readTimepoint(parser_context_t *c, pd_Timepoint_t *v);
parser_error_t _readTupleAccountIdData(parser_context_t *c, pd_TupleAccountIdData_t *v);
parser_error_t _readVecTupleDataData(parser_context_t *c, pd_VecTupleDataData_t *v);
parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v);
parser_error_t _readIdentityInfo(parser_context_t *c, pd_IdentityInfo_t *v);
parser_error_t _readOpaqueCall(parser_context_t *c, pd_OpaqueCall_t *v);
parser_error_t _readOptionChangesTrieConfiguration(parser_context_t *c, pd_OptionChangesTrieConfiguration_t *v);
parser_error_t _readOptionTimepoint(parser_context_t *c, pd_OptionTimepoint_t *v);
parser_error_t _readPriority(parser_context_t *c, pd_Priority_t *v);
parser_error_t _readProposal(parser_context_t *c, pd_Proposal_t *v);
parser_error_t _readRewardDestination(parser_context_t *c, pd_RewardDestination_t *v);
parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v);
parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v);
parser_error_t _readVecTupleAccountIdData(parser_context_t *c, pd_VecTupleAccountIdData_t *v);
parser_error_t _readWeight(parser_context_t *c, pd_Weight_t *v);
parser_error_t _readAccountIndex(parser_context_t *c, pd_AccountIndex_t *v);
parser_error_t _readAmountOf(parser_context_t *c, pd_AmountOf_t *v);
parser_error_t _readAsOriginId(parser_context_t *c, pd_AsOriginId_t *v);
parser_error_t _readBabeEquivocationProof(parser_context_t *c, pd_BabeEquivocationProof_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readCallOf(parser_context_t *c, pd_CallOf_t *v);
parser_error_t _readCompactBalanceOf(parser_context_t *c, pd_CompactBalanceOf_t *v);
parser_error_t _readCompactEraIndex(parser_context_t *c, pd_CompactEraIndex_t *v);
parser_error_t _readCompactMemberCount(parser_context_t *c, pd_CompactMemberCount_t *v);
parser_error_t _readCompactMoment(parser_context_t *c, pd_CompactMoment_t *v);
parser_error_t _readCompactProposalIndex(parser_context_t *c, pd_CompactProposalIndex_t *v);
parser_error_t _readCompactRegistrarIndex(parser_context_t *c, pd_CompactRegistrarIndex_t *v);
parser_error_t _readCompactWeight(parser_context_t *c, pd_CompactWeight_t *v);
parser_error_t _readCurrencyIdOf(parser_context_t *c, pd_CurrencyIdOf_t *v);
parser_error_t _readDispatchTime(parser_context_t *c, pd_DispatchTime_t *v);
parser_error_t _readEcdsaSignature(parser_context_t *c, pd_EcdsaSignature_t *v);
parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v);
parser_error_t _readEvmAddress(parser_context_t *c, pd_EvmAddress_t *v);
parser_error_t _readGrandpaEquivocationProof(parser_context_t *c, pd_GrandpaEquivocationProof_t *v);
parser_error_t _readH256(parser_context_t *c, pd_H256_t *v);
parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);
parser_error_t _readHeartbeat(parser_context_t *c, pd_Heartbeat_t *v);
parser_error_t _readIdentityFields(parser_context_t *c, pd_IdentityFields_t *v);
parser_error_t _readIdentityJudgement(parser_context_t *c, pd_IdentityJudgement_t *v);
parser_error_t _readKeyOwnerProof(parser_context_t *c, pd_KeyOwnerProof_t *v);
parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v);
parser_error_t _readLockDuration(parser_context_t *c, pd_LockDuration_t *v);
parser_error_t _readMemberCount(parser_context_t *c, pd_MemberCount_t *v);
parser_error_t _readNextConfigDescriptor(parser_context_t *c, pd_NextConfigDescriptor_t *v);
parser_error_t _readOptionAccountId(parser_context_t *c, pd_OptionAccountId_t *v);
parser_error_t _readOptionCurrencyId(parser_context_t *c, pd_OptionCurrencyId_t *v);
parser_error_t _readOptionPercent(parser_context_t *c, pd_OptionPercent_t *v);
parser_error_t _readOptionPeriod(parser_context_t *c, pd_OptionPeriod_t *v);
parser_error_t _readOptionu32(parser_context_t *c, pd_Optionu32_t *v);
parser_error_t _readPalletsOrigin(parser_context_t *c, pd_PalletsOrigin_t *v);
parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v);
parser_error_t _readRegistrarIndex(parser_context_t *c, pd_RegistrarIndex_t *v);
parser_error_t _readScheduleTaskIndex(parser_context_t *c, pd_ScheduleTaskIndex_t *v);
parser_error_t _readSignature(parser_context_t *c, pd_Signature_t *v);
parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v);
parser_error_t _readVecHeader(parser_context_t *c, pd_VecHeader_t *v);
parser_error_t _readVecKeyValue(parser_context_t *c, pd_VecKeyValue_t *v);
parser_error_t _readVecKey(parser_context_t *c, pd_VecKey_t *v);
parser_error_t _readVecLookupSource(parser_context_t *c, pd_VecLookupSource_t *v);
parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v);

// Common toString functions

parser_error_t _toStringu8(const pd_u8_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringBlockNumber(const pd_BlockNumber_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringCompactu32(const pd_Compactu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringCompactu64(const pd_Compactu64_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringData(const pd_Data_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringAccountId(const pd_AccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringTupleDataData(const pd_TupleDataData_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringu8_array_20(const pd_u8_array_20_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringBalance(const pd_Balance_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringChangesTrieConfiguration(const pd_ChangesTrieConfiguration_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactPerBill(const pd_CompactPerBill_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCurrencyId(const pd_CurrencyId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringHeader(const pd_Header_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringKeyValue(const pd_KeyValue_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringKey(const pd_Key_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringLookupSource(const pd_LookupSource_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOptionu8_array_20(const pd_Optionu8_array_20_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPercent(const pd_Percent_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringPeriod(const pd_Period_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringStreamDependency(const pd_StreamDependency_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTimepoint(const pd_Timepoint_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringTupleAccountIdData(const pd_TupleAccountIdData_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecTupleDataData(const pd_VecTupleDataData_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBalanceOf(const pd_BalanceOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringIdentityInfo(const pd_IdentityInfo_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOpaqueCall(const pd_OpaqueCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration(const pd_OptionChangesTrieConfiguration_t *v, char *outValue,
                                                       uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionTimepoint(const pd_OptionTimepoint_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPriority(const pd_Priority_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringProposal(const pd_Proposal_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringRewardDestination(const pd_RewardDestination_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs(const pd_ValidatorPrefs_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecCall(const pd_VecCall_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringVecTupleAccountIdData(const pd_VecTupleAccountIdData_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringWeight(const pd_Weight_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringAccountIndex(const pd_AccountIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringAmountOf(const pd_AmountOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringAsOriginId(const pd_AsOriginId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringBabeEquivocationProof(const pd_BabeEquivocationProof_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBytes(const pd_Bytes_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringCallOf(const pd_CallOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringCompactBalanceOf(const pd_CompactBalanceOf_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactEraIndex(const pd_CompactEraIndex_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactMemberCount(const pd_CompactMemberCount_t *v, char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactMoment(const pd_CompactMoment_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactProposalIndex(const pd_CompactProposalIndex_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactRegistrarIndex(const pd_CompactRegistrarIndex_t *v, char *outValue, uint16_t outValueLen,
                                              uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactWeight(const pd_CompactWeight_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCurrencyIdOf(const pd_CurrencyIdOf_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringDispatchTime(const pd_DispatchTime_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringEcdsaSignature(const pd_EcdsaSignature_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringEraIndex(const pd_EraIndex_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringEvmAddress(const pd_EvmAddress_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringGrandpaEquivocationProof(const pd_GrandpaEquivocationProof_t *v, char *outValue,
                                                 uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringH256(const pd_H256_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringHeartbeat(const pd_Heartbeat_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringIdentityFields(const pd_IdentityFields_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringIdentityJudgement(const pd_IdentityJudgement_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyOwnerProof(const pd_KeyOwnerProof_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeys(const pd_Keys_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringLockDuration(const pd_LockDuration_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringMemberCount(const pd_MemberCount_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringNextConfigDescriptor(const pd_NextConfigDescriptor_t *v, char *outValue, uint16_t outValueLen,
                                             uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionAccountId(const pd_OptionAccountId_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionCurrencyId(const pd_OptionCurrencyId_t *v, char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionPercent(const pd_OptionPercent_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionPeriod(const pd_OptionPeriod_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOptionu32(const pd_Optionu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringPalletsOrigin(const pd_PalletsOrigin_t *v, char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPerbill(const pd_Perbill_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringRegistrarIndex(const pd_RegistrarIndex_t *v, char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringScheduleTaskIndex(const pd_ScheduleTaskIndex_t *v, char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSignature(const pd_Signature_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecAccountId(const pd_VecAccountId_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringVecHeader(const pd_VecHeader_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecKeyValue(const pd_VecKeyValue_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringVecKey(const pd_VecKey_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringVecLookupSource(const pd_VecLookupSource_t *v, char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecu32(const pd_Vecu32_t *v, char *outValue, uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
