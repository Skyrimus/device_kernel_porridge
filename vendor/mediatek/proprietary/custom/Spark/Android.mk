LOCAL_PATH:= $(call my-dir)
ifeq ($(MTK_PROJECT), Spark)
include $(call all-makefiles-under,$(LOCAL_PATH))
endif
