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

#include "stdbool.h"

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop
#endif

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint8_t pd_u8_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;
typedef uint32_t pd_BlockNumber_t;

#define CHECK_ERROR(FUNC_CALL)            \
    {                                     \
        parser_error_t err = FUNC_CALL;   \
        if (err != parser_ok) return err; \
    }

typedef struct {
    uint8_t moduleIdx;
    uint8_t idx;
} pd_CallIndex_t;

typedef enum { eEraImmortal = 0, eEraMortal = 1 } pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
    pd_ExtrinsicEra_e type;
    uint64_t period;
    uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
    const uint8_t *ptr;
    uint8_t len;
} compactInt_t;

typedef struct {
    uint32_t _lenBuffer;
    const uint8_t *_ptr;      // Pointer to actual
    const uint8_t *_nextPtr;  // Pointer to next Call
    uint8_t slotIdx;          // Count of nested calls
    bool isTail;
} pd_NestCallIdx_t;

////////////////////////
// Common types
////////////////////////

typedef compactInt_t pd_Compactu32_t;  // u32
typedef compactInt_t pd_Compactu64_t;  // u64
typedef compactInt_t pd_CompactAssignments_t;
typedef compactInt_t pd_CompactBountyIndex_t;
typedef compactInt_t pd_CompactEraIndex_t;
typedef compactInt_t pd_CompactMemberCount_t;
typedef compactInt_t pd_CompactMoment_t;
typedef compactInt_t pd_CompactPropIndex_t;
typedef compactInt_t pd_CompactProposalIndex_t;
typedef compactInt_t pd_CompactReferendumIndex_t;
typedef compactInt_t pd_CompactRegistrarIndex_t;
typedef compactInt_t pd_CompactWeight_t;

typedef enum { eAddressIndex = 0, eAddressId = 1 } pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t *idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    uint8_t value;
    const uint8_t *_ptr;
} pd_Data_t;

typedef struct {
    const uint8_t *_ptr;
} pd_AccountId_t;

typedef struct {
    pd_Data_t data1;
    pd_Data_t data2;
} pd_TupleDataData_t;

typedef struct {
    const uint8_t *_ptr;
} pd_u8_array_20_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Balance_t;

typedef struct {
    pd_CallIndex_t callIndex;
    const uint32_t *_txVerPtr;
    pd_NestCallIdx_t nestCallIdx;
} pd_Call_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    uint32_t value;
} pd_CurrencyId_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Header_t;

typedef struct {
    const uint8_t *_ptr;
} pd_KeyValue_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Key_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_t;

typedef struct {
    uint8_t some;
    pd_u8_array_20_t contained;
} pd_Optionu8_array_20_t;

typedef struct {
    uint8_t value;
} pd_Percent_t;

typedef struct {
    uint64_t value;
} pd_Period_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_t;

typedef struct {
    pd_BlockNumber_t height;
    uint32_t index;
} pd_Timepoint_t;

typedef struct {
    pd_AccountId_t id;
    pd_Data_t data;
} pd_TupleAccountIdData_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

typedef struct {
    pd_Balance_t value;
} pd_BalanceOf_t;

typedef struct {
    pd_VecTupleDataData_t additional;
    pd_Data_t display;
    pd_Data_t legal;
    pd_Data_t web;
    pd_Data_t riot;
    pd_Data_t email;
    pd_Optionu8_array_20_t pgp_fingerprint;
    pd_Data_t image;
    pd_Data_t twitter;
} pd_IdentityInfo_t;

typedef struct {
    pd_Call_t call;
} pd_OpaqueCall_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_t contained;
} pd_OptionChangesTrieConfiguration_t;

typedef struct {
    uint8_t some;
    pd_Timepoint_t contained;
} pd_OptionTimepoint_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_t dependency;
} pd_Priority_t;

typedef struct {
    pd_Call_t call;
} pd_Proposal_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t accountId;
} pd_RewardDestination_t;

typedef struct {
    pd_CompactPerBill_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
    uint32_t callTxVersion;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecTupleAccountIdData_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AmountOf_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_AsOriginId_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BabeEquivocationProof_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
} pd_Bytes_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t *_ptr;
    };
} pd_LookupSource_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CallOf_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalanceOf_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CurrencyIdOf_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DispatchTime_t;

typedef struct {
    const uint8_t *_ptr;
} pd_EcdsaSignature_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EvmAddress_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_t;

typedef struct {
    const uint8_t *_ptr;
} pd_H256_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Hash_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Heartbeat_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityFields_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_IdentityJudgement_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Keys_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LockDuration_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_NextConfigDescriptor_t;

typedef struct {
    uint8_t some;
    pd_AccountId_t contained;
} pd_OptionAccountId_t;

typedef struct {
    uint8_t some;
    pd_CurrencyId_t contained;
} pd_OptionCurrencyId_t;

typedef struct {
    uint8_t some;
    pd_Percent_t contained;
} pd_OptionPercent_t;

typedef struct {
    uint8_t some;
    pd_Period_t contained;
} pd_OptionPeriod_t;

typedef struct {
    uint8_t some;
    pd_u32_t contained;
} pd_Optionu32_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PalletsOrigin_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

typedef struct {
    uint32_t value;
} pd_RegistrarIndex_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScheduleTaskIndex_t;

typedef struct {
    const uint8_t *_ptr;
} pd_Signature_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecHeader_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecKey_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_t;

typedef struct {
    uint64_t _len;
    const uint8_t *_ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

#ifdef __cplusplus
}
#endif
