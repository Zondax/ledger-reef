# Ledger Reef App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/zondax/ledger-reef/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-reef/blob/main/.github/workflows/main.yaml)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Reef app (<https://reef.io/>) for Ledger Nano S+, X, Stax and Flex.

- Ledger Nano S+/X/Stax/Flex BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Reef  2.10.x

## System

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|fill_block|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Perbill`_ratio<br/>|
|remark|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Bytes`_remark<br/>|
|set_heap_pages|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`u64`pages<br/>|
|set_code|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Bytes`code<br/>|
|set_code_without_checks|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Bytes`code<br/>|
|set_changes_trie_config||||`Option<ChangesTrieConfiguration>`changes_trie_config<br/>|
|set_storage||||`Vec<KeyValue>`items<br/>|
|kill_storage||||`Vec<Key>`keys<br/>|
|kill_prefix||||`Key`prefix<br/>`u32`_subkeys<br/>|
|remark_with_event|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Bytes`remark<br/>|

## RandomnessCollectiveFlip

Empty

## Timestamp

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|set|:heavy_check_mark:|:heavy_check_mark:||`Compact<Moment>`now<br/>|

## Sudo

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|sudo||||`Call`call<br/>|
|sudo_unchecked_weight||||`Call`call<br/>`Weight`_weight<br/>|
|set_key||||`LookupSource`new<br/>|
|sudo_as||||`LookupSource`who<br/>`Call`call<br/>|

## Scheduler

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|schedule||||`BlockNumber`when<br/>`Option<Period>`maybe_periodic<br/>`Priority`priority<br/>`Call`call<br/>|
|cancel||||`BlockNumber`when<br/>`u32`index<br/>|
|schedule_named||||`Bytes`id<br/>`BlockNumber`when<br/>`Option<Period>`maybe_periodic<br/>`Priority`priority<br/>`Call`call<br/>|
|cancel_named||||`Bytes`id<br/>|
|schedule_after||||`BlockNumber`after<br/>`Option<Period>`maybe_periodic<br/>`Priority`priority<br/>`Call`call<br/>|
|schedule_named_after||||`Bytes`id<br/>`BlockNumber`after<br/>`Option<Period>`maybe_periodic<br/>`Priority`priority<br/>`Call`call<br/>|

## Indices

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|claim|:heavy_check_mark:|:heavy_check_mark:||`AccountIndex`index<br/>|
|transfer|:heavy_check_mark:|:heavy_check_mark:||`AccountId`new<br/>`AccountIndex`index<br/>|
|free|:heavy_check_mark:|:heavy_check_mark:||`AccountIndex`index<br/>|
|force_transfer|:heavy_check_mark:|:heavy_check_mark:||`AccountId`new<br/>`AccountIndex`index<br/>`bool`freeze<br/>|
|freeze|:heavy_check_mark:|:heavy_check_mark:||`AccountIndex`index<br/>|

## Balances

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|transfer|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`dest<br/>`Compact<Balance>`value<br/>|
|set_balance|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`who<br/>`Compact<Balance>`new_free<br/>`Compact<Balance>`new_reserved<br/>|
|force_transfer|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`source<br/>`LookupSource`dest<br/>`Compact<Balance>`value<br/>|
|transfer_keep_alive|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`dest<br/>`Compact<Balance>`value<br/>|
|transfer_all|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`dest<br/>`bool`keep_alive<br/>|

## Currencies

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|transfer||||`LookupSource`dest<br/>`CurrencyIdOf`currency_id<br/>`Compact<BalanceOf>`amount<br/>|
|transfer_native_currency||||`LookupSource`dest<br/>`Compact<BalanceOf>`amount<br/>|
|update_balance||||`LookupSource`who<br/>`CurrencyIdOf`currency_id<br/>`AmountOf`amount<br/>|

## Tokens

Empty

## TransactionPayment

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|set_default_fee_token||||`Option<CurrencyId>`fee_token<br/>|

## Authority

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|dispatch_as||||`AsOriginId`as_origin<br/>`CallOf`call<br/>|
|schedule_dispatch||||`DispatchTime`when<br/>`Priority`priority<br/>`bool`with_delayed_origin<br/>`CallOf`call<br/>|
|fast_track_scheduled_dispatch||||`PalletsOrigin`initial_origin<br/>`ScheduleTaskIndex`task_id<br/>`DispatchTime`when<br/>|
|delay_scheduled_dispatch||||`PalletsOrigin`initial_origin<br/>`ScheduleTaskIndex`task_id<br/>`BlockNumber`additional_delay<br/>|
|cancel_scheduled_dispatch||||`PalletsOrigin`initial_origin<br/>`ScheduleTaskIndex`task_id<br/>|
|authorize_call||||`CallOf`call<br/>`Option<AccountId>`caller<br/>|
|remove_authorized_call||||`Hash`hash<br/>|
|trigger_call||||`Hash`hash<br/>`Compact<Weight>`call_weight_bound<br/>|

