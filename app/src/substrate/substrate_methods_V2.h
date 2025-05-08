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
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#include "substrate_types.h"
#include "substrate_types_V2.h"
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V2 0
#define PD_CALL_TIMESTAMP_V2 2
#define PD_CALL_INDICES_V2 5
#define PD_CALL_BALANCES_V2 6
#define PD_CALL_UTILITY_V2 11
#define PD_CALL_STAKING_V2 33
#define PD_CALL_SESSION_V2 34
#define PD_CALL_IDENTITY_V2 40
#define PD_CALL_TECHCOUNCIL_V2 50

#define PD_CALL_UTILITY_BATCH_V2 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V2_t;

#define PD_CALL_UTILITY_BATCH_ALL_V2 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V2_t;

#define PD_CALL_SESSION_SET_KEYS_V2 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V2_t;

#define PD_CALL_SESSION_PURGE_KEYS_V2 1
typedef struct {
} pd_session_purge_keys_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_TIMESTAMP_SET_V2 0
typedef struct {
    pd_CompactMoment_t now;
} pd_timestamp_set_V2_t;

#define PD_CALL_INDICES_CLAIM_V2 0
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_claim_V2_t;

#define PD_CALL_INDICES_TRANSFER_V2 1
typedef struct {
    pd_AccountId_t new_;
    pd_AccountIndex_t index;
} pd_indices_transfer_V2_t;

