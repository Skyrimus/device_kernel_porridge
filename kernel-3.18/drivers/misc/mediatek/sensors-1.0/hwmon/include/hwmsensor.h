/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

/*
* Copyright(C)2014 MediaTek Inc.
* Modification based on code covered by the below mentioned copyright
* and/or permission notice(S).
*/


#ifndef __HWMSENSOR_H__
#define __HWMSENSOR_H__

#include <linux/ioctl.h>
#include <linux/types.h>
#ifdef CONFIG_COMPAT
#include <linux/compat.h>
#endif
/* follow google default sensor type */
#define SENSOR_TYPE_ACCELEROMETER					1
#define SENSOR_TYPE_MAGNETIC_FIELD					2
#define SENSOR_TYPE_ORIENTATION						3
#define SENSOR_TYPE_GYROSCOPE						4
#define SENSOR_TYPE_LIGHT							5
#define SENSOR_TYPE_PRESSURE						6
#define SENSOR_TYPE_TEMPERATURE						7
#define SENSOR_TYPE_PROXIMITY						8
#define SENSOR_TYPE_GRAVITY							9
#define SENSOR_TYPE_LINEAR_ACCELERATION				10
#define SENSOR_TYPE_ROTATION_VECTOR					11
#define	SENSOR_TYPE_RELATIVE_HUMIDITY				12
#define SENSOR_TYPE_AMBIENT_TEMPERATURE				13
#define SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED		14
#define SENSOR_TYPE_GAME_ROTATION_VECTOR			15
#define SENSOR_TYPE_GYROSCOPE_UNCALIBRATED			16
#define SENSOR_TYPE_SIGNIFICANT_MOTION				17
#define SENSOR_TYPE_STEP_DETECTOR					18
#define SENSOR_TYPE_STEP_COUNTER					19
#define SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR		20
#define SENSOR_TYPE_HEART_RATE						21
#define SENSOR_TYPE_TILT_DETECTOR					22
#define SENSOR_TYPE_WAKE_GESTURE					23
#define SENSOR_TYPE_GLANCE_GESTURE					24
#define SENSOR_TYPE_PICK_UP_GESTURE					25
#define SENSOR_TYPE_WRIST_TILT_GESTURE				26
#define SENSOR_TYPE_DEVICE_ORIENTATION              27
#define SENSOR_TYPE_POSE_6DOF                       28
#define SENSOR_TYPE_STATIONARY_DETECT               29
#define SENSOR_TYPE_MOTION_DETECT                   30
#define SENSOR_TYPE_HEART_BEAT                      31
#define SENSOR_TYPE_DYNAMIC_SENSOR_META             32
#define SENSOR_TYPE_ADDITIONAL_INFO                 33
#define SENSOR_TYPE_LOW_LATENCY_OFFBODY_DETECT		34
#define SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED		35