## Utility

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|batch|:heavy_check_mark:|:heavy_check_mark:||`Vec<Call>`calls<br/>|
|as_derivative||||`u16`index<br/>`Call`call<br/>|
|batch_all|:heavy_check_mark:|:heavy_check_mark:||`Vec<Call>`calls<br/>|

## Multisig

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|as_multi_threshold_1||||`Vec<AccountId>`other_signatories<br/>`Call`call<br/>|
|as_multi||||`u16`threshold<br/>`Vec<AccountId>`other_signatories<br/>`Option<Timepoint>`maybe_timepoint<br/>`OpaqueCall`call<br/>`bool`store_call<br/>`Weight`max_weight<br/>|
|approve_as_multi||||`u16`threshold<br/>`Vec<AccountId>`other_signatories<br/>`Option<Timepoint>`maybe_timepoint<br/>`[u8;32]`call_hash<br/>`Weight`max_weight<br/>|
|cancel_as_multi||||`u16`threshold<br/>`Vec<AccountId>`other_signatories<br/>`Timepoint`timepoint<br/>`[u8;32]`call_hash<br/>|

## EvmAccounts

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|claim_account||||`EvmAddress`eth_address<br/>`EcdsaSignature`eth_signature<br/>|
|claim_default_account|||||

## EVM

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|call||||`EvmAddress`target<br/>`Bytes`input<br/>`BalanceOf`value<br/>`u64`gas_limit<br/>`u32`storage_limit<br/>|
|scheduled_call||||`EvmAddress`from<br/>`EvmAddress`target<br/>`Bytes`input<br/>`BalanceOf`value<br/>`u64`gas_limit<br/>`u32`storage_limit<br/>|
|create||||`Bytes`init<br/>`BalanceOf`value<br/>`u64`gas_limit<br/>`u32`storage_limit<br/>|
|create2||||`Bytes`init<br/>`H256`salt<br/>`BalanceOf`value<br/>`u64`gas_limit<br/>`u32`storage_limit<br/>|
|create_network_contract||||`Bytes`init<br/>`BalanceOf`value<br/>`u64`gas_limit<br/>`u32`storage_limit<br/>|
|transfer_maintainer||||`EvmAddress`contract<br/>`EvmAddress`new_maintainer<br/>|
|deploy||||`EvmAddress`contract<br/>|
|deploy_free||||`EvmAddress`contract<br/>|
|enable_contract_development|||||
|disable_contract_development|||||
|set_code||||`EvmAddress`contract<br/>`Bytes`code<br/>|
|selfdestruct||||`EvmAddress`contract<br/>|

## EVMBridge

Empty

## Authorship

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|set_uncles||||`Vec<Header>`new_uncles<br/>|

## Babe

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|report_equivocation||||`BabeEquivocationProof`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/>|
|report_equivocation_unsigned||||`BabeEquivocationProof`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/>|
|plan_config_change||||`NextConfigDescriptor`config<br/>|

## Grandpa

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|report_equivocation||||`GrandpaEquivocationProof`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/>|
|report_equivocation_unsigned||||`GrandpaEquivocationProof`equivocation_proof<br/>`KeyOwnerProof`key_owner_proof<br/>|
|note_stalled||||`BlockNumber`delay<br/>`BlockNumber`best_finalized_block_number<br/>|

