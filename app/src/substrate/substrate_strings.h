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

// Modules names
static const char *STR_MO_SYSTEM = "System";
static const char *STR_MO_TIMESTAMP = "Timestamp";
static const char *STR_MO_SUDO = "Sudo";
static const char *STR_MO_INDICES = "Indices";
static const char *STR_MO_BALANCES = "Balances";
static const char *STR_MO_CURRENCIES = "Currencies";
static const char *STR_MO_TRANSACTIONPAYMENT = "Transactionpayment";
static const char *STR_MO_AUTHORITY = "Authority";
static const char *STR_MO_UTILITY = "Utility";
static const char *STR_MO_MULTISIG = "Multisig";
static const char *STR_MO_EVMACCOUNTS = "Evmaccounts";
static const char *STR_MO_EVM = "Evm";
static const char *STR_MO_STAKING = "Staking";
static const char *STR_MO_SESSION = "Session";
static const char *STR_MO_IDENTITY = "Identity";
static const char *STR_MO_TECHCOUNCIL = "Techcouncil";
static const char *STR_MO_POC = "Poc";

// Methods names
static const char *STR_ME_FILL_BLOCK = "Fill block";
static const char *STR_ME_REMARK = "Remark";
static const char *STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char *STR_ME_SET_CODE = "Set code";
static const char *STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char *STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char *STR_ME_SET = "Set";
static const char *STR_ME_SUDO = "Sudo";
static const char *STR_ME_SUDO_UNCHECKED_WEIGHT = "Sudo unchecked weight";
static const char *STR_ME_SET_KEY = "Set key";
static const char *STR_ME_SUDO_AS = "Sudo as";
static const char *STR_ME_CLAIM = "Claim";
static const char *STR_ME_TRANSFER = "Transfer";
static const char *STR_ME_FREE = "Free";
static const char *STR_ME_FORCE_TRANSFER = "Force transfer";
static const char *STR_ME_FREEZE = "Freeze";
static const char *STR_ME_SET_BALANCE = "Set balance";
static const char *STR_ME_TRANSFER_KEEP_ALIVE = "Transfer keep alive";
static const char *STR_ME_TRANSFER_ALL = "Transfer all";
static const char *STR_ME_TRANSFER_NATIVE_CURRENCY = "Transfer native currency";
static const char *STR_ME_UPDATE_BALANCE = "Update balance";
static const char *STR_ME_SET_DEFAULT_FEE_TOKEN = "Set default fee token";
static const char *STR_ME_DISPATCH_AS = "Dispatch as";
static const char *STR_ME_SCHEDULE_DISPATCH = "Schedule dispatch";
static const char *STR_ME_FAST_TRACK_SCHEDULED_DISPATCH = "Fast track scheduled dispatch";
static const char *STR_ME_DELAY_SCHEDULED_DISPATCH = "Delay scheduled dispatch";
static const char *STR_ME_CANCEL_SCHEDULED_DISPATCH = "Cancel scheduled dispatch";
static const char *STR_ME_AUTHORIZE_CALL = "Authorize call";
static const char *STR_ME_REMOVE_AUTHORIZED_CALL = "Remove authorized call";
static const char *STR_ME_TRIGGER_CALL = "Trigger call";
static const char *STR_ME_BATCH = "Batch";
static const char *STR_ME_BATCH_ALL = "Batch all";
static const char *STR_ME_AS_MULTI_THRESHOLD_1 = "As multi threshold 1";
static const char *STR_ME_AS_MULTI = "As multi";
static const char *STR_ME_APPROVE_AS_MULTI = "Approve as multi";
static const char *STR_ME_CANCEL_AS_MULTI = "Cancel as multi";
static const char *STR_ME_CLAIM_ACCOUNT = "Claim account";
static const char *STR_ME_CLAIM_DEFAULT_ACCOUNT = "Claim default account";
static const char *STR_ME_CALL = "Call";
static const char *STR_ME_SCHEDULED_CALL = "Scheduled call";
static const char *STR_ME_CREATE = "Create";
static const char *STR_ME_CREATE2 = "Create2";
static const char *STR_ME_CREATE_NETWORK_CONTRACT = "Create network contract";
static const char *STR_ME_TRANSFER_MAINTAINER = "Transfer maintainer";
static const char *STR_ME_DEPLOY = "Deploy";
static const char *STR_ME_DEPLOY_FREE = "Deploy free";
static const char *STR_ME_ENABLE_CONTRACT_DEVELOPMENT = "Enable contract development";
static const char *STR_ME_DISABLE_CONTRACT_DEVELOPMENT = "Disable contract development";
static const char *STR_ME_SELFDESTRUCT = "Selfdestruct";
static const char *STR_ME_BOND = "Bond";
static const char *STR_ME_BOND_EXTRA = "Bond extra";
static const char *STR_ME_UNBOND = "Unbond";
static const char *STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char *STR_ME_VALIDATE = "Validate";
static const char *STR_ME_NOMINATE = "Nominate";
static const char *STR_ME_CHILL = "Chill";
static const char *STR_ME_SET_PAYEE = "Set payee";
static const char *STR_ME_SET_CONTROLLER = "Set controller";
static const char *STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char *STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char *STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char *STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char *STR_ME_FORCE_NEW_ERA = "Force new era";
static const char *STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char *STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char *STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char *STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char *STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char *STR_ME_REBOND = "Rebond";
static const char *STR_ME_SET_HISTORY_DEPTH = "Set history depth";
static const char *STR_ME_REAP_STASH = "Reap stash";
static const char *STR_ME_KICK = "Kick";
static const char *STR_ME_SET_STAKING_LIMITS = "Set staking limits";
static const char *STR_ME_CHILL_OTHER = "Chill other";
static const char *STR_ME_SET_KEYS = "Set keys";
static const char *STR_ME_PURGE_KEYS = "Purge keys";
static const char *STR_ME_ADD_REGISTRAR = "Add registrar";
static const char *STR_ME_SET_IDENTITY = "Set identity";
static const char *STR_ME_SET_SUBS = "Set subs";
static const char *STR_ME_CLEAR_IDENTITY = "Clear identity";
static const char *STR_ME_REQUEST_JUDGEMENT = "Request judgement";
static const char *STR_ME_CANCEL_REQUEST = "Cancel request";
static const char *STR_ME_SET_FEE = "Set fee";
static const char *STR_ME_SET_ACCOUNT_ID = "Set account id";
static const char *STR_ME_PROVIDE_JUDGEMENT = "Provide judgement";
static const char *STR_ME_KILL_IDENTITY = "Kill identity";
static const char *STR_ME_ADD_SUB = "Add sub";
static const char *STR_ME_RENAME_SUB = "Rename sub";
static const char *STR_ME_REMOVE_SUB = "Remove sub";
static const char *STR_ME_QUIT_SUB = "Quit sub";
static const char *STR_ME_SET_MEMBERS = "Set members";
static const char *STR_ME_EXECUTE = "Execute";
static const char *STR_ME_PROPOSE = "Propose";
static const char *STR_ME_VOTE = "Vote";
static const char *STR_ME_CLOSE = "Close";
static const char *STR_ME_DISAPPROVE_PROPOSAL = "Disapprove proposal";
static const char *STR_ME_START_CANDIDACY = "Start candidacy";
static const char *STR_ME_STOP_CANDIDACY = "Stop candidacy";
static const char *STR_ME_COMMIT = "Commit";
static const char *STR_ME_ADD_FUNDS = "Add funds";
static const char *STR_ME_WITHDRAW = "Withdraw";
static const char *STR_ME_VOTE_CANDIDATE = "Vote candidate";

