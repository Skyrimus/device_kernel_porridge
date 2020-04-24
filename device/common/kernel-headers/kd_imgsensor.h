/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _KD_IMGSENSOR_H
#define _KD_IMGSENSOR_H
#include <linux/ioctl.h>
#ifndef ASSERT
#define ASSERT(expr) WARN_ON(! (expr))
#endif
#define IMGSENSORMAGIC 'i'
#define KDIMGSENSORIOC_T_OPEN _IO(IMGSENSORMAGIC, 0)
#define KDIMGSENSORIOC_X_GET_CONFIG_INFO _IOWR(IMGSENSORMAGIC, 5, IMGSENSOR_GET_CONFIG_INFO_STRUCT)
#define KDIMGSENSORIOC_X_GETINFO _IOWR(IMGSENSORMAGIC, 5, ACDK_SENSOR_GETINFO_STRUCT)
#define KDIMGSENSORIOC_X_GETRESOLUTION _IOWR(IMGSENSORMAGIC, 10, ACDK_SENSOR_RESOLUTION_INFO_STRUCT)
#define KDIMGSENSORIOC_X_GETRESOLUTION2 _IOWR(IMGSENSORMAGIC, 10, ACDK_SENSOR_PRESOLUTION_STRUCT)
#define KDIMGSENSORIOC_X_FEATURECONCTROL _IOWR(IMGSENSORMAGIC, 15, ACDK_SENSOR_FEATURECONTROL_STRUCT)
#define KDIMGSENSORIOC_X_CONTROL _IOWR(IMGSENSORMAGIC, 20, ACDK_SENSOR_CONTROL_STRUCT)
#define KDIMGSENSORIOC_T_CLOSE _IO(IMGSENSORMAGIC, 25)
#define KDIMGSENSORIOC_T_CHECK_IS_ALIVE _IO(IMGSENSORMAGIC, 30)
#define KDIMGSENSORIOC_X_SET_DRIVER _IOWR(IMGSENSORMAGIC, 35, SENSOR_DRIVER_INDEX_STRUCT)
#define KDIMGSENSORIOC_X_GET_SOCKET_POS _IOWR(IMGSENSORMAGIC, 40, u32)
#define KDIMGSENSORIOC_X_SET_I2CBUS _IOWR(IMGSENSORMAGIC, 45, u32)
#define KDIMGSENSORIOC_X_RELEASE_I2C_TRIGGER_LOCK _IO(IMGSENSORMAGIC, 50)
#define KDIMGSENSORIOC_X_SET_SHUTTER_GAIN_WAIT_DONE _IOWR(IMGSENSORMAGIC, 55, u32)
#define KDIMGSENSORIOC_X_SET_MCLK_PLL _IOWR(IMGSENSORMAGIC, 60, ACDK_SENSOR_MCLK_STRUCT)
#define KDIMGSENSORIOC_X_GETINFO2 _IOWR(IMGSENSORMAGIC, 65, IMAGESENSOR_GETINFO_STRUCT)
#define KDIMGSENSORIOC_X_SET_CURRENT_SENSOR _IOWR(IMGSENSORMAGIC, 70, u32)
#define KDIMGSENSORIOC_X_SET_GPIO _IOWR(IMGSENSORMAGIC, 75, IMGSENSOR_GPIO_STRUCT)
#define KDIMGSENSORIOC_X_GET_ISP_CLK _IOWR(IMGSENSORMAGIC, 80, u32)
#define KDIMGSENSORIOC_X_GET_CSI_CLK _IOWR(IMGSENSORMAGIC, 85, u32)
#define KDIMGSENSORIOC_DFS_UPDATE _IOWR(IMGSENSORMAGIC, 90, unsigned int)
#define KDIMGSENSORIOC_GET_SUPPORTED_ISP_CLOCKS _IOWR(IMGSENSORMAGIC, 95, IMAGESENSOR_GET_SUPPORTED_ISP_CLK)
#define KDIMGSENSORIOC_GET_CUR_ISP_CLOCK _IOWR(IMGSENSORMAGIC, 100, unsigned int)

#define OV8856_SENSOR_ID 0x8856
#define S5K3M2_SENSOR_ID 0x30D2

#define CAMERA_HW_DEVNAME "kd_camera_hw"

#define SENSOR_DRVNAME_OV8856_MIPI_RAW "ov8856_mipi_raw"
#define SENSOR_DRVNAME_S5K3M2_MIPI_RAW "s5k3m2_mipi_raw"

#define mDELAY(ms) mdelay(ms)
#define uDELAY(us) udelay(us)
#endif