#define PD_CALL_INDICES_FREE_V2 2
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_free_V2_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V2 3
typedef struct {
    pd_AccountId_t new_;
    pd_AccountIndex_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V2_t;

#define PD_CALL_INDICES_FREEZE_V2 4
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_freeze_V2_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V2 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V2_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V2 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V2_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V2 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V2_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V2 12
typedef struct {
} pd_staking_force_no_eras_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V2 13
typedef struct {
} pd_staking_force_new_era_V2_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V2 14
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V2_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V2 15
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V2_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V2 16
typedef struct {
} pd_staking_force_new_era_always_V2_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V2 17
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V2_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V2 20
typedef struct {
    pd_CompactEraIndex_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V2_t;

#define PD_CALL_STAKING_REAP_STASH_V2 21
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V2_t;

#define PD_CALL_STAKING_KICK_V2 22
typedef struct {
    pd_VecLookupSource_t who;
} pd_staking_kick_V2_t;

#define PD_CALL_STAKING_SET_STAKING_LIMITS_V2 23
typedef struct {
    pd_BalanceOf_t min_nominator_bond;
    pd_BalanceOf_t min_validator_bond;
    pd_Optionu32_t max_nominator_count;
    pd_Optionu32_t max_validator_count;
    pd_OptionPercent_t threshold;
} pd_staking_set_staking_limits_V2_t;

#define PD_CALL_STAKING_CHILL_OTHER_V2 24
typedef struct {
    pd_AccountId_t controller;
} pd_staking_chill_other_V2_t;

#define PD_CALL_IDENTITY_ADD_REGISTRAR_V2 0
typedef struct {
    pd_AccountId_t account;
} pd_identity_add_registrar_V2_t;

#define PD_CALL_IDENTITY_CLEAR_IDENTITY_V2 3
typedef struct {
} pd_identity_clear_identity_V2_t;

#define PD_CALL_IDENTITY_REQUEST_JUDGEMENT_V2 4
typedef struct {
    pd_CompactRegistrarIndex_t reg_index;
    pd_CompactBalanceOf_t max_fee;
} pd_identity_request_judgement_V2_t;

#define PD_CALL_IDENTITY_CANCEL_REQUEST_V2 5
typedef struct {
    pd_RegistrarIndex_t reg_index;
} pd_identity_cancel_request_V2_t;

#define PD_CALL_IDENTITY_SET_FEE_V2 6
typedef struct {
    pd_CompactRegistrarIndex_t index;
    pd_CompactBalanceOf_t fee;
} pd_identity_set_fee_V2_t;

#define PD_CALL_IDENTITY_SET_ACCOUNT_ID_V2 7
typedef struct {
    pd_CompactRegistrarIndex_t index;
    pd_AccountId_t new_;
} pd_identity_set_account_id_V2_t;

#define PD_CALL_IDENTITY_KILL_IDENTITY_V2 10
typedef struct {
    pd_LookupSource_t target;
} pd_identity_kill_identity_V2_t;

#define PD_CALL_IDENTITY_REMOVE_SUB_V2 13
typedef struct {
    pd_LookupSource_t sub;
} pd_identity_remove_sub_V2_t;

#define PD_CALL_IDENTITY_QUIT_SUB_V2 14
typedef struct {
} pd_identity_quit_sub_V2_t;

#define PD_CALL_TECHCOUNCIL_SET_MEMBERS_V2 0
typedef struct {
    pd_VecAccountId_t new_members;
    pd_OptionAccountId_t prime;
    pd_MemberCount_t old_count;
} pd_techcouncil_set_members_V2_t;

#define PD_CALL_TECHCOUNCIL_EXECUTE_V2 1
typedef struct {
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_techcouncil_execute_V2_t;

#define PD_CALL_TECHCOUNCIL_PROPOSE_V2 2
typedef struct {
    pd_CompactMemberCount_t threshold;
    pd_Proposal_t proposal;
    pd_Compactu32_t length_bound;
} pd_techcouncil_propose_V2_t;

#define PD_CALL_TECHCOUNCIL_VOTE_V2 3
typedef struct {
    pd_Hash_t proposal;
    pd_CompactProposalIndex_t index;
    pd_bool_t approve;
} pd_techcouncil_vote_V2_t;

#define PD_CALL_TECHCOUNCIL_CLOSE_V2 4
typedef struct {
    pd_Hash_t proposal_hash;
    pd_CompactProposalIndex_t index;
    pd_CompactWeight_t proposal_weight_bound;
    pd_Compactu32_t length_bound;
} pd_techcouncil_close_V2_t;

#define PD_CALL_TECHCOUNCIL_DISAPPROVE_PROPOSAL_V2 5
typedef struct {
    pd_Hash_t proposal_hash;
} pd_techcouncil_disapprove_proposal_V2_t;

#endif

typedef union {
    pd_utility_batch_V2_t utility_batch_V2;
    pd_utility_batch_all_V2_t utility_batch_all_V2;
    pd_session_set_keys_V2_t session_set_keys_V2;
    pd_session_purge_keys_V2_t session_purge_keys_V2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_timestamp_set_V2_t timestamp_set_V2;
    pd_indices_claim_V2_t indices_claim_V2;
    pd_indices_transfer_V2_t indices_transfer_V2;
    pd_indices_free_V2_t indices_free_V2;
    pd_indices_force_transfer_V2_t indices_force_transfer_V2;
    pd_indices_freeze_V2_t indices_freeze_V2;
    pd_staking_set_validator_count_V2_t staking_set_validator_count_V2;
    pd_staking_increase_validator_count_V2_t staking_increase_validator_count_V2;
    pd_staking_scale_validator_count_V2_t staking_scale_validator_count_V2;
    pd_staking_force_no_eras_V2_t staking_force_no_eras_V2;
    pd_staking_force_new_era_V2_t staking_force_new_era_V2;
    pd_staking_set_invulnerables_V2_t staking_set_invulnerables_V2;
    pd_staking_force_unstake_V2_t staking_force_unstake_V2;
    pd_staking_force_new_era_always_V2_t staking_force_new_era_always_V2;
    pd_staking_cancel_deferred_slash_V2_t staking_cancel_deferred_slash_V2;
    pd_staking_set_history_depth_V2_t staking_set_history_depth_V2;
    pd_staking_reap_stash_V2_t staking_reap_stash_V2;
    pd_staking_kick_V2_t staking_kick_V2;
    pd_staking_set_staking_limits_V2_t staking_set_staking_limits_V2;
    pd_staking_chill_other_V2_t staking_chill_other_V2;
    pd_identity_add_registrar_V2_t identity_add_registrar_V2;
    pd_identity_clear_identity_V2_t identity_clear_identity_V2;
    pd_identity_request_judgement_V2_t identity_request_judgement_V2;
    pd_identity_cancel_request_V2_t identity_cancel_request_V2;
    pd_identity_set_fee_V2_t identity_set_fee_V2;
    pd_identity_set_account_id_V2_t identity_set_account_id_V2;
    pd_identity_kill_identity_V2_t identity_kill_identity_V2;
    pd_identity_remove_sub_V2_t identity_remove_sub_V2;
    pd_identity_quit_sub_V2_t identity_quit_sub_V2;
    pd_techcouncil_set_members_V2_t techcouncil_set_members_V2;
    pd_techcouncil_execute_V2_t techcouncil_execute_V2;
    pd_techcouncil_propose_V2_t techcouncil_propose_V2;
    pd_techcouncil_vote_V2_t techcouncil_vote_V2;
    pd_techcouncil_close_V2_t techcouncil_close_V2;
    pd_techcouncil_disapprove_proposal_V2_t techcouncil_disapprove_proposal_V2;
#endif
} pd_MethodBasic_V2_t;

#define PD_CALL_BALANCES_TRANSFER_V2 0
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V2_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V2 2
typedef struct {
    pd_LookupSource_t source;
    pd_LookupSource_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V2_t;

#define PD_CALL_BALANCES_TRANSFER_KEEP_ALIVE_V2 3
typedef struct {
    pd_LookupSource_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_keep_alive_V2_t;

#define PD_CALL_BALANCES_TRANSFER_ALL_V2 4
typedef struct {
    pd_LookupSource_t dest;
    pd_bool_t keep_alive;
} pd_balances_transfer_all_V2_t;

#define PD_CALL_STAKING_BOND_V2 0
typedef struct {
    pd_LookupSource_t controller;
    pd_CompactBalanceOf_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V2_t;

#define PD_CALL_STAKING_BOND_EXTRA_V2 1
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_bond_extra_V2_t;

#define PD_CALL_STAKING_UNBOND_V2 2
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_unbond_V2_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V2 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V2_t;

#define PD_CALL_STAKING_VALIDATE_V2 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V2_t;

#define PD_CALL_STAKING_NOMINATE_V2 5
typedef struct {
    pd_VecLookupSource_t targets;
} pd_staking_nominate_V2_t;

#define PD_CALL_STAKING_CHILL_V2 6
typedef struct {
} pd_staking_chill_V2_t;

#define PD_CALL_STAKING_SET_PAYEE_V2 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V2_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V2 8
typedef struct {
    pd_LookupSource_t controller;
} pd_staking_set_controller_V2_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V2 18
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V2_t;

#define PD_CALL_STAKING_REBOND_V2 19
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_rebond_V2_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
#define PD_CALL_SYSTEM_FILL_BLOCK_V2 0
typedef struct {
    pd_Perbill_t _ratio;
} pd_system_fill_block_V2_t;

#define PD_CALL_SYSTEM_REMARK_V2 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V2_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V2 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_V2 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V2_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V2 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V2_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V2 9
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V2_t;

#define PD_CALL_BALANCES_SET_BALANCE_V2 1
typedef struct {
    pd_LookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V2_t;

#endif

typedef union {
    pd_balances_transfer_V2_t balances_transfer_V2;
    pd_balances_force_transfer_V2_t balances_force_transfer_V2;
    pd_balances_transfer_keep_alive_V2_t balances_transfer_keep_alive_V2;
    pd_balances_transfer_all_V2_t balances_transfer_all_V2;
    pd_staking_bond_V2_t staking_bond_V2;
    pd_staking_bond_extra_V2_t staking_bond_extra_V2;
    pd_staking_unbond_V2_t staking_unbond_V2;
    pd_staking_withdraw_unbonded_V2_t staking_withdraw_unbonded_V2;
    pd_staking_validate_V2_t staking_validate_V2;
    pd_staking_nominate_V2_t staking_nominate_V2;
    pd_staking_chill_V2_t staking_chill_V2;
    pd_staking_set_payee_V2_t staking_set_payee_V2;
    pd_staking_set_controller_V2_t staking_set_controller_V2;
    pd_staking_payout_stakers_V2_t staking_payout_stakers_V2;
    pd_staking_rebond_V2_t staking_rebond_V2;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_system_fill_block_V2_t system_fill_block_V2;
    pd_system_remark_V2_t system_remark_V2;
    pd_system_set_heap_pages_V2_t system_set_heap_pages_V2;
    pd_system_set_code_V2_t system_set_code_V2;
    pd_system_set_code_without_checks_V2_t system_set_code_without_checks_V2;
    pd_system_remark_with_event_V2_t system_remark_with_event_V2;
    pd_balances_set_balance_V2_t balances_set_balance_V2;
#endif
} pd_MethodNested_V2_t;

typedef union {
    pd_MethodBasic_V2_t basic;
    pd_MethodNested_V2_t nested;
} pd_Method_V2_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