// Items names
static const char *STR_IT__ratio = "Ratio";
static const char *STR_IT__remark = "Remark";
static const char *STR_IT_pages = "Pages";
static const char *STR_IT_code = "Code";
static const char *STR_IT_changes_trie_config = "Changes trie config";
static const char *STR_IT_items = "Items";
static const char *STR_IT_keys = "Keys";
static const char *STR_IT_prefix = "Prefix";
static const char *STR_IT__subkeys = "Subkeys";
static const char *STR_IT_remark = "Remark";
static const char *STR_IT_now = "Now";
static const char *STR_IT_call = "Call";
static const char *STR_IT__weight = "Weight";
static const char *STR_IT_new_ = "New";
static const char *STR_IT_who = "Who";
static const char *STR_IT_index = "Index";
static const char *STR_IT_freeze = "Freeze";
static const char *STR_IT_dest = "Dest";
static const char *STR_IT_amount = "Amount";
static const char *STR_IT_new_free = "New free";
static const char *STR_IT_new_reserved = "New reserved";
static const char *STR_IT_source = "Source";
static const char *STR_IT_keep_alive = "Keep alive";
static const char *STR_IT_currency_id = "Currency id";
static const char *STR_IT_fee_token = "Fee token";
static const char *STR_IT_as_origin = "As origin";
static const char *STR_IT_when = "When";
static const char *STR_IT_priority = "Priority";
static const char *STR_IT_with_delayed_origin = "With delayed origin";
static const char *STR_IT_initial_origin = "Initial origin";
static const char *STR_IT_task_id = "Task id";
static const char *STR_IT_additional_delay = "Additional delay";
static const char *STR_IT_caller = "Caller";
static const char *STR_IT_hash = "Hash";
static const char *STR_IT_call_weight_bound = "Call weight bound";
static const char *STR_IT_calls = "Calls";
static const char *STR_IT_other_signatories = "Other signatories";
static const char *STR_IT_threshold = "Threshold";
static const char *STR_IT_maybe_timepoint = "Maybe timepoint";
static const char *STR_IT_store_call = "Store call";
static const char *STR_IT_max_weight = "Max weight";
static const char *STR_IT_call_hash = "Call hash";
static const char *STR_IT_timepoint = "Timepoint";
static const char *STR_IT_eth_address = "Eth address";
static const char *STR_IT_eth_signature = "Eth signature";
static const char *STR_IT_target = "Target";
static const char *STR_IT_input = "Input";
static const char *STR_IT_gas_limit = "Gas limit";
static const char *STR_IT_storage_limit = "Storage limit";
static const char *STR_IT_from = "From";
static const char *STR_IT_init = "Init";
static const char *STR_IT_salt = "Salt";
static const char *STR_IT_contract = "Contract";
static const char *STR_IT_new_maintainer = "New maintainer";
static const char *STR_IT_controller = "Controller";
static const char *STR_IT_payee = "Payee";
static const char *STR_IT_num_slashing_spans = "Num slashing spans";
static const char *STR_IT_prefs = "Prefs";
static const char *STR_IT_targets = "Targets";
static const char *STR_IT_additional = "Additional";
static const char *STR_IT_factor = "Factor";
static const char *STR_IT_invulnerables = "Invulnerables";
static const char *STR_IT_stash = "Stash";
static const char *STR_IT_era = "Era";
static const char *STR_IT_slash_indices = "Slash indices";
static const char *STR_IT_validator_stash = "Validator stash";
static const char *STR_IT_new_history_depth = "New history depth";
static const char *STR_IT__era_items_deleted = "Era items deleted";
static const char *STR_IT_min_nominator_bond = "Min nominator bond";
static const char *STR_IT_min_validator_bond = "Min validator bond";
static const char *STR_IT_max_nominator_count = "Max nominator count";
static const char *STR_IT_max_validator_count = "Max validator count";
static const char *STR_IT_proof = "Proof";
static const char *STR_IT_account = "Account";
static const char *STR_IT_info = "Info";
static const char *STR_IT_subs = "Subs";
static const char *STR_IT_reg_index = "Reg index";
static const char *STR_IT_max_fee = "Max fee";
static const char *STR_IT_fee = "Fee";
static const char *STR_IT_fields = "Fields";
static const char *STR_IT_judgement = "Judgement";
static const char *STR_IT_sub = "Sub";
static const char *STR_IT_data = "Data";
static const char *STR_IT_new_members = "New members";
static const char *STR_IT_prime = "Prime";
static const char *STR_IT_old_count = "Old count";
static const char *STR_IT_proposal = "Proposal";
static const char *STR_IT_length_bound = "Length bound";
static const char *STR_IT_approve = "Approve";
static const char *STR_IT_proposal_hash = "Proposal hash";
static const char *STR_IT_proposal_weight_bound = "Proposal weight bound";
static const char *STR_IT_duration = "Duration";
static const char *STR_IT_candidate = "Candidate";

#ifdef __cplusplus
}
#endif