/* follow mtk add sensor type */
#define SENSOR_TYPE_PEDOMETER						55
#define SENSOR_TYPE_IN_POCKET						56
#define SENSOR_TYPE_ACTIVITY						57
#define SENSOR_TYPE_PDR								58
#define SENSOR_TYPE_FREEFALL						59
#define SENSOR_TYPE_FLAT							60
#define SENSOR_TYPE_FACE_DOWN						61
#define SENSOR_TYPE_SHAKE							62
#define SENSOR_TYPE_BRINGTOSEE						63
#define SENSOR_TYPE_ANSWER_CALL						64
#define SENSOR_TYPE_GEOFENCE						65
#define SENSOR_TYPE_FLOOR_COUNTER					66
#define SENSOR_TYPE_EKG								67
#define SENSOR_TYPE_PPG1							68
#define SENSOR_TYPE_PPG2							69
/* end sensor type */
/*---------------------------------------------------------------------------*/
#define ID_BASE							0
/* follow google default sensor ID */
#define ID_ACCELEROMETER				(ID_BASE + SENSOR_TYPE_ACCELEROMETER - 1)
#define ID_MAGNETIC						(ID_BASE + SENSOR_TYPE_MAGNETIC_FIELD - 1)
#define ID_ORIENTATION					(ID_BASE + SENSOR_TYPE_ORIENTATION - 1)
#define ID_GYROSCOPE					(ID_BASE + SENSOR_TYPE_GYROSCOPE - 1)
#define ID_LIGHT						(ID_BASE + SENSOR_TYPE_LIGHT - 1)
#define ID_PRESSURE						(ID_BASE + SENSOR_TYPE_PRESSURE - 1)
#define ID_TEMPRERATURE					(ID_BASE + SENSOR_TYPE_TEMPERATURE - 1)
#define ID_PROXIMITY					(ID_BASE + SENSOR_TYPE_PROXIMITY - 1)
#define ID_GRAVITY						(ID_BASE + SENSOR_TYPE_GRAVITY - 1)
#define ID_LINEAR_ACCELERATION			(ID_BASE + SENSOR_TYPE_LINEAR_ACCELERATION - 1)
#define ID_ROTATION_VECTOR				(ID_BASE + SENSOR_TYPE_ROTATION_VECTOR - 1)
#define ID_RELATIVE_HUMIDITY			(ID_BASE + SENSOR_TYPE_RELATIVE_HUMIDITY - 1)
#define ID_AMBIENT_TEMPERATURE			(ID_BASE + SENSOR_TYPE_AMBIENT_TEMPERATURE - 1)
#define ID_MAGNETIC_UNCALIBRATED		(ID_BASE + SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED - 1)
#define ID_GAME_ROTATION_VECTOR			(ID_BASE + SENSOR_TYPE_GAME_ROTATION_VECTOR - 1)
#define ID_GYROSCOPE_UNCALIBRATED		(ID_BASE + SENSOR_TYPE_GYROSCOPE_UNCALIBRATED - 1)
#define ID_SIGNIFICANT_MOTION			(ID_BASE + SENSOR_TYPE_SIGNIFICANT_MOTION - 1)
#define ID_STEP_DETECTOR				(ID_BASE + SENSOR_TYPE_STEP_DETECTOR - 1)
#define ID_STEP_COUNTER					(ID_BASE + SENSOR_TYPE_STEP_COUNTER - 1)
#define ID_GEOMAGNETIC_ROTATION_VECTOR	(ID_BASE + SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR - 1)
#define ID_HEART_RATE					(ID_BASE + SENSOR_TYPE_HEART_RATE - 1)
#define ID_TILT_DETECTOR				(ID_BASE + SENSOR_TYPE_TILT_DETECTOR - 1)
#define ID_WAKE_GESTURE					(ID_BASE + SENSOR_TYPE_WAKE_GESTURE - 1)
#define ID_GLANCE_GESTURE				(ID_BASE + SENSOR_TYPE_GLANCE_GESTURE - 1)
#define ID_PICK_UP_GESTURE				(ID_BASE + SENSOR_TYPE_PICK_UP_GESTURE - 1)
#define ID_WRIST_TITL_GESTURE			(ID_BASE + SENSOR_TYPE_WRIST_TILT_GESTURE - 1)
#define ID_DEVICE_ORIENTATION			(ID_BASE + SENSOR_TYPE_DEVICE_ORIENTATION - 1)
#define ID_POSE_6DOF					(ID_BASE + SENSOR_TYPE_POSE_6DOF - 1)
#define ID_STATIONARY_DETECT			(ID_BASE + SENSOR_TYPE_STATIONARY_DETECT - 1)
#define ID_MOTION_DETECT				(ID_BASE + SENSOR_TYPE_MOTION_DETECT - 1)
#define ID_HEART_BEAT					(ID_BASE + SENSOR_TYPE_HEART_BEAT - 1)
#define ID_DYNAMIC_SENSOR_META			(ID_BASE + SENSOR_TYPE_DYNAMIC_SENSOR_META - 1)
#define ID_ADDITIONAL_INFO				(ID_BASE + SENSOR_TYPE_ADDITIONAL_INFO - 1)
#define ID_LOW_LATENCY_OFFBODY_DETECT	(ID_BASE + SENSOR_TYPE_LOW_LATENCY_OFFBODY_DETECT - 1)
#define ID_ACCELEROMETER_UNCALIBRATED	(ID_BASE + SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED - 1)


/* follow mtk add sensor ID */
#define ID_PEDOMETER                    (ID_BASE + SENSOR_TYPE_PEDOMETER - 1)
#define ID_IN_POCKET                    (ID_BASE + SENSOR_TYPE_IN_POCKET - 1)
#define ID_ACTIVITY                     (ID_BASE + SENSOR_TYPE_ACTIVITY - 1)
#define ID_PDR							(ID_BASE + SENSOR_TYPE_PDR - 1)
#define ID_FREEFALL						(ID_BASE + SENSOR_TYPE_FREEFALL - 1)
#define ID_FLAT							(ID_BASE + SENSOR_TYPE_FLAT - 1)
#define ID_FACE_DOWN                    (ID_BASE + SENSOR_TYPE_FACE_DOWN - 1)
#define ID_SHAKE                        (ID_BASE + SENSOR_TYPE_SHAKE - 1)
#define ID_BRINGTOSEE                   (ID_BASE + SENSOR_TYPE_BRINGTOSEE - 1)
#define ID_ANSWER_CALL                  (ID_BASE + SENSOR_TYPE_ANSWER_CALL - 1)
#define ID_GEOFENCE                     (ID_BASE + SENSOR_TYPE_GEOFENCE - 1)
#define ID_FLOOR_COUNTER                     (ID_BASE + SENSOR_TYPE_FLOOR_COUNTER - 1)
#define ID_EKG                          (ID_BASE+SENSOR_TYPE_EKG-1)
#define ID_PPG1                         (ID_BASE+SENSOR_TYPE_PPG1-1)
#define ID_PPG2                         (ID_BASE+SENSOR_TYPE_PPG2-1)
/* end sensor ID */
#define ID_SENSOR_MAX_HANDLE			(ID_BASE + SENSOR_TYPE_PPG2)
#define ID_NONE							(ID_SENSOR_MAX_HANDLE + 1)
#define ID_OFFSET                       (1)
#define ID_SCP_MAX_SENSOR_TYPE			(69)

