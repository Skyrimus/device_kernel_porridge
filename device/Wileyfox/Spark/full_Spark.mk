# Inherit for devices that support 64-bit primary and 32-bit secondary zygote startup script
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)

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

PRODUCT_LOCALES := en_US ru_RU uk_UA de_DE be_BY en_GB kk_KZ



# Set those variables here to overwrite the inherited values.
PRODUCT_MANUFACTURER := Wileyfox
PRODUCT_NAME := full_Spark
PRODUCT_DEVICE := $(strip $(MTK_BASE_PROJECT))
PRODUCT_MODEL := porridge
PRODUCT_POLICY := android.policy_phone
PRODUCT_BRAND := Wileyfox
BUILD_FINGERPRINT := Wileyfox/Spark/Spark:6.0.1/MMB29X/ZNH0EAS9KB:user/release-keys
PRIVATE_BUILD_DESC := "Spark" "6.0.1" "MMB29X" "ZNH0EAS9KB" "release-keys"



ifeq ($(TARGET_BUILD_VARIANT), eng)
#KERNEL_DEFCONFIG ?= Spark_defconfig
KERNEL_DEFCONFIG ?= porridge_defconfig
else
#KERNEL_DEFCONFIG ?= Spark_defconfig
KERNEL_DEFCONFIG ?= porridge_defconfig
endif
PRELOADER_TARGET_PRODUCT ?= Spark
LK_PROJECT ?= Spark
TRUSTY_PROJECT ?= Spark
