# Copyright Statement:
#
# This software/firmware and related documentation ("MediaTek Software") are
# protected under relevant copyright laws. The information contained herein
# is confidential and proprietary to MediaTek Inc. and/or its licensors.
# Without the prior written permission of MediaTek inc. and/or its licensors,
# any reproduction, modification, use or disclosure of MediaTek Software,
# and information contained herein, in whole or in part, shall be strictly prohibited.

# MediaTek Inc. (C) 2010. All rights reserved.
#
# BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
# THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
# CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
# SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
# STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
# CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
# The following software/firmware and/or related documentation ("MediaTek Software")
# have been modified by MediaTek Inc. All revisions are subject to any receiver's
# applicable license agreements with MediaTek Inc.

################################################################################
#
################################################################################

LOCAL_PATH := $(call my-dir)

################################################################################
#
################################################################################
include $(CLEAR_VARS)

ifeq ($(strip $(MTK_GMO_RAM_OPTIMIZE)), yes)
LOCAL_CFLAGS += -DCUSTOM_GMO_RAM_OPTIMIZE=1
else
LOCAL_CFLAGS += -DCUSTOM_GMO_RAM_OPTIMIZE=0
endif

#-----------------------------------------------------------
$(call config-custom-folder,hal:hal)

#-----------------------------------------------------------
LOCAL_SRC_FILES +=

#-----------------------------------------------------------
LOCAL_C_INCLUDES +=

#-----------------------------------------------------------
LOCAL_STATIC_LIBRARIES +=
#
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.camera
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.camera.3a
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.flashlight
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.lens
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.imgsensor
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.imgsensor.core
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.eeprom
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.cam_cal
ifeq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6735m mt6737m))
LOCAL_WHOLE_STATIC_LIBRARIES += libcameracustom.pd_buf_mgr
endif
#-----------------------------------------------------------
LOCAL_SHARED_LIBRARIES += liblog
LOCAL_SHARED_LIBRARIES += libcutils
ifeq (,$(filter $(strip $(TARGET_BOARD_PLATFORM)), mt6735m mt6737m))
LOCAL_SHARED_LIBRARIES += libSonyIMX230PdafLibrary
endif
#-----------------------------------------------------------
#LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libcameracustom
LOCAL_PROPRIETARY_MODULE := true
LOCAL_MODULE_OWNER := mtk

ifeq ($(strip $(TARGET_BOARD_PLATFORM)),mt6735m)
#LOCAL_MULTILIB := 32
endif
#-----------------------------------------------------------
include $(MTK_SHARED_LIBRARY)


################################################################################
#
################################################################################
include $(CLEAR_VARS)
include $(call all-makefiles-under,$(LOCAL_PATH))