## Staking

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|bond|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`controller<br/>`Compact<BalanceOf>`value<br/>`RewardDestination`payee<br/>|
|bond_extra|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Compact<BalanceOf>`max_additional<br/>|
|unbond|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Compact<BalanceOf>`value<br/>|
|withdraw_unbonded|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`u32`num_slashing_spans<br/>|
|validate|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`ValidatorPrefs`prefs<br/>|
|nominate|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Vec<LookupSource>`targets<br/>|
|chill|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:||
|set_payee|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`RewardDestination`payee<br/>|
|set_controller|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`LookupSource`controller<br/>|
|set_validator_count|:heavy_check_mark:|:heavy_check_mark:||`Compact<u32>`new<br/>|
|increase_validator_count|:heavy_check_mark:|:heavy_check_mark:||`Compact<u32>`additional<br/>|
|scale_validator_count|:heavy_check_mark:|:heavy_check_mark:||`Percent`factor<br/>|
|force_no_eras|:heavy_check_mark:|:heavy_check_mark:|||
|force_new_era|:heavy_check_mark:|:heavy_check_mark:|||
|set_invulnerables|:heavy_check_mark:|:heavy_check_mark:||`Vec<AccountId>`invulnerables<br/>|
|force_unstake|:heavy_check_mark:|:heavy_check_mark:||`AccountId`stash<br/>`u32`num_slashing_spans<br/>|
|force_new_era_always|:heavy_check_mark:|:heavy_check_mark:|||
|cancel_deferred_slash|:heavy_check_mark:|:heavy_check_mark:||`EraIndex`era<br/>`Vec<u32>`slash_indices<br/>|
|payout_stakers|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`AccountId`validator_stash<br/>`EraIndex`era<br/>|
|rebond|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Compact<BalanceOf>`value<br/>|
|set_history_depth|:heavy_check_mark:|:heavy_check_mark:||`Compact<EraIndex>`new_history_depth<br/>`Compact<u32>`_era_items_deleted<br/>|
|reap_stash|:heavy_check_mark:|:heavy_check_mark:||`AccountId`stash<br/>`u32`num_slashing_spans<br/>|
|kick|:heavy_check_mark:|:heavy_check_mark:||`Vec<LookupSource>`who<br/>|
|set_staking_limits|:heavy_check_mark:|:heavy_check_mark:||`BalanceOf`min_nominator_bond<br/>`BalanceOf`min_validator_bond<br/>`Option<u32>`max_nominator_count<br/>`Option<u32>`max_validator_count<br/>`Option<Percent>`threshold<br/>|
|chill_other|:heavy_check_mark:|:heavy_check_mark:||`AccountId`controller<br/>|

## Session

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|set_keys|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|`Keys`keys<br/>`Bytes`proof<br/>|
|purge_keys|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:||

## Historical

Empty

## Offences

Empty

## ImOnline

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|heartbeat||||`Heartbeat`heartbeat<br/>`Signature`_signature<br/>|

## AuthorityDiscovery

Empty

## Identity

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|add_registrar|:heavy_check_mark:|:heavy_check_mark:||`AccountId`account<br/>|
|set_identity||||`IdentityInfo`info<br/>|
|set_subs||||`Vec<(AccountId,Data)>`subs<br/>|
|clear_identity|:heavy_check_mark:|:heavy_check_mark:|||
|request_judgement|:heavy_check_mark:|:heavy_check_mark:||`Compact<RegistrarIndex>`reg_index<br/>`Compact<BalanceOf>`max_fee<br/>|
|cancel_request|:heavy_check_mark:|:heavy_check_mark:||`RegistrarIndex`reg_index<br/>|
|set_fee|:heavy_check_mark:|:heavy_check_mark:||`Compact<RegistrarIndex>`index<br/>`Compact<BalanceOf>`fee<br/>|
|set_account_id|:heavy_check_mark:|:heavy_check_mark:||`Compact<RegistrarIndex>`index<br/>`AccountId`new<br/>|
|set_fields||||`Compact<RegistrarIndex>`index<br/>`IdentityFields`fields<br/>|
|provide_judgement||||`Compact<RegistrarIndex>`reg_index<br/>`LookupSource`target<br/>`IdentityJudgement`judgement<br/>|
|kill_identity|:heavy_check_mark:|:heavy_check_mark:||`LookupSource`target<br/>|
|add_sub||||`LookupSource`sub<br/>`Data`data<br/>|
|rename_sub||||`LookupSource`sub<br/>`Data`data<br/>|
|remove_sub|:heavy_check_mark:|:heavy_check_mark:||`LookupSource`sub<br/>|
|quit_sub|:heavy_check_mark:|:heavy_check_mark:|||

## TechCouncil

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|set_members|:heavy_check_mark:|:heavy_check_mark:||`Vec<AccountId>`new_members<br/>`Option<AccountId>`prime<br/>`MemberCount`old_count<br/>|
|execute|:heavy_check_mark:|:heavy_check_mark:||`Proposal`proposal<br/>`Compact<u32>`length_bound<br/>|
|propose|:heavy_check_mark:|:heavy_check_mark:||`Compact<MemberCount>`threshold<br/>`Proposal`proposal<br/>`Compact<u32>`length_bound<br/>|
|vote|:heavy_check_mark:|:heavy_check_mark:||`Hash`proposal<br/>`Compact<ProposalIndex>`index<br/>`bool`approve<br/>|
|close|:heavy_check_mark:|:heavy_check_mark:||`Hash`proposal_hash<br/>`Compact<ProposalIndex>`index<br/>`Compact<Weight>`proposal_weight_bound<br/>`Compact<u32>`length_bound<br/>|
|disapprove_proposal|:heavy_check_mark:|:heavy_check_mark:||`Hash`proposal_hash<br/>|

## Poc

|Name|Nano SP/X|Stax/Flex|Nesting|Arguments|
|-|-|-|-|-|
|start_candidacy|||||
|stop_candidacy|||||
|commit||||`Compact<BalanceOf>`amount<br/>`LockDuration`duration<br/>`AccountId`candidate<br/>|
|add_funds||||`Compact<BalanceOf>`amount<br/>|
|unbond|||||
|withdraw|||||
|vote_candidate||||`AccountId`candidate<br/>|