#define MAX_ANDROID_SENSOR_NUM			(ID_SENSOR_MAX_HANDLE + 1)
#define MAX_SENSOR_DATA_UPDATE_ONCE     (20)

#define C_MAX_HWMSEN_EVENT_NUM          4

#define ACC_PL_DEV_NAME                 "m_acc_pl"
#define ACC_INPUTDEV_NAME               "m_acc_input"
#define ACC_MISC_DEV_NAME               "m_acc_misc"
#define MAG_PL_DEV_NAME                 "m_mag_pl"
#define MAG_INPUTDEV_NAME               "m_mag_input"
#define MAG_MISC_DEV_NAME               "m_mag_misc"
#define UNCALI_MAG_PL_DEV_NAME                 "m_uncali_mag_pl"
#define UNCALI_MAG_INPUTDEV_NAME               "m_uncali_mag_input"
#define UNCALI_MAG_MISC_DEV_NAME               "m_uncali_mag_misc"
#define UNCALI_GYRO_PL_DEV_NAME         "m_uncali_gyro_pl"
#define UNCALI_GYRO_INPUTDEV_NAME       "m_uncali_gyro_input"
#define UNCALI_GYRO_MISC_DEV_NAME       "m_uncali_gyro_misc"
#define GYRO_PL_DEV_NAME                "m_gyro_pl"
#define GYRO_INPUTDEV_NAME              "m_gyro_input"
#define GYRO_MISC_DEV_NAME              "m_gyro_misc"
#define ALSPS_PL_DEV_NAME               "m_alsps_pl"
#define ALSPS_INPUTDEV_NAME             "m_alsps_input"
#define ALS_MISC_DEV_NAME             "m_als_misc"
#define PS_MISC_DEV_NAME             "m_ps_misc"
#define BARO_PL_DEV_NAME                "m_baro_pl"
#define BARO_INPUTDEV_NAME              "m_baro_input"
#define BARO_MISC_DEV_NAME              "m_baro_misc"
#define HMDY_PL_DEV_NAME		"m_hmdy_pl"
#define HMDY_INPUTDEV_NAME		"m_hmdy_input"
#define HMDY_MISC_DEV_NAME		"m_hmdy_misc"

#define STEP_C_PL_DEV_NAME                "m_step_c_pl"
#define STEP_C_INPUTDEV_NAME              "m_step_c_input"
#define STEP_C_MISC_DEV_NAME              "m_step_c_misc"

#define INPK_PL_DEV_NAME                "m_inpk_pl"
#define INPK_INPUTDEV_NAME              "m_inpk_input"
#define INPK_MISC_DEV_NAME              "m_inpk_misc"

#define SHK_PL_DEV_NAME                "m_shk_pl"
#define SHK_INPUTDEV_NAME              "m_shk_input"
#define SHK_MISC_DEV_NAME              "m_shk_misc"

#define FDN_PL_DEV_NAME                "m_fdn_pl"
#define FDN_INPUTDEV_NAME              "m_fdn_input"
#define FDN_MISC_DEV_NAME              "m_fdn_misc"

#define PKUP_PL_DEV_NAME                "m_pkup_pl"
#define PKUP_INPUTDEV_NAME              "m_pkup_input"
#define PKUP_MISC_DEV_NAME              "m_pkup_misc"

#define ACT_PL_DEV_NAME                "m_act_pl"
#define ACT_INPUTDEV_NAME              "m_act_input"
#define ACT_MISC_DEV_NAME              "m_act_misc"

#define PDR_PL_DEV_NAME                "m_pdr_pl"
#define PDR_INPUTDEV_NAME              "m_pdr_input"
#define PDR_MISC_DEV_NAME              "m_pdr_misc"

