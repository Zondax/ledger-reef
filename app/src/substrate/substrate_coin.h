/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

#define COIN_ADDR_TYPE 2
#define CLA 0x99

#define INS_SIGN_RAW 0x03

#define HDPATH_LEN_DEFAULT 5
#define HDPATH_0_DEFAULT (0x80000000 | 0x2c)
#define HDPATH_1_DEFAULT (0x80000000 | 0x1b2)
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

#define KEY_TYPE_ED25519 0

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

#define SUPPORTED_MINIMUM_SPEC_VERSION 9000

#define COIN_AMOUNT_DECIMAL_PLACES 12

#define COIN_GENESIS_HASH "b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe"
#define COIN_NAME "Kusama"
#define COIN_TICKER "KSM "

#define COIN_SECRET_REQUIRED_CLICKS 10

#define MENU_MAIN_APP_LINE1 "Kusama"
#define MENU_MAIN_APP_LINE2 "Ready"
#define MENU_MAIN_APP_LINE2_SECRET "KSM RECOVERY"
#define APPVERSION_LINE1 "Kusama"
#define APPVERSION_LINE2 "v" APPVERSION

#ifdef __cplusplus
}
#endif
