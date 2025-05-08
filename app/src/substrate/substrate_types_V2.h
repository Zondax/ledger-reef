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

#include "substrate_types.h"

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    const uint8_t *_ptr;
} pd_AccountId_V2_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V2_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CurrencyId_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_KeyValue_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Key_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_LookupSource_V2_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V2_t;

typedef struct {
    uint64_t value;
} pd_Period_V2_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V2_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleAccountIdData_V2_t;

typedef struct {
    // https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs#L276
    pd_VecTupleDataData_t additional;
    pd_Data_t display;
    pd_Data_t legal;
    pd_Data_t web;
    pd_Data_t riot;
    pd_Data_t email;
    pd_Optionu8_array_20_t pgp_fingerprint;
    pd_Data_t image;
    pd_Data_t twitter;
} pd_IdentityInfo_V2_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_V2_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V2_t contained;
} pd_OptionChangesTrieConfiguration_V2_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_V2_t contained;
} pd_OptionTimepoint_V2_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V2_t dependency;
} pd_Priority_V2_t;

typedef struct {
    pd_CompactPerBill_V2_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V2_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AmountOf_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AsOriginId_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BabeEquivocationProof_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CallOf_V2_t;

typedef compactInt_t pd_CompactEraIndex_V2_t;

typedef compactInt_t pd_CompactMemberCount_V2_t;

typedef compactInt_t pd_CompactMoment_V2_t;

typedef compactInt_t pd_CompactProposalIndex_V2_t;

typedef compactInt_t pd_CompactRegistrarIndex_V2_t;

typedef compactInt_t pd_CompactWeight_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CurrencyIdOf_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DispatchTime_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_EcdsaSignature_V2_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EvmAddress_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityJudgement_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Keys_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LockDuration_V2_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_V2_t;

typedef struct {
    uint8_t some;
    pd_AccountId_V2_t contained;
} pd_OptionAccountId_V2_t;

typedef struct {
    uint8_t some;
    pd_CurrencyId_V2_t contained;
} pd_OptionCurrencyId_V2_t;

typedef struct {
    uint8_t some;
    pd_Percent_V2_t contained;
} pd_OptionPercent_V2_t;

typedef struct {
    uint8_t some;
    pd_Period_V2_t contained;
} pd_OptionPeriod_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PalletsOrigin_V2_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V2_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_V2_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V2_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScheduleTaskIndex_V2_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Signature_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_V2_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_V2_t;

typedef struct {
    uint64_t value;
} pd_Weight_V2_t;

#ifdef __cplusplus
}
#endif
