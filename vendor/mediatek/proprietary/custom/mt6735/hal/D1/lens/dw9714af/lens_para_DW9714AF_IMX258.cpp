/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
 *     TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/
#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>

#include "camera_custom_nvram.h"
#include "camera_custom_lens.h"

const NVRAM_LENS_PARA_STRUCT DW9714AF_IMX258_LENS_PARA_DEFAULT_VALUE =
{
    //Version
    NVRAM_CAMERA_LENS_FILE_VERSION,

    // Focus Range NVRAM
    {0, 1023},

    // AF NVRAM
    {
        // ------------------------------ sAF_Coef -----------------------------------------
        {
            {
                303, // i4Offset
                17,  // i4NormalNum
                17,  // i4MacroNum
                1,   // i4InfIdxOffset
                1,   // i4MacroIdxOffset          
                {
                    0, 10, 20, 35, 50, 65, 85, 105, 125, 145,
                    175, 205, 235, 265, 295, 325, 365, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                }
               
            },
            12,//15, // i4THRES_MAIN;
            8,//10, // i4THRES_SUB;      
            1,  // i4AFC_FAIL_CNT;                 
            0,  // i4FAIL_POS;

            4,  // i4INIT_WAIT;
            {500, 500, 500, 500, 500}, // i4FRAME_WAIT
            0,  // i4DONE_WAIT;         
        },                             
        // ------------------------------- sVAFC_Coef --------------------------------------------
        {
            {
                303, // i4Offset
                17,  // i4NormalNum
                17,  // i4MacroNum
                1,   // i4InfIdxOffset
                1,   // i4MacroIdxOffset          
                {
                    0, 10, 20, 35, 50, 65, 85, 105, 125, 145,
                    175, 205, 235, 265, 295, 325, 365, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                }
            },
            12,//15, // i4THRES_MAIN;
            8,//10, // i4THRES_SUB;            
            1,  // i4AFC_FAIL_CNT;         
            -1, // i4FAIL_POS;

            4,  // i4INIT_WAIT;
            {  0,  0, 500, 500, 500}, // i4FRAME_WAIT
            0,  // i4DONE_WAIT;                        
        },
        // -------------------- sAF_TH ---------------------
        {
            8, // i4ISONum;
            {100, 150, 200, 300, 400, 600, 800, 1600},
        
            // SGG1~7
            {20, 20, 19, 19, 18, 17, 17, 10,
             29, 29, 29, 28, 28, 27, 26, 18,
             43, 42, 42, 41, 41, 40, 40, 31,
             62, 61, 61, 60, 60, 59, 59, 50,
             89, 88, 88, 87, 87, 86, 86, 77,
             126, 126, 126, 126, 125, 125, 124, 117,
             180, 180, 180, 180, 179, 179, 179, 175},
        
            // horizontal FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // horizontal FV min. threshold
            {3500, 3500, 3500, 3500, 4000, 4500, 5000, 5000},
        
            // horizontal FV threshold
            //{4, 4, 5, 6, 6, 8, 9, 12},
            {1, 1, 1, 1, 1, 2, 3, 3},
        
            // vertical FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // vertical FV min. threshold
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // vertical FV threshold
            //{7, 8, 9, 10, 12, 14, 16, 21},
            {1, 1, 1, 1, 1, 2, 3, 3},

        },
        // ------------------- sZSDAF_TH -----------------------------------
        {
            8, // i4ISONum;
            {100, 150, 200, 300, 400, 600, 800, 1600},
        
            // SGG1~7
            {21, 21, 21, 21, 20, 20, 20, 10,
             31, 30, 30, 30, 30, 30, 29, 18,
             44, 44, 44, 43, 43, 43, 43, 30,
             63, 63, 63, 62, 62, 62, 62, 49,
             89, 89, 89, 89, 89, 89, 88, 77,
             127, 127, 127, 127, 127, 127, 126, 117,
             181, 180, 180, 180, 180, 180, 180, 174},
        
            // horizontal FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // horizontal FV min. threshold
            {3500, 3500, 3500, 3500, 4000, 4500, 5000, 5000},
        
            // horizontal FV threshold
            //{2, 3, 3, 3, 3, 4, 4, 6},
            {1, 1, 1, 1, 1, 2, 3, 3},
        
            // vertical FV baseline
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // vertical FV min. threshold
            {0, 0, 0, 0, 0, 0, 0, 0},
        
            // vertical FV threshold
            //{4, 5, 5, 6, 6, 7, 7, 9},
            {1, 1, 1, 1, 1, 2, 3, 3},

        },
        // -------------------- sVID_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];       
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];            
        },
        // -------------------- sVID1_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];       
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];              
        },
        // -------------------- sVID2_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];       
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                
        },
        // -------------------- sIHDR_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];        
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                   
        },
        // -------------------- sREV1_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];       
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                
        },
        // -------------------- sREV2_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];       
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                   
        },        
        // -------------------- sREV3_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];        
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                 
        },
        // -------------------- sREV4_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];        
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                   
        },
        // -------------------- sREV5_AF_TH ---------------------
        {
            0, // i4ISONum;
            {0,0,0,0,0,0,0,0}, // i4ISO[ISO_MAX_NUM];        
            {{0, 0, 0, 0, 0, 0, 0, 0},// SGG1~7
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 0, 0}},
            {0,0,0,0,0,0,0,0}, // i4FV_DC[ISO_MAX_NUM];
            {0, 0, 0, 0, 0, 0, 0, 0},// i4MIN_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4HW_TH[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4FV_DC2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0}, // i4MIN_TH2[ISO_MAX_NUM];
            {0,0,0,0,0,0,0,0} // i4HW_TH2[ISO_MAX_NUM];                 
        },

        // --- Common use ---        
        1,  // i4ReadOTP; 				// 0: disable, 1:enable           
        3,  // i4StatGain;    
        0,  // i4LV_THRES;         
        299,// i4InfPos;
        33, // i4FRAME_TIME    
        {0, 50, 150, 250, 350},     // back jump
        500,//i4BackJumpPos

        20, //i4AFC_STEP_SIZE;
        18, // i4SPOT_PERCENT_W;        // AFC window location
        24, // i4SPOT_PERCENT_H;        // AFC window location
        0,  // i4CHANGE_CNT_DELTA;    
                                          
        1,  // i4AFS_STEP_MIN_ENABLE;
        4,  // i4AFS_STEP_MIN_NORMAL;
        4,  // i4AFS_STEP_MIN_MACRO;        

        5,  // i4FIRST_FV_WAIT;
        12, // i4FV_1ST_STABLE_THRES;        
        10000,  // i4FV_1ST_STABLE_OFFSET;
        6,  // i4FV_1ST_STABLE_NUM;                        
        6,  // i4FV_1ST_STABLE_CNT; 
        50, // i4FV_SHOCK_THRES;
        30000, // i4FV_SHOCK_OFFSET;
        5,  // i4FV_VALID_CNT;
        20, // i4FV_SHOCK_FRM_CNT;
        5,  // i4FV_SHOCK_CNT;          

        // --- FaceAF ---
        90, // i4FDWinPercent;
        40, // i4FDSizeDiff;
        15, // i4FD_DETECT_CNT;
        5,  // i4FD_NONE_CNT; 

        // --- AFv1.1/AFv1.2 ---
        1,  // i4LeftSearchEnable;       //[0] 0:disable, 1:enable
        0,  // i4LeftJumpStep;           //[1] when disable left peak search, left step= 3 + i4LeftJumpStep
        0,  // No use
        0,  // i4AfDoneDelay;            //[3] AF done happen delay count
        0,  // i4VdoAfDoneDelay;         //[3] AF done happen delay count
        0,  // i4ZoomInWinChg;           //[4] enable AF window change with Zoom-in  
        1,  // i4SensorEnable;           //[5] AF use sensor lister => 0:disable, 1:enable
        0, // i4PostureComp;            //[6] post comp max offset => 0:disable, others:enable
        3,  // i4SceneMonitorLevel;      //[7] scenechange enhancement level => 0:original, 1~3:from stable to sensitive
        1,  // i4VdoSceneMonitorLevel;   //[7] scenechange enhancement level => 0:original, 1~3:from stable to sensitive

        // Scene Monitor 
        // {Type, Off, Thr{by level}, Cnt{by level}}        
        // Type: 1 is &&, 0 is ||
        // Off : value, min=0 is more sensitive
        // Thr : percentage(value for gyro/acce), min=0 is more sensitive 
        // Cnt : value, max=30 is more stable
        // preview params
        {1,                                       // FV 0:disable, 1:enable
         0,10000,{ 40, 40, 30}, { 15, 10, 8},   //    chg; chgT lower to sensitive, chgN bigger to stable   
         1, 5000,{ 25, 25, 30}, { 10,  7,  6} }, //    stb; stbT should fix, stbN bigger to stable         
        {1,                                       // GS 0:disable, 1:enable
         0,   15, { 100, 100, 100}, { 15, 10, 10}, //{ 20, 20, 15}, { 15, 10, 10},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, {  5, 10, 10}, { 10,  7,  5} }, //    stb; stbT should fix, stbN bigger to stable        
        {1,                                       // AEB 0:disable, 1:enable
         0,   15, { 30, 30, 25}, { 33, 30, 8},   //    chg; chgT lower to sensitive, chgN bigger to stable  
         1,    5, { 10, 10, 10}, { 10,  7,  6} }, //    stb; stbT should fix, stbN bigger to stable           
        {1,                                       // GYRO 0:disable, 1:enable
         0,    0, { 40, 40, 40}, {  5,  3,  3},   //    chg; off=0, chgT lower to sensitive, chgN bigger to stable  
         1,    0, { 10, 10, 10}, { 10,  7,  5} }, //    stb; off=0, stbT should fix, stbN bigger to stable      
        {1,                                       // ACCE 0:disable, 1:enable
         0,    0, { 80, 80, 60}, { 15, 12, 8},   //    chg; off=0, chgT lower to sensitive, chgN bigger to stable  
         1,    0, { 50, 50, 50}, { 10,  7,  5} }, //    stb; off=0, stbT should fix, stbN bigger to stable    
        // video params
        {1,                                       // vdo FV
         0,10000,{ 40, 40, 30}, { 20, 15, 15},   //    chg; chgT lower to sensitive, chgN bigger to stable   
         1, 5000, { 20, 20, 20}, { 20, 15, 10} },//    stb; stbT should fix, stbN bigger to stable         
        {1,                                       // vdo GS
         0,   15, { 20, 20, 15}, { 28, 25, 25},   //    chg; chgT lower to sensitive, chgN bigger to stable
         1,    5, {  5,  5,  5}, { 15, 13, 10} }, //    stb            
        {1,                                       // vdo AEB
         0,   15, { 30, 30, 25}, { 33, 30, 30},   //    chg
         1,    5, { 10, 10, 10}, { 15, 13, 10} }, //    stb            
        {1,                                       // vdo GYRO
         0,    0, { 40, 40, 20}, {  7,  5,  5},   //    chg; video mode cnt > normal mode cnt for stable
         1,    0, { 10, 10, 10}, { 15, 13, 10} }, //    stb; video mode cnt > normal mode cnt for stable  
        {1,                                       // vdp ACCE 
         0,    0, { 80, 80, 60}, { 15, 12, 12},   //    chg; video mode cnt > normal mode cnt for stable  
         1,    0, { 50, 50, 50}, { 13, 13, 10} }, //    stb; video mode cnt > normal mode cnt for stable  

        // --- AFv2.0 ---     
        1,  // i4FvExtractEnable;           // 0:disable, 1:enable (for faceAF)
        40, // i4FvExtractThr               // percentage, fixed
        
        1,  // i4DampingCompEnable;         // 0:disable, 1:enable
        {8, 15, 23, 31, 39, 46, 54, 62, 69, 77, 0, 0, 0, 0, 0},        // { step1, step2, ... , step 15(atmost) }
        {
            {-2,-4,-4,-6,-5,-5,-13,-8,-10,-20, 0, 0, 0, 0, 0},// prerun0:{rComp1, rComp2, ..., rComp15(atmost)}
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}   // prerun1:{rComp1, rComp2, ..., rComp15(atmost)}
        },
        {
            {2,4,4,6,5,5,13,8,10,20, 0, 0, 0, 0, 0},          // prerun0:{lComp1, lComp2, ..., lComp15(atmost)}
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}   // prerun1:{lComp1, lComp2, ..., lComp15(atmost)}
        },

        1,  // i4DirSelectEnable;           // 0:disable, 1:enable
        -1, // i4InfDir;                    // 1:right, -1:left, 2:reverse, 0:keep
        -1, // i4MidDir;                    // "
        -1, // i4MacDir;                    // "
        40, // i4RatioInf;                  // below % of tableLength belongs to INF
        70, // i4RatioMac;                  // above % of tableLength belongs to MAC ; should be larger than i4RatioInf                
        1,  // i4StartBoundEnable;          // 0:disable, 1:enable
        3,  // i4StartCamCAF;               // 0:keep current, -1:force to INF, X:set to boundary if within X steps
        3,  // i4StartCamTAF;               // "
        0,  // i4StartVdoCAF;               // "
        0,  // i4StartVdoTAF;               // "                          
        1,  // i4FpsRemapTblEnable;         // 0:disable, 1:enable
        {10, 12}, // i4FpsThres[2];        // two fps threshold {very-low, low}
        {0, 0},   // i4TableClipPt[2];     // clip pts at macro side
        {80, 90}, // i4TableRemapPt[2];    // percentage of new/org table length

        // --- Easytuning ---       
        {0}, // i4EasyTuning[100]

        // --- DepthAF ---          
        {
            12,     // [0] 0:use i4DampingRdirComp/i4DampingLdirComp, N: use following sDpComp tbl, N is also max shutterIdx           
            120,    // [1] shutter_base, shutter = idx * 1/shutter_base (sec)
            10,     // [2] sDpComp_tbl_size
            30, 70, 100, // [3]~[5] position ratio[%]

            // shutterIdx=1, ratio[3], calibration table right & left
     1, 100, 100, 100, -1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 0, 0, -2, 0, -2, -1, 0, -1, -1, 0,                    
     2, 100, 100, 100, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, -1, 0,                       
     3, 100, 100, 100, -6, -8, -10, -14, -22, -20, -32, -41, -32, -63, 2, 6, 11, 17, 17, 29, 25, 22, 40, -63,
     4, 100, 100, 100, -2, 0, 0, 1, 0, -1, 0, 0, 1, -1, 1, 0, 0, -1, -1, -1, 14, -1, 0, -2,                  
     5, 100, 100, 100, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11, 0, 0, -1,                        
     6, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0,                           
     7, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0,                           
     8, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0,                           
     9, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0,                           
     10, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0,                          
     11, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0,                          
     12, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,                          
                           
        }, // i4DepthAF[500]
        
        // --- reserved ---                 
        { 
            0,                                         // [0] InclineReject: 0 is disable, 1 is enable
            0,                                         // [1] fdOffMaxCnt: 0 is using default value 10
            0, 0, 0, 0, 0, 0, 0, 0, 0,                 // [2~10]
            0, 10, 40,  5, 100, 50, 150, 10, 0, 0,     // [11~20] for DAF
            1, 30, 70,  5, 100, 50, 150, 10, 66, 66,     // [21~30] for PDAF
            37, 38, 3, 1014, 40030, 5005, 5, 1001, 50, 14, // [31]~[40]              
            //0, 0, 30, 100, 90, 70, 0, 0, 0, 0,         // [41]~[50] for PL detect
            1, 800, 170000, 250, 1500000, 109, 16, 15, 0, 0, // [41]~[50] for PL detect  
        }  // i4Coefs[100];
    },
    {//PD_NVRAM_T
        {//PD_CALIBRATION_DATA_T
            {0},
            0,
        },
        {//PD_ALGO_TUNING_T
					32,
					24,
					{30, 150,200,300,400},
					{384,410,435,461,486},
					{{0,0,0,0,0,0},
					{0,0,0,0,0,0},
					{0,20,20,20,20,20},
					{0,20,60,60,60,60},
					{0,20,60,60,60,60},
					{0,20,60,60,60,100}},
					240,	 //  i4SaturateLevel
					1,		 //i4SaturateThr
					10, 	 //i4ConfThr
					{0},

        },
    },
    {0}
};

UINT32 DW9714AF_IMX258_getDefaultData(VOID *pDataBuf, UINT32 size)
{
    UINT32 dataSize = sizeof(NVRAM_LENS_PARA_STRUCT);

    if ((pDataBuf == NULL) || (size < dataSize))
    {
        return 1;
    }

    // copy from Buff to global struct
    memcpy(pDataBuf, &DW9714AF_IMX258_LENS_PARA_DEFAULT_VALUE, dataSize);

    return 0;
}

PFUNC_GETLENSDEFAULT pDW9714AF_IMX258_getDefaultData = DW9714AF_IMX258_getDefaultData;

