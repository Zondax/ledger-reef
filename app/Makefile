#*******************************************************************************
#  Ledger App
#  (c) 2019 - 2025 Zondax AG
#  (c) 2017 Ledger
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#*******************************************************************************

ifeq ($(BOLOS_SDK),)
$(error BOLOS_SDK is not set)
endif

########################################
#        Mandatory configuration       #
########################################
# Upload targets to configure the devices 
include $(BOLOS_SDK)/Makefile.defines

ifndef COIN
COIN=REEF
endif
$(info COIN  = [$(COIN)])
VARIANT_PARAM=COIN
VARIANT_VALUES=$(COIN)

# Application allowed derivation paths.
# You should request a specific path for your app.
# This serve as an isolation mechanism.
# Most application will have to request a path according to the BIP-0044
# and SLIP-0044 standards.
# If your app needs it, you can specify multiple path by using:
# `PATH_APP_LOAD_PARAMS = "44'/1'" "45'/1'"`
APPPATH = "44'/819'"

ifeq ($(COIN),REEF)
# Main app configuration
APPNAME = "Reef"
ICON_NAME = icon
endif

$(info PATHS LIST = $(APPPATH))
PATH_APP_LOAD_PARAMS = $(APPPATH)

# Application version
include $(CURDIR)/Makefile.version
APPVERSION = "$(APPVERSION_M).$(APPVERSION_N).$(APPVERSION_P)"

# Application source files
APP_SOURCE_PATH += src

# Application icons following guidelines:
# https://developers.ledger.com/docs/embedded-app/design-requirements/#device-icon

DEFAULT_NBGL_ICON_32 = stax_$(ICON_NAME).gif
DEFAULT_NBGL_ICON_64 = stax_$(ICON_NAME)_64.gif

copy_icon:
	cp $(DEFAULT_NBGL_ICON_32) glyphs/icon_stax_32.gif
	cp $(DEFAULT_NBGL_ICON_64) glyphs/icon_stax_64.gif

all: copy_icon

ICON_NANOX = nanox_icon.gif
ICON_NANOSP = nanox_icon.gif
ICON_STAX = stax_icon.gif
ICON_FLEX = flex_icon.gif

# Application allowed derivation curves.
# Possibles curves are: secp256k1, secp256r1, ed25519 and bls12381g1
# If your app needs it, you can specify multiple curves by using:
# `CURVE_APP_LOAD_PARAMS = <curve1> <curve2>`
ifeq ($(COIN), REEF)
CURVE_APP_LOAD_PARAMS = ed25519
endif

INCLUDES_PATH += $(CURDIR)/src/common
INCLUDES_PATH += ../deps/ledger-zxlib/include


########################################
# Application communication interfaces #
########################################
ENABLE_BLUETOOTH = 1
#ENABLE_NFC = 1

########################################
#         NBGL custom features         #
########################################
ENABLE_NBGL_QRCODE = 1
#ENABLE_NBGL_KEYBOARD = 1
#ENABLE_NBGL_KEYPAD = 1

########################################
#          Features disablers          #
########################################
# These advanced settings allow to disable some feature that are by
# default enabled in the SDK `Makefile.standard_app`.
#DISABLE_STANDARD_APP_FILES = 1
#DISABLE_DEFAULT_IO_SEPROXY_BUFFER_SIZE = 1 # To allow custom size declaration
#DISABLE_STANDARD_APP_DEFINES = 1 # Will set all the following disablers
#DISABLE_STANDARD_SNPRINTF = 1
#DISABLE_STANDARD_USB = 1
#DISABLE_STANDARD_WEBUSB = 1
#DISABLE_DEBUG_LEDGER_ASSERT = 1
#DISABLE_DEBUG_THROW = 1

########################################
#        Other configurations          #
########################################
# Set the default value for PRODUCTION_BUILD to 0 if not already defined
PRODUCTION_BUILD ?= 1

# Display whether this is a production build or for internal use
ifeq ($(PRODUCTION_BUILD), 1)
    $(info ************ PRODUCTION_BUILD  = [PRODUCTION BUILD])
else
    $(info ************ PRODUCTION_BUILD  = [INTERNAL USE])
endif

# Add the PRODUCTION_BUILD definition to the compiler flags
DEFINES += PRODUCTION_BUILD=$(PRODUCTION_BUILD)

# Support for nanoS remove so we can use the full parser for all devices
DEFINES += SUBSTRATE_PARSER_FULL

########################################
# Configure devices and permissions
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.devices
# Create installer script
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.installer_script
# Enable logging
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.app_testing
# Call standard app flags
include $(CURDIR)/../deps/ledger-zxlib/makefiles/Makefile.platform

# Use small buffers for NanoX
ifeq ($(TARGET_NAME), TARGET_NANOX)
CFLAGS += -DZXLIB_LIGHT_MODE
endif

$(info TARGET_NAME  = [$(TARGET_NAME)])
$(info ICONNAME  = [$(ICONNAME)])
ifeq ($(ICONNAME),)
$(error ICONNAME is not set)
endif

.PHONY: version
version:
	@echo "v$(APPVERSION)" > app.version
