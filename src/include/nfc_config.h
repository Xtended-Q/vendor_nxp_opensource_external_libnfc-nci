/*
 * Copyright 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <string>
#include <vector>

#include <config.h>

/* Configs from libnfc-nci.conf */
#define NAME_NFC_DEBUG_ENABLED "NFC_DEBUG_ENABLED"
#define NAME_POLLING_TECH_MASK "POLLING_TECH_MASK"
#define NAME_NFA_DM_CFG "NFA_DM_CFG"
#define NAME_SCREEN_OFF_POWER_STATE "SCREEN_OFF_POWER_STATE"
#define NAME_NFA_STORAGE "NFA_STORAGE"
#define NAME_UICC_LISTEN_TECH_MASK "UICC_LISTEN_TECH_MASK"
#define NAME_NFA_DM_DISC_DURATION_POLL "NFA_DM_DISC_DURATION_POLL"
#define NAME_AID_FOR_EMPTY_SELECT "AID_FOR_EMPTY_SELECT"
#define NAME_PRESERVE_STORAGE "PRESERVE_STORAGE"
#define NAME_NFA_MAX_EE_SUPPORTED "NFA_MAX_EE_SUPPORTED"
#define NAME_POLL_FREQUENCY "POLL_FREQUENCY"
#define NAME_PRESENCE_CHECK_ALGORITHM "PRESENCE_CHECK_ALGORITHM"
#define NAME_DEVICE_HOST_WHITE_LIST "DEVICE_HOST_WHITE_LIST"
/* Configs from vendor interface */
#define NAME_NFA_POLL_BAIL_OUT_MODE "NFA_POLL_BAIL_OUT_MODE"
#define NAME_NFA_PROPRIETARY_CFG "NFA_PROPRIETARY_CFG"
#define NAME_NFA_AID_BLOCK_ROUTE "NFA_AID_BLOCK_ROUTE"
#define NAME_ISO_DEP_MAX_TRANSCEIVE "ISO_DEP_MAX_TRANSCEIVE"
#define NAME_OFF_HOST_ESE_PIPE_ID "OFF_HOST_ESE_PIPE_ID"
#define NAME_OFF_HOST_SIM_PIPE_ID "OFF_HOST_SIM_PIPE_ID"
#if (NXP_EXTNS == TRUE)
#define NAME_DEFAULT_AID_ROUTE "DEFAULT_AID_ROUTE"
#define NAME_DEFAULT_DESFIRE_ROUTE "DEFAULT_DESFIRE_ROUTE"
#define NAME_DEFAULT_MIFARE_CLT_ROUTE "DEFAULT_MIFARE_CLT_ROUTE"
#define NAME_DEFAULT_AID_PWR_STATE "DEFAULT_AID_PWR_STATE"
#define NAME_DEFAULT_DESFIRE_PWR_STATE "DEFAULT_DESFIRE_PWR_STATE"
#define NAME_DEFAULT_MIFARE_CLT_PWR_STATE "DEFAULT_MIFARE_CLT_PWR_STATE"
#define NAME_NXP_CORE_SCRN_OFF_AUTONOMOUS_ENABLE \
  "NXP_CORE_SCRN_OFF_AUTONOMOUS_ENABLE"
#define NAME_NFA_DM_DISC_NTF_TIMEOUT "NFA_DM_DISC_NTF_TIMEOUT"
#define NAME_HOST_LISTEN_TECH_MASK "HOST_LISTEN_TECH_MASK"
#define NAME_NXP_FWD_FUNCTIONALITY_ENABLE "NXP_FWD_FUNCTIONALITY_ENABLE"
#define NAME_NXP_ESE_LISTEN_TECH_MASK "NXP_ESE_LISTEN_TECH_MASK"
#define NAME_P2P_LISTEN_TECH_MASK "P2P_LISTEN_TECH_MASK"
#define NAME_DEFAULT_OFFHOST_ROUTE "DEFAULT_OFFHOST_ROUTE"
#define NAME_NXP_DEFAULT_NFCEE_TIMEOUT "NXP_DEFAULT_NFCEE_TIMEOUT"
#define NAME_NXP_DEFAULT_NFCEE_DISC_TIMEOUT "NXP_DEFAULT_NFCEE_DISC_TIMEOUT"
#define NAME_NXP_DUAL_UICC_ENABLE "NXP_DUAL_UICC_ENABLE"
#define NAME_NXP_ESE_PWR_MGMT_PROP "NXP_ESE_PWR_MGMT_PROP"
#define NAME_OS_DOWNLOAD_TIMEOUT_VALUE "OS_DOWNLOAD_TIMEOUT_VALUE"
#define NAME_DEFAULT_FELICA_CLT_ROUTE "DEFAULT_FELICA_CLT_ROUTE"
#define NAME_DEFAULT_SYS_CODE_PWR_STATE "DEFAULT_SYS_CODE_PWR_STATE"
#define NAME_DEFAULT_FELICA_CLT_PWR_STATE "DEFAULT_FELICA_CLT_PWR_STATE"
#define NAME_NXP_HCEF_CMD_RSP_TIMEOUT_VALUE "NXP_HCEF_CMD_RSP_TIMEOUT_VALUE"
#define NAME_NXP_ALLOW_WIRED_IN_MIFARE_DESFIRE_CLT \
  "NXP_ALLOW_WIRED_IN_MIFARE_DESFIRE_CLT"
#define NAME_NXP_CP_TIMEOUT "NXP_CP_TIMEOUT"
#define NAME_NXP_NFCC_RF_FIELD_EVENT_TIMEOUT "NXP_NFCC_RF_FIELD_EVENT_TIMEOUT"
#define NAME_NXP_WM_MAX_WTX_COUNT       "NXP_WM_MAX_WTX_COUNT"
#define NAME_NXP_NFCC_STANDBY_TIMEOUT "NXP_NFCC_STANDBY_TIMEOUT"
#define NAME_NXP_NFCC_PASSIVE_LISTEN_TIMEOUT "NXP_NFCC_PASSIVE_LISTEN_TIMEOUT"
#define NAME_CHECK_DEFAULT_PROTO_SE_ID "NXP_CHECK_DEFAULT_PROTO_SE_ID"
#endif

class NfcConfig {
 public:
  static bool hasKey(const std::string& key);
  static std::string getString(const std::string& key);
  static std::string getString(const std::string& key,
                               std::string default_value);
  static unsigned getUnsigned(const std::string& key);
  static unsigned getUnsigned(const std::string& key, unsigned default_value);
  static std::vector<uint8_t> getBytes(const std::string& key);
  static void clear();

 private:
  void loadConfig();
  static NfcConfig& getInstance();
  NfcConfig();

  ConfigFile config_;
};
