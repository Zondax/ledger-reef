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

#define COIN_ADDR_TYPE 42
#define CLA 0xa2

#define INS_SIGN_RAW 0x03

#define HDPATH_LEN_DEFAULT 5
#define HDPATH_0_DEFAULT (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT (0x80000000 | 0x333)
#define HDPATH_1_RECOVERY (0x80000000 | 0x162)

#define HDPATH_2_DEFAULT (0x80000000u | 0u)
#define HDPATH_3_DEFAULT (0u)
#define HDPATH_4_DEFAULT (0u)

#define SK_LEN_25519 64u
#define SCALAR_LEN_ED25519 32u
#define SIG_PLUS_TYPE_LEN 65u

#define PK_LEN_25519 32u
#define MAX_SIGN_SIZE 256u
#define BLAKE2B_DIGEST_SIZE 32u

typedef enum {
    key_ed25519 = 0,

#if defined(SUPPORT_SR25519)
    key_sr25519 = 1
#endif

} key_kind_e;

// Coin Specific
#define PK_ADDRESS_TYPE COIN_ADDR_TYPE
#ifdef LEDGER_SPECIFIC
#define SUPPORTED_TX_VERSION_CURRENT MAJOR_VERSION
#define SUPPORTED_TX_VERSION_PREVIOUS (MAJOR_VERSION - 1)
#define SUPPORTED_SPEC_VERSION (MINOR_VERSION + 0)
#else
#define SUPPORTED_TX_VERSION_CURRENT LEDGER_MAJOR_VERSION
#define SUPPORTED_TX_VERSION_PREVIOUS (LEDGER_MAJOR_VERSION - 1)
#define SUPPORTED_SPEC_VERSION (LEDGER_MINOR_VERSION + 0)
#endif
#define SUPPORTED_MINIMUM_SPEC_VERSION 1

#define COIN_AMOUNT_DECIMAL_PLACES 18

#define COIN_GENESIS_HASH "7834781d38e4798d548e34ec947d19deea29df148a7bf32484b7b24dacf8d4b7"
#define COIN_NAME "Reef"
#define COIN_TICKER "REEF "

#define MENU_MAIN_APP_LINE1 "Reef"
#define MENU_MAIN_APP_LINE2 "Ready"
#define APPVERSION_LINE1 "Reef"
#define APPVERSION_LINE2 "v" APPVERSION

#define ACCOUNT_DEFAULT "Legacy"
#define ACCOUNT_SECONDARY "Crowdloan"

#ifdef __cplusplus
}
#endif