#define HRM_PL_DEV_NAME                "m_hrm_pl"
#define HRM_INPUTDEV_NAME              "m_hrm_input"
#define HRM_MISC_DEV_NAME              "m_hrm_misc"

#define TILT_PL_DEV_NAME               "m_tilt_pl"
#define TILT_INPUTDEV_NAME             "m_tilt_input"
#define TILT_MISC_DEV_NAME             "m_tilt_misc"

#define WAG_PL_DEV_NAME                "m_wag_pl"
#define WAG_INPUTDEV_NAME              "m_wag_input"
#define WAG_MISC_DEV_NAME              "m_wag_misc"

#define GLG_PL_DEV_NAME                "m_glg_pl"
#define GLG_INPUTDEV_NAME              "m_glg_input"
#define GLG_MISC_DEV_NAME              "m_glg_misc"

#define ANSWERCALL_PL_DEV_NAME          "m_ancall_pl"
#define ANSWERCALL_INPUTDEV_NAME        "m_ancall_input"
#define ANSWERCALL_MISC_DEV_NAME        "m_ancall_misc"

#define TEMP_PL_DEV_NAME               "m_temp_pl"
#define TEMP_INPUTDEV_NAME             "m_temp_input"
#define TEMP_MISC_DEV_NAME             "m_temp_misc"

#define BATCH_PL_DEV_NAME              "m_batch_pl"
#define BATCH_INPUTDEV_NAME            "m_batch_input"
#define BATCH_MISC_DEV_NAME            "m_batch_misc"

#define BTS_PL_DEV_NAME                "m_bts_pl"
#define BTS_INPUTDEV_NAME              "m_bts_input"
#define BTS_MISC_DEV_NAME              "m_bts_misc"

#define GRV_PL_DEV_NAME                "m_grv_pl"
#define GRV_INPUTDEV_NAME              "m_grv_input"
#define GRV_MISC_DEV_NAME              "m_grv_misc"

#define GMRV_PL_DEV_NAME               "m_gmrv_pl"
#define GMRV_INPUTDEV_NAME             "m_gmrv_input"
#define GMRV_MISC_DEV_NAME             "m_gmrv_misc"

#define GRAV_PL_DEV_NAME               "m_grav_pl"
#define GRAV_INPUTDEV_NAME             "m_grav_input"
#define GRAV_MISC_DEV_NAME             "m_grav_misc"

#define LA_PL_DEV_NAME                 "m_la_pl"
#define LA_INPUTDEV_NAME               "m_la_input"
#define LA_MISC_DEV_NAME               "m_la_misc"

#define RV_PL_DEV_NAME                 "m_rv_pl"
#define RV_INPUTDEV_NAME               "m_rv_input"
#define RV_MISC_DEV_NAME               "m_rv_misc"

#define FUSION_PL_DEV_NAME                 "m_fusion_pl"
#define FUSION_INPUTDEV_NAME               "m_fusion_input"
#define FUSION_MISC_DEV_NAME               "m_fusion_misc"

#define FREEFALL_PL_DEV_NAME                 "m_frfl_pl"
#define FREEFALL_INPUTDEV_NAME               "m_frfl_input"
#define FREEFALL_MISC_DEV_NAME               "m_frfl_misc"

#define PEDO_PL_DEV_NAME                 "m_pedo_pl"
#define PEDO_INPUTDEV_NAME               "m_pedo_input"
#define PEDO_MISC_DEV_NAME               "m_pedo_misc"

#define SITU_PL_DEV_NAME                 "m_situ_pl"
#define SITU_INPUTDEV_NAME               "m_situ_input"
#define SITU_MISC_DEV_NAME               "m_situ_misc"

#define BIO_MISC_DEV_NAME               "m_bio_misc"

struct hwm_sensor_data {
	/* sensor identifier */
	int sensor;
	/* sensor values */
	union {
		int values[6];
		uint8_t probability[12];
	};
	/* sensor values divide */
	uint32_t value_divide;
	/* sensor accuracy */
	int8_t status;
	/* whether updata? */
	int update;
	/* time is in nanosecond */
	int64_t time;

	uint32_t reserved;
};

/**
 * status of each sensor
 */

#define SENSOR_DELAY	0X01
#define	SENSOR_ENABLE	0X02
#define	SENSOR_GET_DATA	0X04

#define SENSOR_STATUS_UNRELIABLE        0
#define SENSOR_STATUS_ACCURACY_LOW      1
#define SENSOR_STATUS_ACCURACY_MEDIUM   2
#define SENSOR_STATUS_ACCURACY_HIGH     3

#define GRAVITY_EARTH_1000           9807	/* about (9.80665f)*1000 */

#endif
