# Inherit from those products. Most specific first.
#$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)

# Set target and base project for flavor build
MTK_TARGET_PROJECT := $(subst full_,,$(TARGET_PRODUCT))
MTK_BASE_PROJECT := $(MTK_TARGET_PROJECT)
MTK_PROJECT_FOLDER := $(LOCAL_PATH)
MTK_TARGET_PROJECT_FOLDER := $(LOCAL_PATH)

# This is where we'd set a backup provider if we had one
#$(call inherit-product, device/sample/products/backup_overlay.mk)
$(call inherit-product, $(LOCAL_PATH)/device.mk)

# set locales & aapt config.
include $(LOCAL_PATH)/ProjectConfig.mk
ifneq (,$(filter OP01%, $(OPTR_SPEC_SEG_DEF)))
  ifeq ($(OP01_COMPATIBLE), yes)
    PRODUCT_LOCALES:=zh_CN en_US zh_TW ja_JP en_GB fr_FR
  else
    PRODUCT_LOCALES:=zh_CN en_US zh_TW
  endif
else ifneq (,$(filter OP09%, $(OPTR_SPEC_SEG_DEF)))
  PRODUCT_LOCALES:=zh_CN zh_HK zh_TW en_US pt_BR pt_PT en_GB fr_FR ja_JP
else
  PRODUCT_LOCALES := en_US zh_CN zh_TW es_ES pt_BR ru_RU fr_FR de_DE tr_TR vi_VN ms_MY in_ID th_TH it_IT ar_EG hi_IN bn_IN ur_PK fa_IR pt_PT nl_NL el_GR hu_HU tl_PH ro_RO cs_CZ ko_KR km_KH iw_IL my_MM pl_PL es_US bg_BG hr_HR lv_LV lt_LT sk_SK uk_UA de_AT da_DK fi_FI nb_NO sv_SE en_GB hy_AM zh_HK et_EE ja_JP kk_KZ sr_RS sl_SI ca_ES
endif


# Set those variables here to overwrite the inherited values.
PRODUCT_MANUFACTURER := Wileyfox
PRODUCT_NAME := full_porridge
PRODUCT_DEVICE := porridge
PRODUCT_MODEL := porridge
PRODUCT_POLICY := android.policy_phone
PRODUCT_BRAND := Wileyfox
BUILD_FINGERPRINT := Wileyfox/Spark/porridge:6.0.1/MMB29X/ZNH0EAS9KB:user/release-keys
PRIVATE_BUILD_DESC := "Spark" "6.0.1" "MMB29X" "ZNH0EAS9KB" "release-keys"



ifeq ($(TARGET_BUILD_VARIANT), eng)
KERNEL_DEFCONFIG ?= porridge_defconfig
else
KERNEL_DEFCONFIG ?= porridge_defconfig
endif
PRELOADER_TARGET_PRODUCT ?= porridge
LK_PROJECT ?= porridge
TRUSTY_PROJECT ?= porridge
