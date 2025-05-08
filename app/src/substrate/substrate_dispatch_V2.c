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

#include "substrate_dispatch_V2.h"

#include <stdint.h>

#include "substrate_strings.h"
#include "zxmacros.h"
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(parser_context_t *c, pd_balances_transfer_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(parser_context_t *c,
                                                                 pd_balances_force_transfer_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_keep_alive_V2(parser_context_t *c,
                                                                      pd_balances_transfer_keep_alive_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_all_V2(parser_context_t *c, pd_balances_transfer_all_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readbool(c, &m->keep_alive))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(parser_context_t *c, pd_utility_batch_V2_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V2(parser_context_t *c, pd_utility_batch_all_V2_t *m) {
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(parser_context_t *c, pd_staking_bond_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(parser_context_t *c, pd_staking_bond_extra_V2_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(parser_context_t *c, pd_staking_unbond_V2_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(parser_context_t *c,
                                                                   pd_staking_withdraw_unbonded_V2_t *m) {
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(parser_context_t *c, pd_staking_validate_V2_t *m) {
    CHECK_ERROR(_readValidatorPrefs_V2(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(parser_context_t *c, pd_staking_nominate_V2_t *m) {
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(__Z_UNUSED parser_context_t *c,
                                                       __Z_UNUSED pd_staking_chill_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(parser_context_t *c, pd_staking_set_payee_V2_t *m) {
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(parser_context_t *c,
                                                                pd_staking_set_controller_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(parser_context_t *c,
                                                                pd_staking_payout_stakers_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(parser_context_t *c, pd_staking_rebond_V2_t *m) {
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(parser_context_t *c, pd_session_set_keys_V2_t *m) {
    CHECK_ERROR(_readKeys_V2(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(__Z_UNUSED parser_context_t *c,
                                                            __Z_UNUSED pd_session_purge_keys_V2_t *m) {
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(parser_context_t *c, pd_system_fill_block_V2_t *m) {
    CHECK_ERROR(_readPerbill_V2(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(parser_context_t *c, pd_system_remark_V2_t *m) {
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(parser_context_t *c, pd_system_set_heap_pages_V2_t *m) {
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(parser_context_t *c, pd_system_set_code_V2_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(parser_context_t *c,
                                                                        pd_system_set_code_without_checks_V2_t *m) {
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V2(parser_context_t *c,
                                                                  pd_system_remark_with_event_V2_t *m) {
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(parser_context_t *c, pd_timestamp_set_V2_t *m) {
    CHECK_ERROR(_readCompactMoment_V2(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V2(parser_context_t *c, pd_indices_claim_V2_t *m) {
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V2(parser_context_t *c, pd_indices_transfer_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V2(parser_context_t *c, pd_indices_free_V2_t *m) {
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V2(parser_context_t *c,
                                                                pd_indices_force_transfer_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V2(parser_context_t *c, pd_indices_freeze_V2_t *m) {
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(parser_context_t *c, pd_balances_set_balance_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V2(parser_context_t *c, pd_grandpa_note_stalled_V2_t *m) {
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(parser_context_t *c,
                                                                     pd_staking_set_validator_count_V2_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(parser_context_t *c,
                                                                          pd_staking_increase_validator_count_V2_t *m) {
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(__Z_UNUSED parser_context_t *c,
                                                               __Z_UNUSED pd_staking_force_no_eras_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(__Z_UNUSED parser_context_t *c,
                                                               __Z_UNUSED pd_staking_force_new_era_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(parser_context_t *c,
                                                                   pd_staking_set_invulnerables_V2_t *m) {
    CHECK_ERROR(_readVecAccountId_V2(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(parser_context_t *c, pd_staking_force_unstake_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
    __Z_UNUSED parser_context_t *c, __Z_UNUSED pd_staking_force_new_era_always_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(parser_context_t *c,
                                                                       pd_staking_cancel_deferred_slash_V2_t *m) {
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    CHECK_ERROR(_readBytes(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(parser_context_t *c,
                                                                   pd_staking_set_history_depth_V2_t *m) {
    CHECK_ERROR(_readCompactEraIndex_V2(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(parser_context_t *c, pd_staking_reap_stash_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_kick_V2(parser_context_t *c, pd_staking_kick_V2_t *m) {
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_staking_limits_V2(parser_context_t *c,
                                                                    pd_staking_set_staking_limits_V2_t *m) {
    CHECK_ERROR(_readBalanceOf(c, &m->min_nominator_bond))
    CHECK_ERROR(_readBalanceOf(c, &m->min_validator_bond))
    CHECK_ERROR(_readOptionu32(c, &m->max_nominator_count))
    CHECK_ERROR(_readOptionu32(c, &m->max_validator_count))
    CHECK_ERROR(_readOptionPercent_V2(c, &m->threshold))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_other_V2(parser_context_t *c, pd_staking_chill_other_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_registrar_V2(parser_context_t *c,
                                                                pd_identity_add_registrar_V2_t *m) {
    CHECK_ERROR(_readAccountId_V2(c, &m->account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_clear_identity_V2(__Z_UNUSED parser_context_t *c,
                                                                 __Z_UNUSED pd_identity_clear_identity_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_request_judgement_V2(parser_context_t *c,
                                                                    pd_identity_request_judgement_V2_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->reg_index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cancel_request_V2(parser_context_t *c,
                                                                 pd_identity_cancel_request_V2_t *m) {
    CHECK_ERROR(_readRegistrarIndex_V2(c, &m->reg_index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_fee_V2(parser_context_t *c, pd_identity_set_fee_V2_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_account_id_V2(parser_context_t *c,
                                                                 pd_identity_set_account_id_V2_t *m) {
    CHECK_ERROR(_readCompactRegistrarIndex_V2(c, &m->index))
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_kill_identity_V2(parser_context_t *c,
                                                                pd_identity_kill_identity_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_sub_V2(parser_context_t *c, pd_identity_remove_sub_V2_t *m) {
    CHECK_ERROR(_readLookupSource_V2(c, &m->sub))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_quit_sub_V2(__Z_UNUSED parser_context_t *c,
                                                           __Z_UNUSED pd_identity_quit_sub_V2_t *m) {
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_set_members_V2(parser_context_t *c,
                                                                 pd_techcouncil_set_members_V2_t *m) {
    CHECK_ERROR(_readVecAccountId_V2(c, &m->new_members))
    CHECK_ERROR(_readOptionAccountId_V2(c, &m->prime))
    CHECK_ERROR(_readMemberCount_V2(c, &m->old_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_execute_V2(parser_context_t *c, pd_techcouncil_execute_V2_t *m) {
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_propose_V2(parser_context_t *c, pd_techcouncil_propose_V2_t *m) {
    CHECK_ERROR(_readCompactMemberCount_V2(c, &m->threshold))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_vote_V2(parser_context_t *c, pd_techcouncil_vote_V2_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_close_V2(parser_context_t *c, pd_techcouncil_close_V2_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    CHECK_ERROR(_readCompactProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readCompactWeight_V2(c, &m->proposal_weight_bound))
    CHECK_ERROR(_readCompactu32(c, &m->length_bound))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_techcouncil_disapprove_proposal_V2(parser_context_t *c,
                                                                         pd_techcouncil_disapprove_proposal_V2_t *m) {
    CHECK_ERROR(_readHash(c, &m->proposal_hash))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(parser_context_t *c, uint8_t moduleIdx, uint8_t callIdx, pd_Method_V2_t *method) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
            break;
        case 1538: /* module 6 call 2 */
            CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
            break;
        case 1539: /* module 6 call 3 */
            CHECK_ERROR(_readMethod_balances_transfer_keep_alive_V2(c, &method->nested.balances_transfer_keep_alive_V2))
            break;
        case 1540: /* module 6 call 4 */
            CHECK_ERROR(_readMethod_balances_transfer_all_V2(c, &method->basic.balances_transfer_all_V2))
            break;
        case 2816: /* module 11 call 0 */
            CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->basic.utility_batch_V2))
            break;
        case 2818: /* module 11 call 2 */
            CHECK_ERROR(_readMethod_utility_batch_all_V2(c, &method->basic.utility_batch_all_V2))
            break;
        case 8448: /* module 33 call 0 */
            CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->basic.staking_bond_V2))
            break;
        case 8449: /* module 33 call 1 */
            CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->basic.staking_bond_extra_V2))
            break;
        case 8450: /* module 33 call 2 */
            CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->basic.staking_unbond_V2))
            break;
        case 8451: /* module 33 call 3 */
            CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->basic.staking_withdraw_unbonded_V2))
            break;
        case 8452: /* module 33 call 4 */
            CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->basic.staking_validate_V2))
            break;
        case 8453: /* module 33 call 5 */
            CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->basic.staking_nominate_V2))
            break;
        case 8454: /* module 33 call 6 */
            CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->basic.staking_chill_V2))
            break;
        case 8455: /* module 33 call 7 */
            CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->basic.staking_set_payee_V2))
            break;
        case 8456: /* module 33 call 8 */
            CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->basic.staking_set_controller_V2))
            break;
        case 8466: /* module 33 call 18 */
            CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->basic.staking_payout_stakers_V2))
            break;
        case 8467: /* module 33 call 19 */
            CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->basic.staking_rebond_V2))
            break;
        case 8704: /* module 34 call 0 */
            CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->basic.session_set_keys_V2))
            break;
        case 8705: /* module 34 call 1 */
            CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->basic.session_purge_keys_V2))
            break;

#ifdef SUBSTRATE_PARSER_FULL
        case 0: /* module 0 call 0 */
            CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
            break;
        case 1: /* module 0 call 1 */
            CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
            break;
        case 2: /* module 0 call 2 */
            CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
            break;
        case 3: /* module 0 call 3 */
            CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
            break;
        case 4: /* module 0 call 4 */
            CHECK_ERROR(
                _readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
            break;
        case 9: /* module 0 call 9 */
            CHECK_ERROR(_readMethod_system_remark_with_event_V2(c, &method->nested.system_remark_with_event_V2))
            break;
        case 512: /* module 2 call 0 */
            CHECK_ERROR(_readMethod_timestamp_set_V2(c, &method->basic.timestamp_set_V2))
            break;
        case 1280: /* module 5 call 0 */
            CHECK_ERROR(_readMethod_indices_claim_V2(c, &method->basic.indices_claim_V2))
            break;
        case 1281: /* module 5 call 1 */
            CHECK_ERROR(_readMethod_indices_transfer_V2(c, &method->basic.indices_transfer_V2))
            break;
        case 1282: /* module 5 call 2 */
            CHECK_ERROR(_readMethod_indices_free_V2(c, &method->basic.indices_free_V2))
            break;
        case 1283: /* module 5 call 3 */
            CHECK_ERROR(_readMethod_indices_force_transfer_V2(c, &method->basic.indices_force_transfer_V2))
            break;
        case 1284: /* module 5 call 4 */
            CHECK_ERROR(_readMethod_indices_freeze_V2(c, &method->basic.indices_freeze_V2))
            break;
        case 1537: /* module 6 call 1 */
            CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
            break;
        case 8194: /* module 32 call 2 */
            CHECK_ERROR(_readMethod_grandpa_note_stalled_V2(c, &method->basic.grandpa_note_stalled_V2))
            break;
        case 8457: /* module 33 call 9 */
            CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->basic.staking_set_validator_count_V2))
            break;
        case 8458: /* module 33 call 10 */
            CHECK_ERROR(
                _readMethod_staking_increase_validator_count_V2(c, &method->basic.staking_increase_validator_count_V2))
            break;
        case 8460: /* module 33 call 12 */
            CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->basic.staking_force_no_eras_V2))
            break;
        case 8461: /* module 33 call 13 */
            CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->basic.staking_force_new_era_V2))
            break;
        case 8462: /* module 33 call 14 */
            CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->basic.staking_set_invulnerables_V2))
            break;
        case 8463: /* module 33 call 15 */
            CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->basic.staking_force_unstake_V2))
            break;
        case 8464: /* module 33 call 16 */
            CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->basic.staking_force_new_era_always_V2))
            break;
        case 8465: /* module 33 call 17 */
            CHECK_ERROR(
                _readMethod_staking_cancel_deferred_slash_V2(c, &method->basic.staking_cancel_deferred_slash_V2))
            break;
        case 8468: /* module 33 call 20 */
            CHECK_ERROR(_readMethod_staking_set_history_depth_V2(c, &method->basic.staking_set_history_depth_V2))
            break;
        case 8469: /* module 33 call 21 */
            CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->basic.staking_reap_stash_V2))
            break;
        case 8470: /* module 33 call 22 */
            CHECK_ERROR(_readMethod_staking_kick_V2(c, &method->basic.staking_kick_V2))
            break;
        case 8471: /* module 33 call 23 */
            CHECK_ERROR(_readMethod_staking_set_staking_limits_V2(c, &method->basic.staking_set_staking_limits_V2))
            break;
        case 8472: /* module 33 call 24 */
            CHECK_ERROR(_readMethod_staking_chill_other_V2(c, &method->basic.staking_chill_other_V2))
            break;
        case 10240: /* module 40 call 0 */
            CHECK_ERROR(_readMethod_identity_add_registrar_V2(c, &method->basic.identity_add_registrar_V2))
            break;
        case 10243: /* module 40 call 3 */
            CHECK_ERROR(_readMethod_identity_clear_identity_V2(c, &method->basic.identity_clear_identity_V2))
            break;
        case 10244: /* module 40 call 4 */
            CHECK_ERROR(_readMethod_identity_request_judgement_V2(c, &method->basic.identity_request_judgement_V2))
            break;
        case 10245: /* module 40 call 5 */
            CHECK_ERROR(_readMethod_identity_cancel_request_V2(c, &method->basic.identity_cancel_request_V2))
            break;
        case 10246: /* module 40 call 6 */
            CHECK_ERROR(_readMethod_identity_set_fee_V2(c, &method->basic.identity_set_fee_V2))
            break;
        case 10247: /* module 40 call 7 */
            CHECK_ERROR(_readMethod_identity_set_account_id_V2(c, &method->basic.identity_set_account_id_V2))
            break;
        case 10250: /* module 40 call 10 */
            CHECK_ERROR(_readMethod_identity_kill_identity_V2(c, &method->basic.identity_kill_identity_V2))
            break;
        case 10253: /* module 40 call 13 */
            CHECK_ERROR(_readMethod_identity_remove_sub_V2(c, &method->basic.identity_remove_sub_V2))
            break;
        case 10254: /* module 40 call 14 */
            CHECK_ERROR(_readMethod_identity_quit_sub_V2(c, &method->basic.identity_quit_sub_V2))
            break;
        case 12800: /* module 50 call 0 */
            CHECK_ERROR(_readMethod_techcouncil_set_members_V2(c, &method->basic.techcouncil_set_members_V2))
            break;
        case 12801: /* module 50 call 1 */
            CHECK_ERROR(_readMethod_techcouncil_execute_V2(c, &method->basic.techcouncil_execute_V2))
            break;
        case 12802: /* module 50 call 2 */
            CHECK_ERROR(_readMethod_techcouncil_propose_V2(c, &method->basic.techcouncil_propose_V2))
            break;
        case 12803: /* module 50 call 3 */
            CHECK_ERROR(_readMethod_techcouncil_vote_V2(c, &method->basic.techcouncil_vote_V2))
            break;
        case 12804: /* module 50 call 4 */
            CHECK_ERROR(_readMethod_techcouncil_close_V2(c, &method->basic.techcouncil_close_V2))
            break;
        case 12805: /* module 50 call 5 */
            CHECK_ERROR(
                _readMethod_techcouncil_disapprove_proposal_V2(c, &method->basic.techcouncil_disapprove_proposal_V2))
            break;
#endif
        default:
            return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char *_getMethod_ModuleName_V2(uint8_t moduleIdx) {
    switch (moduleIdx) {
        case 6:
            return STR_MO_BALANCES;
        case 11:
            return STR_MO_UTILITY;
        case 33:
            return STR_MO_STAKING;
        case 34:
            return STR_MO_SESSION;
#ifdef SUBSTRATE_PARSER_FULL
        case 0:
            return STR_MO_SYSTEM;
        case 2:
            return STR_MO_TIMESTAMP;
        case 5:
            return STR_MO_INDICES;
        case 32:
            return STR_MO_GRANDPA;
        case 40:
            return STR_MO_IDENTITY;
        case 50:
            return STR_MO_TECHCOUNCIL;
#endif
        default:
            return NULL;
    }

    return NULL;
}

const char *_getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            return STR_ME_TRANSFER;
        case 1538: /* module 6 call 2 */
            return STR_ME_FORCE_TRANSFER;
        case 1539: /* module 6 call 3 */
            return STR_ME_TRANSFER_KEEP_ALIVE;
        case 1540: /* module 6 call 4 */
            return STR_ME_TRANSFER_ALL;
        case 2816: /* module 11 call 0 */
            return STR_ME_BATCH;
        case 2818: /* module 11 call 2 */
            return STR_ME_BATCH_ALL;
        case 8448: /* module 33 call 0 */
            return STR_ME_BOND;
        case 8449: /* module 33 call 1 */
            return STR_ME_BOND_EXTRA;
        case 8450: /* module 33 call 2 */
            return STR_ME_UNBOND;
        case 8451: /* module 33 call 3 */
            return STR_ME_WITHDRAW_UNBONDED;
        case 8452: /* module 33 call 4 */
            return STR_ME_VALIDATE;
        case 8453: /* module 33 call 5 */
            return STR_ME_NOMINATE;
        case 8454: /* module 33 call 6 */
            return STR_ME_CHILL;
        case 8455: /* module 33 call 7 */
            return STR_ME_SET_PAYEE;
        case 8456: /* module 33 call 8 */
            return STR_ME_SET_CONTROLLER;
        case 8466: /* module 33 call 18 */
            return STR_ME_PAYOUT_STAKERS;
        case 8467: /* module 33 call 19 */
            return STR_ME_REBOND;
        case 8704: /* module 34 call 0 */
            return STR_ME_SET_KEYS;
        case 8705: /* module 34 call 1 */
            return STR_ME_PURGE_KEYS;
#ifdef SUBSTRATE_PARSER_FULL
        case 0: /* module 0 call 0 */
            return STR_ME_FILL_BLOCK;
        case 1: /* module 0 call 1 */
            return STR_ME_REMARK;
        case 2: /* module 0 call 2 */
            return STR_ME_SET_HEAP_PAGES;
        case 3: /* module 0 call 3 */
            return STR_ME_SET_CODE;
        case 4: /* module 0 call 4 */
            return STR_ME_SET_CODE_WITHOUT_CHECKS;
        case 5: /* module 0 call 5 */
            return STR_ME_SET_CHANGES_TRIE_CONFIG;
        case 6: /* module 0 call 6 */
            return STR_ME_SET_STORAGE;
        case 7: /* module 0 call 7 */
            return STR_ME_KILL_STORAGE;
        case 8: /* module 0 call 8 */
            return STR_ME_KILL_PREFIX;
        case 9: /* module 0 call 9 */
            return STR_ME_REMARK_WITH_EVENT;
        case 512: /* module 2 call 0 */
            return STR_ME_SET;
        case 768: /* module 3 call 0 */
            return STR_ME_SUDO;
        case 769: /* module 3 call 1 */
            return STR_ME_SUDO_UNCHECKED_WEIGHT;
        case 770: /* module 3 call 2 */
            return STR_ME_SET_KEY;
        case 771: /* module 3 call 3 */
            return STR_ME_SUDO_AS;
        case 1024: /* module 4 call 0 */
            return STR_ME_SCHEDULE;
        case 1025: /* module 4 call 1 */
            return STR_ME_CANCEL;
        case 1026: /* module 4 call 2 */
            return STR_ME_SCHEDULE_NAMED;
        case 1027: /* module 4 call 3 */
            return STR_ME_CANCEL_NAMED;
        case 1028: /* module 4 call 4 */
            return STR_ME_SCHEDULE_AFTER;
        case 1029: /* module 4 call 5 */
            return STR_ME_SCHEDULE_NAMED_AFTER;
        case 1280: /* module 5 call 0 */
            return STR_ME_CLAIM;
        case 1281: /* module 5 call 1 */
            return STR_ME_TRANSFER;
        case 1282: /* module 5 call 2 */
            return STR_ME_FREE;
        case 1283: /* module 5 call 3 */
            return STR_ME_FORCE_TRANSFER;
        case 1284: /* module 5 call 4 */
            return STR_ME_FREEZE;
        case 1537: /* module 6 call 1 */
            return STR_ME_SET_BALANCE;
        case 1792: /* module 7 call 0 */
            return STR_ME_TRANSFER;
        case 1793: /* module 7 call 1 */
            return STR_ME_TRANSFER_NATIVE_CURRENCY;
        case 1794: /* module 7 call 2 */
            return STR_ME_UPDATE_BALANCE;
        case 2304: /* module 9 call 0 */
            return STR_ME_SET_DEFAULT_FEE_TOKEN;
        case 2560: /* module 10 call 0 */
            return STR_ME_DISPATCH_AS;
        case 2561: /* module 10 call 1 */
            return STR_ME_SCHEDULE_DISPATCH;
        case 2562: /* module 10 call 2 */
            return STR_ME_FAST_TRACK_SCHEDULED_DISPATCH;
        case 2563: /* module 10 call 3 */
            return STR_ME_DELAY_SCHEDULED_DISPATCH;
        case 2564: /* module 10 call 4 */
            return STR_ME_CANCEL_SCHEDULED_DISPATCH;
        case 2565: /* module 10 call 5 */
            return STR_ME_AUTHORIZE_CALL;
        case 2566: /* module 10 call 6 */
            return STR_ME_REMOVE_AUTHORIZED_CALL;
        case 2567: /* module 10 call 7 */
            return STR_ME_TRIGGER_CALL;
        case 2817: /* module 11 call 1 */
            return STR_ME_AS_DERIVATIVE;
        case 3072: /* module 12 call 0 */
            return STR_ME_AS_MULTI_THRESHOLD_1;
        case 3073: /* module 12 call 1 */
            return STR_ME_AS_MULTI;
        case 3074: /* module 12 call 2 */
            return STR_ME_APPROVE_AS_MULTI;
        case 3075: /* module 12 call 3 */
            return STR_ME_CANCEL_AS_MULTI;
        case 5120: /* module 20 call 0 */
            return STR_ME_CLAIM_ACCOUNT;
        case 5121: /* module 20 call 1 */
            return STR_ME_CLAIM_DEFAULT_ACCOUNT;
        case 5376: /* module 21 call 0 */
            return STR_ME_CALL;
        case 5377: /* module 21 call 1 */
            return STR_ME_SCHEDULED_CALL;
        case 5378: /* module 21 call 2 */
            return STR_ME_CREATE;
        case 5379: /* module 21 call 3 */
            return STR_ME_CREATE2;
        case 5380: /* module 21 call 4 */
            return STR_ME_CREATE_NETWORK_CONTRACT;
        case 5381: /* module 21 call 5 */
            return STR_ME_TRANSFER_MAINTAINER;
        case 5382: /* module 21 call 6 */
            return STR_ME_DEPLOY;
        case 5383: /* module 21 call 7 */
            return STR_ME_DEPLOY_FREE;
        case 5384: /* module 21 call 8 */
            return STR_ME_ENABLE_CONTRACT_DEVELOPMENT;
        case 5385: /* module 21 call 9 */
            return STR_ME_DISABLE_CONTRACT_DEVELOPMENT;
        case 5386: /* module 21 call 10 */
            return STR_ME_SET_CODE;
        case 5387: /* module 21 call 11 */
            return STR_ME_SELFDESTRUCT;
        case 7680: /* module 30 call 0 */
            return STR_ME_SET_UNCLES;
        case 7936: /* module 31 call 0 */
            return STR_ME_REPORT_EQUIVOCATION;
        case 7937: /* module 31 call 1 */
            return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
        case 7938: /* module 31 call 2 */
            return STR_ME_PLAN_CONFIG_CHANGE;
        case 8192: /* module 32 call 0 */
            return STR_ME_REPORT_EQUIVOCATION;
        case 8193: /* module 32 call 1 */
            return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
        case 8194: /* module 32 call 2 */
            return STR_ME_NOTE_STALLED;
        case 8457: /* module 33 call 9 */
            return STR_ME_SET_VALIDATOR_COUNT;
        case 8458: /* module 33 call 10 */
            return STR_ME_INCREASE_VALIDATOR_COUNT;
        case 8459: /* module 33 call 11 */
            return STR_ME_SCALE_VALIDATOR_COUNT;
        case 8460: /* module 33 call 12 */
            return STR_ME_FORCE_NO_ERAS;
        case 8461: /* module 33 call 13 */
            return STR_ME_FORCE_NEW_ERA;
        case 8462: /* module 33 call 14 */
            return STR_ME_SET_INVULNERABLES;
        case 8463: /* module 33 call 15 */
            return STR_ME_FORCE_UNSTAKE;
        case 8464: /* module 33 call 16 */
            return STR_ME_FORCE_NEW_ERA_ALWAYS;
        case 8465: /* module 33 call 17 */
            return STR_ME_CANCEL_DEFERRED_SLASH;
        case 8468: /* module 33 call 20 */
            return STR_ME_SET_HISTORY_DEPTH;
        case 8469: /* module 33 call 21 */
            return STR_ME_REAP_STASH;
        case 8470: /* module 33 call 22 */
            return STR_ME_KICK;
        case 8471: /* module 33 call 23 */
            return STR_ME_SET_STAKING_LIMITS;
        case 8472: /* module 33 call 24 */
            return STR_ME_CHILL_OTHER;
        case 9472: /* module 37 call 0 */
            return STR_ME_HEARTBEAT;
        case 10240: /* module 40 call 0 */
            return STR_ME_ADD_REGISTRAR;
        case 10241: /* module 40 call 1 */
            return STR_ME_SET_IDENTITY;
        case 10242: /* module 40 call 2 */
            return STR_ME_SET_SUBS;
        case 10243: /* module 40 call 3 */
            return STR_ME_CLEAR_IDENTITY;
        case 10244: /* module 40 call 4 */
            return STR_ME_REQUEST_JUDGEMENT;
        case 10245: /* module 40 call 5 */
            return STR_ME_CANCEL_REQUEST;
        case 10246: /* module 40 call 6 */
            return STR_ME_SET_FEE;
        case 10247: /* module 40 call 7 */
            return STR_ME_SET_ACCOUNT_ID;
        case 10248: /* module 40 call 8 */
            return STR_ME_SET_FIELDS;
        case 10249: /* module 40 call 9 */
            return STR_ME_PROVIDE_JUDGEMENT;
        case 10250: /* module 40 call 10 */
            return STR_ME_KILL_IDENTITY;
        case 10251: /* module 40 call 11 */
            return STR_ME_ADD_SUB;
        case 10252: /* module 40 call 12 */
            return STR_ME_RENAME_SUB;
        case 10253: /* module 40 call 13 */
            return STR_ME_REMOVE_SUB;
        case 10254: /* module 40 call 14 */
            return STR_ME_QUIT_SUB;
        case 12800: /* module 50 call 0 */
            return STR_ME_SET_MEMBERS;
        case 12801: /* module 50 call 1 */
            return STR_ME_EXECUTE;
        case 12802: /* module 50 call 2 */
            return STR_ME_PROPOSE;
        case 12803: /* module 50 call 3 */
            return STR_ME_VOTE;
        case 12804: /* module 50 call 4 */
            return STR_ME_CLOSE;
        case 12805: /* module 50 call 5 */
            return STR_ME_DISAPPROVE_PROPOSAL;
        case 13056: /* module 51 call 0 */
            return STR_ME_START_CANDIDACY;
        case 13057: /* module 51 call 1 */
            return STR_ME_STOP_CANDIDACY;
        case 13058: /* module 51 call 2 */
            return STR_ME_COMMIT;
        case 13059: /* module 51 call 3 */
            return STR_ME_ADD_FUNDS;
        case 13060: /* module 51 call 4 */
            return STR_ME_UNBOND;
        case 13061: /* module 51 call 5 */
            return STR_ME_WITHDRAW;
        case 13062: /* module 51 call 6 */
            return STR_ME_VOTE_CANDIDATE;
#endif
        default:
            return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            return 2;
        case 1538: /* module 6 call 2 */
            return 3;
        case 1539: /* module 6 call 3 */
            return 2;
        case 1540: /* module 6 call 4 */
            return 2;
        case 2816: /* module 11 call 0 */
            return 1;
        case 2818: /* module 11 call 2 */
            return 1;
        case 8448: /* module 33 call 0 */
            return 3;
        case 8449: /* module 33 call 1 */
            return 1;
        case 8450: /* module 33 call 2 */
            return 1;
        case 8451: /* module 33 call 3 */
            return 1;
        case 8452: /* module 33 call 4 */
            return 1;
        case 8453: /* module 33 call 5 */
            return 1;
        case 8454: /* module 33 call 6 */
            return 0;
        case 8455: /* module 33 call 7 */
            return 1;
        case 8456: /* module 33 call 8 */
            return 1;
        case 8466: /* module 33 call 18 */
            return 2;
        case 8467: /* module 33 call 19 */
            return 1;
        case 8704: /* module 34 call 0 */
            return 2;
        case 8705: /* module 34 call 1 */
            return 0;
#ifdef SUBSTRATE_PARSER_FULL
        case 0: /* module 0 call 0 */
            return 1;
        case 1: /* module 0 call 1 */
            return 1;
        case 2: /* module 0 call 2 */
            return 1;
        case 3: /* module 0 call 3 */
            return 1;
        case 4: /* module 0 call 4 */
            return 1;
        case 9: /* module 0 call 9 */
            return 1;
        case 512: /* module 2 call 0 */
            return 1;
        case 1280: /* module 5 call 0 */
            return 1;
        case 1281: /* module 5 call 1 */
            return 2;
        case 1282: /* module 5 call 2 */
            return 1;
        case 1283: /* module 5 call 3 */
            return 3;
        case 1284: /* module 5 call 4 */
            return 1;
        case 1537: /* module 6 call 1 */
            return 3;
        case 8194: /* module 32 call 2 */
            return 2;
        case 8457: /* module 33 call 9 */
            return 1;
        case 8458: /* module 33 call 10 */
            return 1;
        case 8460: /* module 33 call 12 */
            return 0;
        case 8461: /* module 33 call 13 */
            return 0;
        case 8462: /* module 33 call 14 */
            return 1;
        case 8463: /* module 33 call 15 */
            return 2;
        case 8464: /* module 33 call 16 */
            return 0;
        case 8465: /* module 33 call 17 */
            return 2;
        case 8468: /* module 33 call 20 */
            return 2;
        case 8469: /* module 33 call 21 */
            return 2;
        case 8470: /* module 33 call 22 */
            return 1;
        case 8471: /* module 33 call 23 */
            return 5;
        case 8472: /* module 33 call 24 */
            return 1;
        case 10240: /* module 40 call 0 */
            return 1;
        case 10243: /* module 40 call 3 */
            return 0;
        case 10244: /* module 40 call 4 */
            return 2;
        case 10245: /* module 40 call 5 */
            return 1;
        case 10246: /* module 40 call 6 */
            return 2;
        case 10247: /* module 40 call 7 */
            return 2;
        case 10250: /* module 40 call 10 */
            return 1;
        case 10253: /* module 40 call 13 */
            return 1;
        case 10254: /* module 40 call 14 */
            return 0;
        case 12800: /* module 50 call 0 */
            return 3;
        case 12801: /* module 50 call 1 */
            return 2;
        case 12802: /* module 50 call 2 */
            return 3;
        case 12803: /* module 50 call 3 */
            return 3;
        case 12804: /* module 50 call 4 */
            return 4;
        case 12805: /* module 50 call 5 */
            return 1;
#endif
        default:
            return 0;
    }

    return 0;
}

const char *_getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_source;
                case 1:
                    return STR_IT_dest;
                case 2:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_dest;
                case 1:
                    return STR_IT_keep_alive;
                default:
                    return NULL;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 2818: /* module 11 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_calls;
                default:
                    return NULL;
            }
        case 8448: /* module 33 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                case 1:
                    return STR_IT_amount;
                case 2:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 8449: /* module 33 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 8450: /* module 33 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 8451: /* module 33 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 8452: /* module 33 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_prefs;
                default:
                    return NULL;
            }
        case 8453: /* module 33 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_targets;
                default:
                    return NULL;
            }
        case 8454: /* module 33 call 6 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 8455: /* module 33 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_payee;
                default:
                    return NULL;
            }
        case 8456: /* module 33 call 8 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                default:
                    return NULL;
            }
        case 8466: /* module 33 call 18 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_validator_stash;
                case 1:
                    return STR_IT_era;
                default:
                    return NULL;
            }
        case 8467: /* module 33 call 19 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_amount;
                default:
                    return NULL;
            }
        case 8704: /* module 34 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_keys;
                case 1:
                    return STR_IT_proof;
                default:
                    return NULL;
            }
        case 8705: /* module 34 call 1 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
#ifdef SUBSTRATE_PARSER_FULL
        case 0: /* module 0 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT__ratio;
                default:
                    return NULL;
            }
        case 1: /* module 0 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT__remark;
                default:
                    return NULL;
            }
        case 2: /* module 0 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_pages;
                default:
                    return NULL;
            }
        case 3: /* module 0 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 4: /* module 0 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_code;
                default:
                    return NULL;
            }
        case 9: /* module 0 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_remark;
                default:
                    return NULL;
            }
        case 512: /* module 2 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_now;
                default:
                    return NULL;
            }
        case 1280: /* module 5 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_index;
                default:
                    return NULL;
            }
        case 1281: /* module 5 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                case 1:
                    return STR_IT_index;
                default:
                    return NULL;
            }
        case 1282: /* module 5 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_index;
                default:
                    return NULL;
            }
        case 1283: /* module 5 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                case 1:
                    return STR_IT_index;
                case 2:
                    return STR_IT_freeze;
                default:
                    return NULL;
            }
        case 1284: /* module 5 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_index;
                default:
                    return NULL;
            }
        case 1537: /* module 6 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                case 1:
                    return STR_IT_new_free;
                case 2:
                    return STR_IT_new_reserved;
                default:
                    return NULL;
            }
        case 8194: /* module 32 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_delay;
                case 1:
                    return STR_IT_best_finalized_block_number;
                default:
                    return NULL;
            }
        case 8457: /* module 33 call 9 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 8458: /* module 33 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_additional;
                default:
                    return NULL;
            }
        case 8460: /* module 33 call 12 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 8461: /* module 33 call 13 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 8462: /* module 33 call 14 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_invulnerables;
                default:
                    return NULL;
            }
        case 8463: /* module 33 call 15 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 8464: /* module 33 call 16 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 8465: /* module 33 call 17 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_era;
                case 1:
                    return STR_IT_slash_indices;
                default:
                    return NULL;
            }
        case 8468: /* module 33 call 20 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_history_depth;
                case 1:
                    return STR_IT__era_items_deleted;
                default:
                    return NULL;
            }
        case 8469: /* module 33 call 21 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_stash;
                case 1:
                    return STR_IT_num_slashing_spans;
                default:
                    return NULL;
            }
        case 8470: /* module 33 call 22 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_who;
                default:
                    return NULL;
            }
        case 8471: /* module 33 call 23 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_min_nominator_bond;
                case 1:
                    return STR_IT_min_validator_bond;
                case 2:
                    return STR_IT_max_nominator_count;
                case 3:
                    return STR_IT_max_validator_count;
                case 4:
                    return STR_IT_threshold;
                default:
                    return NULL;
            }
        case 8472: /* module 33 call 24 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_controller;
                default:
                    return NULL;
            }
        case 10240: /* module 40 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_account;
                default:
                    return NULL;
            }
        case 10243: /* module 40 call 3 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 10244: /* module 40 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_reg_index;
                case 1:
                    return STR_IT_max_fee;
                default:
                    return NULL;
            }
        case 10245: /* module 40 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_reg_index;
                default:
                    return NULL;
            }
        case 10246: /* module 40 call 6 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_index;
                case 1:
                    return STR_IT_fee;
                default:
                    return NULL;
            }
        case 10247: /* module 40 call 7 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_index;
                case 1:
                    return STR_IT_new_;
                default:
                    return NULL;
            }
        case 10250: /* module 40 call 10 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_target;
                default:
                    return NULL;
            }
        case 10253: /* module 40 call 13 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_sub;
                default:
                    return NULL;
            }
        case 10254: /* module 40 call 14 */
            switch (itemIdx) {
                default:
                    return NULL;
            }
        case 12800: /* module 50 call 0 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_new_members;
                case 1:
                    return STR_IT_prime;
                case 2:
                    return STR_IT_old_count;
                default:
                    return NULL;
            }
        case 12801: /* module 50 call 1 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal;
                case 1:
                    return STR_IT_length_bound;
                default:
                    return NULL;
            }
        case 12802: /* module 50 call 2 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_threshold;
                case 1:
                    return STR_IT_proposal;
                case 2:
                    return STR_IT_length_bound;
                default:
                    return NULL;
            }
        case 12803: /* module 50 call 3 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal;
                case 1:
                    return STR_IT_index;
                case 2:
                    return STR_IT_approve;
                default:
                    return NULL;
            }
        case 12804: /* module 50 call 4 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal_hash;
                case 1:
                    return STR_IT_index;
                case 2:
                    return STR_IT_proposal_weight_bound;
                case 3:
                    return STR_IT_length_bound;
                default:
                    return NULL;
            }
        case 12805: /* module 50 call 5 */
            switch (itemIdx) {
                case 0:
                    return STR_IT_proposal_hash;
                default:
                    return NULL;
            }
#endif
        default:
            return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(pd_Method_V2_t *m, uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
                                       char *outValue, uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 1536: /* module 6 call 0 */
            switch (itemIdx) {
                case 0: /* balances_transfer_V2 - dest */;
                    return _toStringLookupSource_V2(&m->nested.balances_transfer_V2.dest, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 1: /* balances_transfer_V2 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_V2.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1538: /* module 6 call 2 */
            switch (itemIdx) {
                case 0: /* balances_force_transfer_V2 - source */;
                    return _toStringLookupSource_V2(&m->nested.balances_force_transfer_V2.source, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 1: /* balances_force_transfer_V2 - dest */;
                    return _toStringLookupSource_V2(&m->nested.balances_force_transfer_V2.dest, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 2: /* balances_force_transfer_V2 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_force_transfer_V2.amount, outValue, outValueLen,
                                                   pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1539: /* module 6 call 3 */
            switch (itemIdx) {
                case 0: /* balances_transfer_keep_alive_V2 - dest */;
                    return _toStringLookupSource_V2(&m->nested.balances_transfer_keep_alive_V2.dest, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 1: /* balances_transfer_keep_alive_V2 - amount */;
                    return _toStringCompactBalance(&m->nested.balances_transfer_keep_alive_V2.amount, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 1540: /* module 6 call 4 */
            switch (itemIdx) {
                case 0: /* balances_transfer_all_V2 - dest */;
                    return _toStringLookupSource_V2(&m->basic.balances_transfer_all_V2.dest, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 1: /* balances_transfer_all_V2 - keep_alive */;
                    return _toStringbool(&m->basic.balances_transfer_all_V2.keep_alive, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 2816: /* module 11 call 0 */
            switch (itemIdx) {
                case 0: /* utility_batch_V2 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_V2.calls, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 2818: /* module 11 call 2 */
            switch (itemIdx) {
                case 0: /* utility_batch_all_V2 - calls */;
                    return _toStringVecCall(&m->basic.utility_batch_all_V2.calls, outValue, outValueLen, pageIdx,
                                            pageCount);
                default:
                    return parser_no_data;
            }
        case 8448: /* module 33 call 0 */
            switch (itemIdx) {
                case 0: /* staking_bond_V2 - controller */;
                    return _toStringLookupSource_V2(&m->basic.staking_bond_V2.controller, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 1: /* staking_bond_V2 - amount */;
                    return _toStringCompactBalanceOf(&m->basic.staking_bond_V2.amount, outValue, outValueLen, pageIdx,
                                                     pageCount);
                case 2: /* staking_bond_V2 - payee */;
                    return _toStringRewardDestination_V2(&m->basic.staking_bond_V2.payee, outValue, outValueLen,
                                                         pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8449: /* module 33 call 1 */
            switch (itemIdx) {
                case 0: /* staking_bond_extra_V2 - amount */;
                    return _toStringCompactBalanceOf(&m->basic.staking_bond_extra_V2.amount, outValue, outValueLen,
                                                     pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8450: /* module 33 call 2 */
            switch (itemIdx) {
                case 0: /* staking_unbond_V2 - amount */;
                    return _toStringCompactBalanceOf(&m->basic.staking_unbond_V2.amount, outValue, outValueLen, pageIdx,
                                                     pageCount);
                default:
                    return parser_no_data;
            }
        case 8451: /* module 33 call 3 */
            switch (itemIdx) {
                case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_withdraw_unbonded_V2.num_slashing_spans, outValue,
                                        outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8452: /* module 33 call 4 */
            switch (itemIdx) {
                case 0: /* staking_validate_V2 - prefs */;
                    return _toStringValidatorPrefs_V2(&m->basic.staking_validate_V2.prefs, outValue, outValueLen,
                                                      pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8453: /* module 33 call 5 */
            switch (itemIdx) {
                case 0: /* staking_nominate_V2 - targets */;
                    return _toStringVecLookupSource_V2(&m->basic.staking_nominate_V2.targets, outValue, outValueLen,
                                                       pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8454: /* module 33 call 6 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 8455: /* module 33 call 7 */
            switch (itemIdx) {
                case 0: /* staking_set_payee_V2 - payee */;
                    return _toStringRewardDestination_V2(&m->basic.staking_set_payee_V2.payee, outValue, outValueLen,
                                                         pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8456: /* module 33 call 8 */
            switch (itemIdx) {
                case 0: /* staking_set_controller_V2 - controller */;
                    return _toStringLookupSource_V2(&m->basic.staking_set_controller_V2.controller, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8466: /* module 33 call 18 */
            switch (itemIdx) {
                case 0: /* staking_payout_stakers_V2 - validator_stash */;
                    return _toStringAccountId_V2(&m->basic.staking_payout_stakers_V2.validator_stash, outValue,
                                                 outValueLen, pageIdx, pageCount);
                case 1: /* staking_payout_stakers_V2 - era */;
                    return _toStringEraIndex_V2(&m->basic.staking_payout_stakers_V2.era, outValue, outValueLen, pageIdx,
                                                pageCount);
                default:
                    return parser_no_data;
            }
        case 8467: /* module 33 call 19 */
            switch (itemIdx) {
                case 0: /* staking_rebond_V2 - amount */;
                    return _toStringCompactBalanceOf(&m->basic.staking_rebond_V2.amount, outValue, outValueLen, pageIdx,
                                                     pageCount);
                default:
                    return parser_no_data;
            }
        case 8704: /* module 34 call 0 */
            switch (itemIdx) {
                case 0: /* session_set_keys_V2 - keys */;
                    return _toStringKeys_V2(&m->basic.session_set_keys_V2.keys, outValue, outValueLen, pageIdx,
                                            pageCount);
                case 1: /* session_set_keys_V2 - proof */;
                    return _toStringBytes(&m->basic.session_set_keys_V2.proof, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 8705: /* module 34 call 1 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
#ifdef SUBSTRATE_PARSER_FULL
        case 0: /* module 0 call 0 */
            switch (itemIdx) {
                case 0: /* system_fill_block_V2 - _ratio */;
                    return _toStringPerbill_V2(&m->nested.system_fill_block_V2._ratio, outValue, outValueLen, pageIdx,
                                               pageCount);
                default:
                    return parser_no_data;
            }
        case 1: /* module 0 call 1 */
            switch (itemIdx) {
                case 0: /* system_remark_V2 - _remark */;
                    return _toStringBytes(&m->nested.system_remark_V2._remark, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 2: /* module 0 call 2 */
            switch (itemIdx) {
                case 0: /* system_set_heap_pages_V2 - pages */;
                    return _toStringu64(&m->nested.system_set_heap_pages_V2.pages, outValue, outValueLen, pageIdx,
                                        pageCount);
                default:
                    return parser_no_data;
            }
        case 3: /* module 0 call 3 */
            switch (itemIdx) {
                case 0: /* system_set_code_V2 - code */;
                    return _toStringBytes(&m->nested.system_set_code_V2.code, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 4: /* module 0 call 4 */
            switch (itemIdx) {
                case 0: /* system_set_code_without_checks_V2 - code */;
                    return _toStringBytes(&m->nested.system_set_code_without_checks_V2.code, outValue, outValueLen,
                                          pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 9: /* module 0 call 9 */
            switch (itemIdx) {
                case 0: /* system_remark_with_event_V2 - remark */;
                    return _toStringBytes(&m->nested.system_remark_with_event_V2.remark, outValue, outValueLen, pageIdx,
                                          pageCount);
                default:
                    return parser_no_data;
            }
        case 512: /* module 2 call 0 */
            switch (itemIdx) {
                case 0: /* timestamp_set_V2 - now */;
                    return _toStringCompactMoment_V2(&m->basic.timestamp_set_V2.now, outValue, outValueLen, pageIdx,
                                                     pageCount);
                default:
                    return parser_no_data;
            }
        case 1280: /* module 5 call 0 */
            switch (itemIdx) {
                case 0: /* indices_claim_V2 - index */;
                    return _toStringAccountIndex_V2(&m->basic.indices_claim_V2.index, outValue, outValueLen, pageIdx,
                                                    pageCount);
                default:
                    return parser_no_data;
            }
        case 1281: /* module 5 call 1 */
            switch (itemIdx) {
                case 0: /* indices_transfer_V2 - new_ */;
                    return _toStringAccountId_V2(&m->basic.indices_transfer_V2.new_, outValue, outValueLen, pageIdx,
                                                 pageCount);
                case 1: /* indices_transfer_V2 - index */;
                    return _toStringAccountIndex_V2(&m->basic.indices_transfer_V2.index, outValue, outValueLen, pageIdx,
                                                    pageCount);
                default:
                    return parser_no_data;
            }
        case 1282: /* module 5 call 2 */
            switch (itemIdx) {
                case 0: /* indices_free_V2 - index */;
                    return _toStringAccountIndex_V2(&m->basic.indices_free_V2.index, outValue, outValueLen, pageIdx,
                                                    pageCount);
                default:
                    return parser_no_data;
            }
        case 1283: /* module 5 call 3 */
            switch (itemIdx) {
                case 0: /* indices_force_transfer_V2 - new_ */;
                    return _toStringAccountId_V2(&m->basic.indices_force_transfer_V2.new_, outValue, outValueLen,
                                                 pageIdx, pageCount);
                case 1: /* indices_force_transfer_V2 - index */;
                    return _toStringAccountIndex_V2(&m->basic.indices_force_transfer_V2.index, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 2: /* indices_force_transfer_V2 - freeze */;
                    return _toStringbool(&m->basic.indices_force_transfer_V2.freeze, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 1284: /* module 5 call 4 */
            switch (itemIdx) {
                case 0: /* indices_freeze_V2 - index */;
                    return _toStringAccountIndex_V2(&m->basic.indices_freeze_V2.index, outValue, outValueLen, pageIdx,
                                                    pageCount);
                default:
                    return parser_no_data;
            }
        case 1537: /* module 6 call 1 */
            switch (itemIdx) {
                case 0: /* balances_set_balance_V2 - who */;
                    return _toStringLookupSource_V2(&m->nested.balances_set_balance_V2.who, outValue, outValueLen,
                                                    pageIdx, pageCount);
                case 1: /* balances_set_balance_V2 - new_free */;
                    return _toStringCompactBalance(&m->nested.balances_set_balance_V2.new_free, outValue, outValueLen,
                                                   pageIdx, pageCount);
                case 2: /* balances_set_balance_V2 - new_reserved */;
                    return _toStringCompactBalance(&m->nested.balances_set_balance_V2.new_reserved, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8194: /* module 32 call 2 */
            switch (itemIdx) {
                case 0: /* grandpa_note_stalled_V2 - delay */;
                    return _toStringBlockNumber(&m->basic.grandpa_note_stalled_V2.delay, outValue, outValueLen, pageIdx,
                                                pageCount);
                case 1: /* grandpa_note_stalled_V2 - best_finalized_block_number */;
                    return _toStringBlockNumber(&m->basic.grandpa_note_stalled_V2.best_finalized_block_number, outValue,
                                                outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8457: /* module 33 call 9 */
            switch (itemIdx) {
                case 0: /* staking_set_validator_count_V2 - new_ */;
                    return _toStringCompactu32(&m->basic.staking_set_validator_count_V2.new_, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8458: /* module 33 call 10 */
            switch (itemIdx) {
                case 0: /* staking_increase_validator_count_V2 - additional */;
                    return _toStringCompactu32(&m->basic.staking_increase_validator_count_V2.additional, outValue,
                                               outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8460: /* module 33 call 12 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 8461: /* module 33 call 13 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 8462: /* module 33 call 14 */
            switch (itemIdx) {
                case 0: /* staking_set_invulnerables_V2 - invulnerables */;
                    return _toStringVecAccountId_V2(&m->basic.staking_set_invulnerables_V2.invulnerables, outValue,
                                                    outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8463: /* module 33 call 15 */
            switch (itemIdx) {
                case 0: /* staking_force_unstake_V2 - stash */;
                    return _toStringAccountId_V2(&m->basic.staking_force_unstake_V2.stash, outValue, outValueLen,
                                                 pageIdx, pageCount);
                case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_force_unstake_V2.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8464: /* module 33 call 16 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 8465: /* module 33 call 17 */
            switch (itemIdx) {
                case 0: /* staking_cancel_deferred_slash_V2 - era */;
                    return _toStringEraIndex_V2(&m->basic.staking_cancel_deferred_slash_V2.era, outValue, outValueLen,
                                                pageIdx, pageCount);
                case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
                    return _toStringBytes(&m->basic.staking_cancel_deferred_slash_V2.slash_indices, outValue,
                                          outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8468: /* module 33 call 20 */
            switch (itemIdx) {
                case 0: /* staking_set_history_depth_V2 - new_history_depth */;
                    return _toStringCompactEraIndex_V2(&m->basic.staking_set_history_depth_V2.new_history_depth,
                                                       outValue, outValueLen, pageIdx, pageCount);
                case 1: /* staking_set_history_depth_V2 - _era_items_deleted */;
                    return _toStringCompactu32(&m->basic.staking_set_history_depth_V2._era_items_deleted, outValue,
                                               outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8469: /* module 33 call 21 */
            switch (itemIdx) {
                case 0: /* staking_reap_stash_V2 - stash */;
                    return _toStringAccountId_V2(&m->basic.staking_reap_stash_V2.stash, outValue, outValueLen, pageIdx,
                                                 pageCount);
                case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
                    return _toStringu32(&m->basic.staking_reap_stash_V2.num_slashing_spans, outValue, outValueLen,
                                        pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8470: /* module 33 call 22 */
            switch (itemIdx) {
                case 0: /* staking_kick_V2 - who */;
                    return _toStringVecLookupSource_V2(&m->basic.staking_kick_V2.who, outValue, outValueLen, pageIdx,
                                                       pageCount);
                default:
                    return parser_no_data;
            }
        case 8471: /* module 33 call 23 */
            switch (itemIdx) {
                case 0: /* staking_set_staking_limits_V2 - min_nominator_bond */;
                    return _toStringBalanceOf(&m->basic.staking_set_staking_limits_V2.min_nominator_bond, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 1: /* staking_set_staking_limits_V2 - min_validator_bond */;
                    return _toStringBalanceOf(&m->basic.staking_set_staking_limits_V2.min_validator_bond, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 2: /* staking_set_staking_limits_V2 - max_nominator_count */;
                    return _toStringOptionu32(&m->basic.staking_set_staking_limits_V2.max_nominator_count, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 3: /* staking_set_staking_limits_V2 - max_validator_count */;
                    return _toStringOptionu32(&m->basic.staking_set_staking_limits_V2.max_validator_count, outValue,
                                              outValueLen, pageIdx, pageCount);
                case 4: /* staking_set_staking_limits_V2 - threshold */;
                    return _toStringOptionPercent_V2(&m->basic.staking_set_staking_limits_V2.threshold, outValue,
                                                     outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 8472: /* module 33 call 24 */
            switch (itemIdx) {
                case 0: /* staking_chill_other_V2 - controller */;
                    return _toStringAccountId_V2(&m->basic.staking_chill_other_V2.controller, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10240: /* module 40 call 0 */
            switch (itemIdx) {
                case 0: /* identity_add_registrar_V2 - account */;
                    return _toStringAccountId_V2(&m->basic.identity_add_registrar_V2.account, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10243: /* module 40 call 3 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 10244: /* module 40 call 4 */
            switch (itemIdx) {
                case 0: /* identity_request_judgement_V2 - reg_index */;
                    return _toStringCompactRegistrarIndex_V2(&m->basic.identity_request_judgement_V2.reg_index,
                                                             outValue, outValueLen, pageIdx, pageCount);
                case 1: /* identity_request_judgement_V2 - max_fee */;
                    return _toStringCompactBalanceOf(&m->basic.identity_request_judgement_V2.max_fee, outValue,
                                                     outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10245: /* module 40 call 5 */
            switch (itemIdx) {
                case 0: /* identity_cancel_request_V2 - reg_index */;
                    return _toStringRegistrarIndex_V2(&m->basic.identity_cancel_request_V2.reg_index, outValue,
                                                      outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10246: /* module 40 call 6 */
            switch (itemIdx) {
                case 0: /* identity_set_fee_V2 - index */;
                    return _toStringCompactRegistrarIndex_V2(&m->basic.identity_set_fee_V2.index, outValue, outValueLen,
                                                             pageIdx, pageCount);
                case 1: /* identity_set_fee_V2 - fee */;
                    return _toStringCompactBalanceOf(&m->basic.identity_set_fee_V2.fee, outValue, outValueLen, pageIdx,
                                                     pageCount);
                default:
                    return parser_no_data;
            }
        case 10247: /* module 40 call 7 */
            switch (itemIdx) {
                case 0: /* identity_set_account_id_V2 - index */;
                    return _toStringCompactRegistrarIndex_V2(&m->basic.identity_set_account_id_V2.index, outValue,
                                                             outValueLen, pageIdx, pageCount);
                case 1: /* identity_set_account_id_V2 - new_ */;
                    return _toStringAccountId_V2(&m->basic.identity_set_account_id_V2.new_, outValue, outValueLen,
                                                 pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10250: /* module 40 call 10 */
            switch (itemIdx) {
                case 0: /* identity_kill_identity_V2 - target */;
                    return _toStringLookupSource_V2(&m->basic.identity_kill_identity_V2.target, outValue, outValueLen,
                                                    pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10253: /* module 40 call 13 */
            switch (itemIdx) {
                case 0: /* identity_remove_sub_V2 - sub */;
                    return _toStringLookupSource_V2(&m->basic.identity_remove_sub_V2.sub, outValue, outValueLen,
                                                    pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 10254: /* module 40 call 14 */
            switch (itemIdx) {
                default:
                    return parser_no_data;
            }
        case 12800: /* module 50 call 0 */
            switch (itemIdx) {
                case 0: /* techcouncil_set_members_V2 - new_members */;
                    return _toStringVecAccountId_V2(&m->basic.techcouncil_set_members_V2.new_members, outValue,
                                                    outValueLen, pageIdx, pageCount);
                case 1: /* techcouncil_set_members_V2 - prime */;
                    return _toStringOptionAccountId_V2(&m->basic.techcouncil_set_members_V2.prime, outValue,
                                                       outValueLen, pageIdx, pageCount);
                case 2: /* techcouncil_set_members_V2 - old_count */;
                    return _toStringMemberCount_V2(&m->basic.techcouncil_set_members_V2.old_count, outValue,
                                                   outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12801: /* module 50 call 1 */
            switch (itemIdx) {
                case 0: /* techcouncil_execute_V2 - proposal */;
                    return _toStringProposal(&m->basic.techcouncil_execute_V2.proposal, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 1: /* techcouncil_execute_V2 - length_bound */;
                    return _toStringCompactu32(&m->basic.techcouncil_execute_V2.length_bound, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12802: /* module 50 call 2 */
            switch (itemIdx) {
                case 0: /* techcouncil_propose_V2 - threshold */;
                    return _toStringCompactMemberCount_V2(&m->basic.techcouncil_propose_V2.threshold, outValue,
                                                          outValueLen, pageIdx, pageCount);
                case 1: /* techcouncil_propose_V2 - proposal */;
                    return _toStringProposal(&m->basic.techcouncil_propose_V2.proposal, outValue, outValueLen, pageIdx,
                                             pageCount);
                case 2: /* techcouncil_propose_V2 - length_bound */;
                    return _toStringCompactu32(&m->basic.techcouncil_propose_V2.length_bound, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12803: /* module 50 call 3 */
            switch (itemIdx) {
                case 0: /* techcouncil_vote_V2 - proposal */;
                    return _toStringHash(&m->basic.techcouncil_vote_V2.proposal, outValue, outValueLen, pageIdx,
                                         pageCount);
                case 1: /* techcouncil_vote_V2 - index */;
                    return _toStringCompactProposalIndex_V2(&m->basic.techcouncil_vote_V2.index, outValue, outValueLen,
                                                            pageIdx, pageCount);
                case 2: /* techcouncil_vote_V2 - approve */;
                    return _toStringbool(&m->basic.techcouncil_vote_V2.approve, outValue, outValueLen, pageIdx,
                                         pageCount);
                default:
                    return parser_no_data;
            }
        case 12804: /* module 50 call 4 */
            switch (itemIdx) {
                case 0: /* techcouncil_close_V2 - proposal_hash */;
                    return _toStringHash(&m->basic.techcouncil_close_V2.proposal_hash, outValue, outValueLen, pageIdx,
                                         pageCount);
                case 1: /* techcouncil_close_V2 - index */;
                    return _toStringCompactProposalIndex_V2(&m->basic.techcouncil_close_V2.index, outValue, outValueLen,
                                                            pageIdx, pageCount);
                case 2: /* techcouncil_close_V2 - proposal_weight_bound */;
                    return _toStringCompactWeight_V2(&m->basic.techcouncil_close_V2.proposal_weight_bound, outValue,
                                                     outValueLen, pageIdx, pageCount);
                case 3: /* techcouncil_close_V2 - length_bound */;
                    return _toStringCompactu32(&m->basic.techcouncil_close_V2.length_bound, outValue, outValueLen,
                                               pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
        case 12805: /* module 50 call 5 */
            switch (itemIdx) {
                case 0: /* techcouncil_disapprove_proposal_V2 - proposal_hash */;
                    return _toStringHash(&m->basic.techcouncil_disapprove_proposal_V2.proposal_hash, outValue,
                                         outValueLen, pageIdx, pageCount);
                default:
                    return parser_no_data;
            }
#endif
        default:
            return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 8451:  // Staking:Withdraw Unbonded
            switch (itemIdx) {
                case 0:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 8463:  // Staking:Force unstake
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }
        case 8469:  // Staking:Reap stash
            switch (itemIdx) {
                case 1:  // Num slashing spans
                    return true;
                default:
                    return false;
            }

        default:
            return false;
    }
}

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx) {
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
        case 512:    // Timestamp:Set
        case 1280:   // Indices:Claim
        case 1281:   // Indices:Transfer
        case 1282:   // Indices:Free
        case 1283:   // Indices:Force transfer
        case 1284:   // Indices:Freeze
        case 1540:   // Balances:Transfer all
        case 2816:   // Utility:Batch
        case 2818:   // Utility:Batch all
        case 8194:   // Grandpa:Note stalled
        case 8448:   // Staking:Bond
        case 8449:   // Staking:Bond extra
        case 8450:   // Staking:Unbond
        case 8451:   // Staking:Withdraw Unbonded
        case 8452:   // Staking:Validate
        case 8453:   // Staking:Nominate
        case 8454:   // Staking:Chill
        case 8455:   // Staking:Set payee
        case 8456:   // Staking:Set controller
        case 8457:   // Staking:Set validator count
        case 8458:   // Staking:Increase validator count
        case 8460:   // Staking:Force no eras
        case 8461:   // Staking:Force new era
        case 8462:   // Staking:Set invulnerables
        case 8463:   // Staking:Force unstake
        case 8464:   // Staking:Force new era always
        case 8465:   // Staking:Cancel deferred slash
        case 8466:   // Staking:Payout stakers
        case 8467:   // Staking:Rebond
        case 8468:   // Staking:Set history depth
        case 8469:   // Staking:Reap stash
        case 8470:   // Staking:Kick
        case 8471:   // Staking:Set staking limits
        case 8472:   // Staking:Chill other
        case 8704:   // Session:Set keys
        case 8705:   // Session:Purge keys
        case 10240:  // Identity:Add registrar
        case 10243:  // Identity:Clear identity
        case 10244:  // Identity:Request judgement
        case 10245:  // Identity:Cancel request
        case 10246:  // Identity:Set fee
        case 10247:  // Identity:Set account id
        case 10250:  // Identity:Kill identity
        case 10253:  // Identity:Remove sub
        case 10254:  // Identity:Quit sub
        case 12800:  // TechCouncil:Set members
        case 12801:  // TechCouncil:Execute
        case 12802:  // TechCouncil:Propose
        case 12803:  // TechCouncil:Vote
        case 12804:  // TechCouncil:Close
        case 12805:  // TechCouncil:Disapprove proposal
            return false;
        default:
            return true;
    }
}
