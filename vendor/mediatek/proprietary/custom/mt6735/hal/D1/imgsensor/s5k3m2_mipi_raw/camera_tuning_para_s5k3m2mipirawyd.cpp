#include <utils/Log.h>
#include <fcntl.h>
#include <math.h>

#include "camera_custom_nvram.h"
#include "camera_custom_sensor.h"
#include "image_sensor.h"
#include "kd_imgsensor_define.h"
#include "camera_AE_PLineTable_s5k3m2mipirawyd.h"
#include "camera_info_s5k3m2mipirawyd.h"
#include "camera_custom_AEPlinetable.h"
#include "camera_custom_tsf_tbl.h"
const NVRAM_CAMERA_ISP_PARAM_STRUCT CAMERA_ISP_DEFAULT_VALUE =
{{
    //Version
    Version: NVRAM_CAMERA_PARA_FILE_VERSION,
    //SensorId
    SensorId: SENSOR_ID,
    ISPComm:{
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        }
    },
    ISPPca: {
#include INCLUDE_FILENAME_ISP_PCA_PARAM
    },
    ISPRegs:{
#include INCLUDE_FILENAME_ISP_REGS_PARAM
    },
    ISPMfbMixer:{{
      0x01FF0001, // MIX3_CTRL_0
      0x00FF0000, // MIX3_CTRL_1
      0xFFFF0000  // MIX3_SPARE
    }},
    ISPMulitCCM:{
      Poly22:{
        79350,      // i4R_AVG
        17758,      // i4R_STD
        123800,      // i4B_AVG
        25833,      // i4B_STD
        0,      // i4R_MAX
        0,      // i4R_MIN
        0,      // i4G_MAX
        0,      // i4G_MIN
        0,      // i4B_MAX
        0,      // i4B_MIN
        {  // i4P00[9]
            8247500, -3552500, 417500, -1470000, 6295000, 280000, -150000, -4802500, 10077500
        },
        {  // i4P10[9]
            2064481, -2746113, 692772, 137425, -657735, 513437, 358179, 1402106, -1758218
        },
        {  // i4P01[9]
            1577091, -1910492, 344731, -325577, -571483, 889704, 17635, 18052, -24792
        },
        {  // i4P20[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P11[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        },
        {  // i4P02[9]
            0, 0, 0, 0, 0, 0, 0, 0, 0
        }
      },

      AWBGain:{
        // Strobe
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // A
        {
          574,    // i4R
          512,    // i4G
          1498    // i4B
        },
        // TL84
        {
          757,    // i4R
          512,    // i4G
          1228    // i4B
        },
        // CWF
        {
          843,    // i4R
          512,    // i4G
          1338    // i4B
        },
        // D65
        {
          1000,    // i4R
          512,    // i4G
          888    // i4B
        },
        // Reserved 1
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // Reserved 2
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        },
        // Reserved 3
        {
          512,    // i4R
          512,    // i4G
          512    // i4B
        }
      },
      Weight:{
        1, // Strobe
        1, // A
        1, // TL84
        1, // CWF
        1, // D65
        1, // Reserved 1
        1, // Reserved 2
        1  // Reserved 3
      }
    },

    //bInvokeSmoothCCM
    bInvokeSmoothCCM: MTRUE,

    DngMetadata:{
      0, // i4RefereceIlluminant1
      0, // i4RefereceIlluminant2
      rNoiseProfile:{
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        },
        {
          S:{
            0.000000,      // a
            0.000000       // b
          },
          O:{
            0.000000,      // a
            0.000000       // b
          }
        }
      }
  }
}};

const NVRAM_CAMERA_3A_STRUCT CAMERA_3A_NVRAM_DEFAULT_VALUE =
{
    NVRAM_CAMERA_3A_FILE_VERSION, // u4Version
    SENSOR_ID, // SensorId

    // AE NVRAM
    {
        // rDevicesInfo
        {
            1128,    // u4MinGain, 1024 base = 1x
            10928,    // u4MaxGain, 16x
            40,    // u4MiniISOGain, ISOxx  
            32,    // u4GainStepUnit, 1x/8 
            25059,    // u4PreExpUnit 
            29,    // u4PreMaxFrameRate
            12983,    // u4VideoExpUnit  
            30,    // u4VideoMaxFrameRate 
            1024,    // u4Video2PreRatio, 1024 base = 1x 
            12983,    // u4CapExpUnit 
            30,    // u4CapMaxFrameRate
            1024,    // u4Cap2PreRatio, 1024 base = 1x
            12386,    // u4Video1ExpUnit
            120,    // u4Video1MaxFrameRate
            1024,    // u4Video12PreRatio, 1024 base = 1x
            25059,    // u4Video2ExpUnit
            30,    // u4Video2MaxFrameRate
            1024,    // u4Video22PreRatio, 1024 base = 1x
            25059,    // u4Custom1ExpUnit
            29,    // u4Custom1MaxFrameRate
            1024,    // u4Custom12PreRatio, 1024 base = 1x
            25059,    // u4Custom2ExpUnit
            29,    // u4Custom2MaxFrameRate
            1024,    // u4Custom22PreRatio, 1024 base = 1x
            25059,    // u4Custom3ExpUnit
            29,    // u4Custom3MaxFrameRate
            1024,    // u4Custom32PreRatio, 1024 base = 1x
            25059,    // u4Custom4ExpUnit
            29,    // u4Custom4MaxFrameRate
            1024,    // u4Custom42PreRatio, 1024 base = 1x
            25059,    // u4Custom5ExpUnit
            29,    // u4Custom5MaxFrameRate
            1024,    // u4Custom52PreRatio, 1024 base = 1x
            18,    // u4LensFno, Fno = 2.8
            350    // u4FocusLength_100x
        },
        // rHistConfig
        {
            4,    // u4HistHighThres
            40,    // u4HistLowThres
            2,    // u4MostBrightRatio
            1,    // u4MostDarkRatio
            160,    // u4CentralHighBound
            20,    // u4CentralLowBound
            {240, 230, 220, 210, 200},    // u4OverExpThres[AE_CCT_STRENGTH_NUM] 
            {62, 70, 82, 108, 141},    // u4HistStretchThres[AE_CCT_STRENGTH_NUM] 
            {18, 22, 26, 30, 34}    // u4BlackLightThres[AE_CCT_STRENGTH_NUM] 
        },
        // rCCTConfig
        {
            TRUE,    // bEnableBlackLight
            TRUE,    // bEnableHistStretch
            TRUE,    // bEnableAntiOverExposure
            TRUE,    // bEnableTimeLPF
            FALSE,    // bEnableCaptureThres
            TRUE,    // bEnableVideoThres
            TRUE,    // bEnableVideo1Thres
            TRUE,    // bEnableVideo2Thres
            TRUE,    // bEnableCustom1Thres
            TRUE,    // bEnableCustom2Thres
            TRUE,    // bEnableCustom3Thres
            TRUE,    // bEnableCustom4Thres
            TRUE,    // bEnableCustom5Thres
            TRUE,    // bEnableStrobeThres
            45,    // u4AETarget
            47,    // u4StrobeAETarget
            50,    // u4InitIndex
            4,    // u4BackLightWeight
            32,    // u4HistStretchWeight
            4,    // u4AntiOverExpWeight
            2,    // u4BlackLightStrengthIndex
            2,    // u4HistStretchStrengthIndex
            2,    // u4AntiOverExpStrengthIndex
            2,    // u4TimeLPFStrengthIndex
            {1, 3, 5, 7, 8},    // u4LPFConvergeTable[AE_CCT_STRENGTH_NUM] 
            90,    // u4InDoorEV = 9.0, 10 base 
            3,    // i4BVOffset delta BV = value/10 
            16,    // u4PreviewFlareOffset
            16,    // u4CaptureFlareOffset
            3,    // u4CaptureFlareThres
            0,    // u4VideoFlareOffset
            3,    // u4VideoFlareThres
            0,    // u4CustomFlareOffset
            3,    // u4CustomFlareThres
            0,    // u4StrobeFlareOffset
            3,    // u4StrobeFlareThres
            160,    // u4PrvMaxFlareThres
            0,    // u4PrvMinFlareThres
            160,    // u4VideoMaxFlareThres
            0,    // u4VideoMinFlareThres
            18,    // u4FlatnessThres    // 10 base for flatness condition.
            75,    // u4FlatnessStrength
            //rMeteringSpec
            {
                //rHS_Spec
                {
                    TRUE,//bEnableHistStretch           // enable histogram stretch
                    1024,//u4HistStretchWeight          // Histogram weighting value
                    40,//u4Pcent                      // 
                    170,//u4Thd                        // 0~255
                    80, //74,//u4FlatThd                    // 0~255
                    120,//u4FlatBrightPcent
                    120,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1000,  //i4X1
                        1024,  //i4Y1
                        2400,  //i4X2
                        0  //i4Y2
                    },
                    TRUE, //bEnableGreyTextEnhance
                    1800, //u4GreyTextFlatStart, > sFlatRatio.i4X1, < sFlatRatio.i4X2
                    {
                        10,  //i4X1
                        1024,  //i4Y1
                        80,  //i4X2
                        0  //i4Y2
                    }
                },
                //rAOE_Spec
                {
                    TRUE, //bEnableAntiOverExposure
                    1024, //u4AntiOverExpWeight
                    80, //u4Pcent
                    220, //u4Thd
                    TRUE, //bEnableCOEP
                    1, //u4COEPcent
                    106, //u4COEThd
                    0, //u4BVCompRatio
                    //sCOEYRatio;     // the outer y ratio
                    {
                        23,  //i4X1
                        1024,  //i4Y1
                        47,  //i4X2
                        0  //i4Y2
                    },
                    //sCOEDiffRatio;  // inner/outer y difference ratio
                    {
                        1500,  //i4X1
                        0,  //i4Y1
                        2100,  //i4X2
                        1024  //i4Y2
                    }
                },
                //rABL_Spec
                {
                    TRUE,//bEnableBlackLight
                    1024,//u4BackLightWeight
                    400,//u4Pcent
                    50,//u4Thd
                    255, // center luminance
                    256, // final target limitation, 256/128 = 2x
                    //sFgBgEVRatio
                    {
                        2200,  //i4X1
                        0,  //i4Y1
                        4000,  //i4X2
                        1024  //i4Y2
                    },
                    //sBVRatio
                    {
                        3800,  //i4X1
                        0,  //i4Y1
                        5000,  //i4X2
                        1024  //i4Y2
                    }
                },
                //rNS_Spec
                {
                    TRUE, // bEnableNightScene
                    5,//u4Pcent
                    190,//u4Thd
                    72,//u4FlatThd
                    200,//u4BrightTonePcent
                    86,//u4BrightToneThd
                    500,//u4LowBndPcent
                    5,//u4LowBndThd
                    23,//u4LowBndThdLimit
                    50,//u4FlatBrightPcent
                    300,//u4FlatDarkPcent
                    //sFlatRatio
                    {
                        1200,  //i4X1
                        1024,  //i4Y1
                        2400,  //i4X2
                        0  //i4Y2
                    },
                    //sBVRatio
                    {
                        -500,  //i4X1
                        1024,  //i4Y1
                        3000,  //i4X2
                        0  //i4Y2
                    },
                    TRUE, // bEnableNightSkySuppresion
                    //sSkyBVRatio
                    {
                        -4000,  //i4X1
                        1024,  //i4Y1
                        -2000,  //i4X2
                        0  //i4Y2
                    }
                },
                // rTOUCHFD_Spec
                {
                    40, //uMeteringYLowBound;
                    50, //uMeteringYHighBound;
                    50, //uFaceYLowBound;
                    50, //uFaceYHighBound;
                    3, //uFaceCentralWeight;
                    160, //u4MeteringStableMax;
                    40, //u4MeteringStableMin;
                }
            }, //End rMeteringSpec
            // rFlareSpec
            {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uPrvFlareWeightArr[16];
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //uVideoFlareWeightArr[16];
                96,                                               //u4FlareStdThrHigh;
                48,                                               //u4FlareStdThrLow;
                0,                                               //u4PrvCapFlareDiff;
                4,                                               //u4FlareMaxStepGap_Fast;
                0,                                               //u4FlareMaxStepGap_Slow;
                1800,                                               //u4FlarMaxStepGapLimitBV;
                0,                                               //u4FlareAEStableCount;
            },
            //rAEMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                70, //u4B2TStart
                60, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAEVideoMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAEVideo1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAEVideo2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAECustom1MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAECustom2MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAECustom3MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAECustom4MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAECustom5MoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                150, //u4Bright2TargetEnd
                20, //u4Dark2TargetStart
                90, //u4B2TEnd
                10, //u4B2TStart
                10, //u4D2TEnd
                90, //u4D2TStart
            },
            //rAEFaceMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190, //u4Bright2TargetEnd
                10, //u4Dark2TargetStart
                80, //u4B2TEnd
                30, //u4B2TStart
                20, //u4D2TEnd
                60, //u4D2TStart
            },
            //rAETrackingMoveRatio =
            {
                100, //u4SpeedUpRatio
                100, //u4GlobalRatio
                190, //u4Bright2TargetEnd
                10, //u4Dark2TargetStart
                80, //u4B2TEnd
                30, //u4B2TStart
                20, //u4D2TEnd
                60, //u4D2TStart
            },
            //rAEAOENVRAMParam =
            {
                1,      // i4AOEStrengthIdx: 0 / 1 / 2
                130,      // u4BVCompRatio
                {//rAEAOEAlgParam
                    {//rAEAOEAlgParam[0]
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        10,  //u4AOE_DarkBound
                        950,  //u4AOE_LowlightPrecent
                        1,  //u4AOE_LowlightBound
                        145,  //u4AOESceneLV_L
                        180,  //u4AOESceneLV_H
                        40,  //u4AOE_SWHdrLE_Bound
                    },
                    {//rAEAOEAlgParam[1]
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        15,  //u4AOE_DarkBound
                        950,  //u4AOE_LowlightPrecent
                        3,  //u4AOE_LowlightBound
                        145,  //u4AOESceneLV_L
                        180,  //u4AOESceneLV_H
                        40,  //u4AOE_SWHdrLE_Bound
                    },
                    {//rAEAOEAlgParam[2]
                        47,  //u4Y_Target
                        25,  //u4AOE_OE_percent
                        210,  //u4AOE_OEBound
                        25,  //u4AOE_DarkBound
                        950,  //u4AOE_LowlightPrecent
                        8,  //u4AOE_LowlightBound
                        145,  //u4AOESceneLV_L
                        180,  //u4AOESceneLV_H
                        40,  //u4AOE_SWHdrLE_Bound
                    }
                }
            }
        }
    },
    // AWB NVRAM
    {
        {
          {
            // AWB calibration data
            {
                // rUnitGain (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rD65Gain (D65 WB gain: 1.0 = 512)
                {
                    987,    // D65Gain_R
                    512,    // D65Gain_G
                    867    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    35,    // i4X
                    -443    // i4Y
                },
                // Horizon
                {
                    -473,    // OriX_Hor
                    -434    // OriY_Hor
                },
                // A
                {
                    -343,    // OriX_A
                    -441    // OriY_A
                },
                // TL84
                {
                    -188,    // OriX_TL84
                    -446    // OriY_TL84
                },
                // CWF
                {
                    -178,    // OriX_CWF
                    -510    // OriY_CWF
                },
                // DNP
                {
                    -64,    // OriX_DNP
                    -455    // OriY_DNP
                },
                // D65
                {
                    48,    // OriX_D65
                    -437    // OriY_D65
                },
                // DF
                {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            // Rotated XY coordinate of AWB light source
            {
                // Strobe
                {
                    35,    // i4X
                    -443    // i4Y
                },
                // Horizon
                {
                    -473,    // RotX_Hor
                    -434    // RotY_Hor
                },
                // A
                {
                    -343,    // RotX_A
                    -441    // RotY_A
                },
                // TL84
                {
                    -188,    // RotX_TL84
                    -446    // RotY_TL84
                },
                // CWF
                {
                    -178,    // RotX_CWF
                    -510    // RotY_CWF
                },
                // DNP
                {
                    -64,    // RotX_DNP
                    -455    // RotY_DNP
                },
                // D65
                {
                    48,    // RotX_D65
                    -437    // RotY_D65
                },
                // DF
                {
                    27,    // RotX_DF
                    -501    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    978,    // i4R
                    512,    // i4G
                    890    // i4B
                },
                // Horizon 
                {
                    512,    // AWBGAIN_HOR_R
                    540,    // AWBGAIN_HOR_G
                    1842    // AWBGAIN_HOR_B
                },
                // A 
                {
                    585,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1480    // AWBGAIN_A_B
                },
                // TL84 
                {
                    727,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1207    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    802,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1299    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    870,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    1033    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    987,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    867    // AWBGAIN_D65_B
                },
                // DF 
                {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                }
            },
            // Rotation matrix parameter
            {
                0,    // RotationAngle
                256,    // Cos
                0    // Sin
            },
            // Daylight locus parameter
            {
                -129,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    957,    // i4R
                    530,    // i4G
                    887    // i4B
                },
                // DaylightLocus_H
                {
                    830,    // i4R
                    512,    // i4G
                    1031    // i4B
                },
                // Temporal General
                {
                    987,    // i4R
                    512,    // i4G
                    867    // i4B
                },
                // AWB LSC Gain
                {
                    830,        // i4R
                    512,        // i4G
                    1031        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    85,    // i4RightBound
                    -15,    // i4LeftBound
                    -393,    // i4UpperBound
                    -493    // i4LowerBound
                },
                // Tungsten
                {
                    -250,    // TungRightBound
                    -873,    // TungLeftBound
                    -310,    // TungUpperBound
                    -444    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -250,    // WFluoRightBound
                    -873,    // WFluoLeftBound
                    -444,    // WFluoUpperBound
                    -600    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -104,    // FluoRightBound
                    -250,    // FluoLeftBound
                    -310,    // FluoUpperBound
                    -478    // FluoLowerBound
                },
                // CWF
                {
                -88,    // CWFRightBound
                -250,    // CWFLeftBound
                -478,    // CWFUpperBound
                -565    // CWFLowerBound
                },
                // Daylight
                {
                    78,    // DayRightBound
                    -104,    // DayLeftBound
                    -310,    // DayUpperBound
                    -478    // DayLowerBound
                },
                // Shade
                {
                    408,    // ShadeRightBound
                    78,    // ShadeLeftBound
                    -377,    // ShadeUpperBound
                    -466    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    78,    // DFRightBound
                    -88,    // DFLeftBound
                    -478,    // DFUpperBound
                    -565    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    408,    // PRefRightBound
                    -873,    // PRefLeftBound
                    -310,    // PRefUpperBound
                    -600    // PRefLowerBound
                },
                // Daylight
                {
                    103,    // PDayRightBound
                    -104,    // PDayLeftBound
                    -310,    // PDayUpperBound
                    -478    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    203,    // PCloudyRightBound
                    28,    // PCloudyLeftBound
                    -310,    // PCloudyUpperBound
                    -478    // PCloudyLowerBound
                },
                // Shade
                {
                    303,    // PShadeRightBound
                    28,    // PShadeLeftBound
                    -310,    // PShadeUpperBound
                    -478    // PShadeLowerBound
                },
                // Twilight
                {
                    -104,    // PTwiRightBound
                    -264,    // PTwiLeftBound
                    -310,    // PTwiUpperBound
                    -478    // PTwiLowerBound
                },
                // Fluorescent
                {
                    98,    // PFluoRightBound
                    -288,    // PFluoLeftBound
                    -387,    // PFluoUpperBound
                    -560    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -243,    // PWFluoRightBound
                    -443,    // PWFluoLeftBound
                    -387,    // PWFluoUpperBound
                    -560    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -243,    // PIncaRightBound
                    -443,    // PIncaLeftBound
                    -310,    // PIncaUpperBound
                    -478    // PIncaLowerBound
                },
                // Gray World
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            // PWB default gain	
            {
                // Daylight
                {
                    872,    // PWB_Day_R
                    512,    // PWB_Day_G
                    873    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1021,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    746    // PWB_Cloudy_B
                },
                // Shade
                {
                    1092,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    698    // PWB_Shade_B
                },
                // Twilight
                {
                    680,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    1120    // PWB_Twi_B
                },
                // Fluorescent
                {
                    855,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    1105    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    611,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1546    // PWB_WFluo_B
                },
                // Incandescent
                {
                    549,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1389    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    0,    // TUNG_SLIDER
                    6171    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    0,    // WFluo_SLIDER
                    5060    // WFluo_OFFS
                },
                // Shade
                {
                    0,    // Shade_SLIDER
                    1409    // Shade_OFFS
                },
                // Sunset Area
                {
                    -33,   // i4Sunset_BoundXr_Thr
                    -455    // i4Sunset_BoundYr_Thr
                },
                // Sunset Vertex
                {
                    -33,   // i4Sunset_BoundXr_Thr
                    -455    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -250,   // i4BoundXrThr
                    -450    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -250,   // i4BoundXrThr
                    -464    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -250,   // i4BoundXrThr
                    -514    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -250,   // i4BoundXrThr
                    -540    // i4BoundYrThr
                },
                // Low CCT Area
                {
                    -493,   // i4BoundXrThr
                    74    // i4BoundYrThr
                },
                // Low CCT Vertex
                {
                    -493,   // i4BoundXrThr
                    74    // i4BoundYrThr
                }
            },
            // CCT estimation
            {
                // CCT
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                // Rotated X coordinate
                {
                -521,    // i4RotatedXCoordinate[0]
                -391,    // i4RotatedXCoordinate[1]
                -236,    // i4RotatedXCoordinate[2]
                -112,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        // Algorithm Tuning Paramter
        {
            // AWB Backup Enable
            0,

            // Daylight locus offset LUTs for tungsten
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for WF
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for Shade
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            // Preference gain for each light source
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // TUNGSTEN
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // WARM F
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // F
                {
                    {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, 
                    {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}
                }, // CWF
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                }, // DAYLIGHT
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                }, // SHADE
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                } // DAYLIGHT F
            },
            // Parent block weight parameter
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            // AWB LV threshold for predictor
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            // AWB number threshold for temporal predictor
            {
                65,     // i4Neutral_ParentBlk_Thr
                //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Daylight
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                    // DF
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                // AWB feature detection
                {
                    // Sunset Prop
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },
                    // Shade F Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        70,        // i4LVThr_H
                        128         // i4DaylightProb
                    },
                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        70,        // i4LVThr_H
                        192         // i4DaylightProb
                    },
                    // Low CCT
                    {
                        0,          // i4Enable
                        256        // i4SpeedRatio
                    }
                },
                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },
                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  40,  30,  20}, // Daylight
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                }
            }
        },
        {
          {
            // AWB calibration data
            {
                // rUnitGain (unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rGoldenGain (golden sample gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rTuningUnitGain (Tuning sample unit gain: 1.0 = 512)
                {
                    0,    // i4R
                    0,    // i4G
                    0    // i4B
                },
                // rD65Gain (D65 WB gain: 1.0 = 512)
                {
                    987,    // D65Gain_R
                    512,    // D65Gain_G
                    867    // D65Gain_B
                }
            },
            // Original XY coordinate of AWB light source
            {
                // Strobe
                {
                    35,    // i4X
                    -443    // i4Y
                },
                // Horizon
                {
                    -473,    // OriX_Hor
                    -434    // OriY_Hor
                },
                // A
                {
                    -343,    // OriX_A
                    -441    // OriY_A
                },
                // TL84
                {
                    -188,    // OriX_TL84
                    -446    // OriY_TL84
                },
                // CWF
                {
                    -178,    // OriX_CWF
                    -510    // OriY_CWF
                },
                // DNP
                {
                    -64,    // OriX_DNP
                    -455    // OriY_DNP
                },
                // D65
                {
                    48,    // OriX_D65
                    -437    // OriY_D65
                },
                // DF
                {
                    0,    // OriX_DF
                    0    // OriY_DF
                }
            },
            // Rotated XY coordinate of AWB light source
            {
                // Strobe
                {
                    35,    // i4X
                    -443    // i4Y
                },
                // Horizon
                {
                    -473,    // RotX_Hor
                    -434    // RotY_Hor
                },
                // A
                {
                    -343,    // RotX_A
                    -441    // RotY_A
                },
                // TL84
                {
                    -188,    // RotX_TL84
                    -446    // RotY_TL84
                },
                // CWF
                {
                    -178,    // RotX_CWF
                    -510    // RotY_CWF
                },
                // DNP
                {
                    -64,    // RotX_DNP
                    -455    // RotY_DNP
                },
                // D65
                {
                    48,    // RotX_D65
                    -437    // RotY_D65
                },
                // DF
                {
                    27,    // RotX_DF
                    -501    // RotY_DF
                }
            },
            // AWB gain of AWB light source
            {
                // Strobe 
                {
                    978,    // i4R
                    512,    // i4G
                    890    // i4B
                },
                // Horizon 
                {
                    512,    // AWBGAIN_HOR_R
                    540,    // AWBGAIN_HOR_G
                    1842    // AWBGAIN_HOR_B
                },
                // A 
                {
                    585,    // AWBGAIN_A_R
                    512,    // AWBGAIN_A_G
                    1480    // AWBGAIN_A_B
                },
                // TL84 
                {
                    727,    // AWBGAIN_TL84_R
                    512,    // AWBGAIN_TL84_G
                    1207    // AWBGAIN_TL84_B
                },
                // CWF 
                {
                    802,    // AWBGAIN_CWF_R
                    512,    // AWBGAIN_CWF_G
                    1299    // AWBGAIN_CWF_B
                },
                // DNP 
                {
                    870,    // AWBGAIN_DNP_R
                    512,    // AWBGAIN_DNP_G
                    1033    // AWBGAIN_DNP_B
                },
                // D65 
                {
                    987,    // AWBGAIN_D65_R
                    512,    // AWBGAIN_D65_G
                    867    // AWBGAIN_D65_B
                },
                // DF 
                {
                    512,    // AWBGAIN_DF_R
                    512,    // AWBGAIN_DF_G
                    512    // AWBGAIN_DF_B
                }
            },
            // Rotation matrix parameter
            {
                0,    // RotationAngle
                256,    // Cos
                0    // Sin
            },
            // Daylight locus parameter
            {
                -129,    // i4SlopeNumerator
                128    // i4SlopeDenominator
            },
            // Predictor gain
            {
                101, // i4PrefRatio100
                // DaylightLocus_L
                {
                    957,    // i4R
                    530,    // i4G
                    887    // i4B
                },
                // DaylightLocus_H
                {
                    830,    // i4R
                    512,    // i4G
                    1031    // i4B
                },
                // Temporal General
                {
                    987,    // i4R
                    512,    // i4G
                    867    // i4B
                },
                // AWB LSC Gain
                {
                    830,        // i4R
                    512,        // i4G
                    1031        // i4B
                }
            },
            // AWB light area
            {
                // Strobe:FIXME
                {
                    85,    // i4RightBound
                    -15,    // i4LeftBound
                    -393,    // i4UpperBound
                    -493    // i4LowerBound
                },
                // Tungsten
                {
                    -250,    // TungRightBound
                    -873,    // TungLeftBound
                    -379,    // TungUpperBound
                    -444    // TungLowerBound
                },
                // Warm fluorescent
                {
                    -250,    // WFluoRightBound
                    -873,    // WFluoLeftBound
                    -444,    // WFluoUpperBound
                    -600    // WFluoLowerBound
                },
                // Fluorescent
                {
                    -104,    // FluoRightBound
                    -250,    // FluoLeftBound
                    -377,    // FluoUpperBound
                    -478    // FluoLowerBound
                },
                // CWF
                {
                -88,    // CWFRightBound
                -250,    // CWFLeftBound
                -478,    // CWFUpperBound
                -565    // CWFLowerBound
                },
                // Daylight
                {
                    78,    // DayRightBound
                    -104,    // DayLeftBound
                    -377,    // DayUpperBound
                    -478    // DayLowerBound
                },
                // Shade
                {
                    408,    // ShadeRightBound
                    78,    // ShadeLeftBound
                    -377,    // ShadeUpperBound
                    -466    // ShadeLowerBound
                },
                // Daylight Fluorescent
                {
                    78,    // DFRightBound
                    -88,    // DFLeftBound
                    -478,    // DFUpperBound
                    -565    // DFLowerBound
                }
            },
            // PWB light area
            {
                // Reference area
                {
                    408,    // PRefRightBound
                    -873,    // PRefLeftBound
                    -352,    // PRefUpperBound
                    -600    // PRefLowerBound
                },
                // Daylight
                {
                    103,    // PDayRightBound
                    -104,    // PDayLeftBound
                    -377,    // PDayUpperBound
                    -478    // PDayLowerBound
                },
                // Cloudy daylight
                {
                    203,    // PCloudyRightBound
                    28,    // PCloudyLeftBound
                    -377,    // PCloudyUpperBound
                    -478    // PCloudyLowerBound
                },
                // Shade
                {
                    303,    // PShadeRightBound
                    28,    // PShadeLeftBound
                    -377,    // PShadeUpperBound
                    -478    // PShadeLowerBound
                },
                // Twilight
                {
                    -104,    // PTwiRightBound
                    -264,    // PTwiLeftBound
                    -377,    // PTwiUpperBound
                    -478    // PTwiLowerBound
                },
                // Fluorescent
                {
                    98,    // PFluoRightBound
                    -288,    // PFluoLeftBound
                    -387,    // PFluoUpperBound
                    -560    // PFluoLowerBound
                },
                // Warm fluorescent
                {
                    -243,    // PWFluoRightBound
                    -443,    // PWFluoLeftBound
                    -387,    // PWFluoUpperBound
                    -560    // PWFluoLowerBound
                },
                // Incandescent
                {
                    -243,    // PIncaRightBound
                    -443,    // PIncaLeftBound
                    -377,    // PIncaUpperBound
                    -478    // PIncaLowerBound
                },
                // Gray World
                {
                    5000,    // PGWRightBound
                    -5000,    // PGWLeftBound
                    5000,    // PGWUpperBound
                    -5000    // PGWLowerBound
                }
            },
            // PWB default gain	
            {
                // Daylight
                {
                    913,    // PWB_Day_R
                    512,    // PWB_Day_G
                    914    // PWB_Day_B
                },
                // Cloudy daylight
                {
                    1068,    // PWB_Cloudy_R
                    512,    // PWB_Cloudy_G
                    781    // PWB_Cloudy_B
                },
                // Shade
                {
                    1143,    // PWB_Shade_R
                    512,    // PWB_Shade_G
                    730    // PWB_Shade_B
                },
                // Twilight
                {
                    712,    // PWB_Twi_R
                    512,    // PWB_Twi_G
                    1172    // PWB_Twi_B
                },
                // Fluorescent
                {
                    855,    // PWB_Fluo_R
                    512,    // PWB_Fluo_G
                    1105    // PWB_Fluo_B
                },
                // Warm fluorescent
                {
                    611,    // PWB_WFluo_R
                    512,    // PWB_WFluo_G
                    1546    // PWB_WFluo_B
                },
                // Incandescent
                {
                    574,    // PWB_Inca_R
                    512,    // PWB_Inca_G
                    1453    // PWB_Inca_B
                },
                // Gray World
                {
                    512,    // PWB_GW_R
                    512,    // PWB_GW_G
                    512    // PWB_GW_B
                }
            },
            // AWB preference color	
            {
                // Tungsten
                {
                    0,    // TUNG_SLIDER
                    6171    // TUNG_OFFS
                },
                // Warm fluorescent	
                {
                    0,    // WFluo_SLIDER
                    5060    // WFluo_OFFS
                },
                // Shade
                {
                    0,    // Shade_SLIDER
                    1409    // Shade_OFFS
                },
                // Sunset Area
                {
                    -33,   // i4Sunset_BoundXr_Thr
                    -455    // i4Sunset_BoundYr_Thr
                },
                // Sunset Vertex
                {
                    -33,   // i4Sunset_BoundXr_Thr
                    -455    // i4Sunset_BoundYr_Thr
                },
                // Shade F Area
                {
                    -250,   // i4BoundXrThr
                    -450    // i4BoundYrThr
                },
                // Shade F Vertex
                {
                    -250,   // i4BoundXrThr
                    -464    // i4BoundYrThr
                },
                // Shade CWF Area
                {
                    -250,   // i4BoundXrThr
                    -514    // i4BoundYrThr
                },
                // Shade CWF Vertex
                {
                    -250,   // i4BoundXrThr
                    -540    // i4BoundYrThr
                },
                // Low CCT Area
                {
                    -493,   // i4BoundXrThr
                    74    // i4BoundYrThr
                },
                // Low CCT Vertex
                {
                    -493,   // i4BoundXrThr
                    74    // i4BoundYrThr
                }
            },
            // CCT estimation
            {
                // CCT
                {
                    2300,    // i4CCT[0]
                    2850,    // i4CCT[1]
                    3750,    // i4CCT[2]
                    5100,    // i4CCT[3]
                    6500     // i4CCT[4]
                },
                // Rotated X coordinate
                {
                -521,    // i4RotatedXCoordinate[0]
                -391,    // i4RotatedXCoordinate[1]
                -236,    // i4RotatedXCoordinate[2]
                -112,    // i4RotatedXCoordinate[3]
                0    // i4RotatedXCoordinate[4]
                }
            }
        },
        // Algorithm Tuning Paramter
        {
            // AWB Backup Enable
            0,

            // Daylight locus offset LUTs for tungsten
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 800, 1222, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for WF
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 350, 700, 1000, 1444, 1667, 1889, 2111, 2333, 2556, 2778, 3000, 3222, 3444, 3667, 3889, 4111, 4333, 4556, 4778, 5000} // i4LUTOut
            },
            // Daylight locus offset LUTs for Shade
            {
                21, // i4Size: LUT dimension
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000}, // i4LUTIn
                {0, 500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000} // i4LUTOut
            },
            // Preference gain for each light source
            {
                {
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, 
                    {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}, {512, 512, 512}
                }, // STROBE
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // TUNGSTEN
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // WARM F
                {
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, 
                    {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}, {490, 512, 512}
                }, // F
                {
                    {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, 
                    {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}, {465, 485, 525}
                }, // CWF
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                }, // DAYLIGHT
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                }, // SHADE
                {
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, 
                    {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}, {495, 512, 512}
                } // DAYLIGHT F
            },
            // Parent block weight parameter
            {
                1,      // bEnable
                6           // i4ScalingFactor: [6] 1~12, [7] 1~6, [8] 1~3, [9] 1~2, [>=10]: 1
            },
            // AWB LV threshold for predictor
            {
                115,    // i4InitLVThr_L
                155,    // i4InitLVThr_H
                100      // i4EnqueueLVThr
            },
            // AWB number threshold for temporal predictor
            {
                65,     // i4Neutral_ParentBlk_Thr
                //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   2,   2,   2,   2,   2,   2,   2}  // (%) i4CWFDF_LUTThr
                },
                // AWB light neutral noise reduction for outdoor
                {
                    //LV0  1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18
                    // Non neutral
                    {   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Flurescent
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // CWF
                    {   0,   0,   0,   0,   0,   3,   5,   5,   5,   5,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                    // Daylight
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   2,   2,   2,   2,   2,   2,   2},  // (%)
                    // DF
                    {   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   5,  10,  10,  10,  10,  10,  10,  10,  10},  // (%)
                },
                // AWB feature detection
                {
                    // Sunset Prop
                    {
                        1,          // i4Enable
                        120,        // i4LVThr_L
                        130,        // i4LVThr_H
                        10,         // i4SunsetCountThr
                        0,          // i4SunsetCountRatio_L
                        171         // i4SunsetCountRatio_H
                    },
                    // Shade F Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        70,        // i4LVThr_H
                        128         // i4DaylightProb
                    },
                    // Shade CWF Detection
                    {
                        1,          // i4Enable
                        50,        // i4LVThr_L
                        70,        // i4LVThr_H
                        192         // i4DaylightProb
                    },
                    // Low CCT
                    {
                        0,          // i4Enable
                        256        // i4SpeedRatio
                    }
                },
                // AWB non-neutral probability for spatial and temporal weighting look-up table (Max: 100; Min: 0)
                {
                    //LV0   1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18
                    {   0,  33,  66, 100, 100, 100, 100, 100, 100, 100, 100,  70,  30,  20,  10,   0,   0,   0,   0}
                },
                // AWB daylight locus probability look-up table (Max: 100; Min: 0)
                {   //LV0    1     2     3      4     5     6     7     8      9      10     11    12   13     14    15   16    17    18
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  50,  25,   0,   0,   0,   0}, // Strobe
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0}, // Tungsten
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,  25,  25,   0,   0,   0}, // Warm fluorescent
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  95,  75,  50,  25,  25,  25,   0,   0,   0}, // Fluorescent
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0}, // CWF
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  40,  30,  20}, // Daylight
                    { 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,  75,  50,  25,   0,   0,   0,   0}, // Shade
                    {  90,  90,  90,  90,  90,  90,  90,  90,  90,  90,  80,  55,  30,  30,  30,  30,   0,   0,   0} // Daylight fluorescent
                }
            }
        }
    },
    // Flash AWB NVRAM
    {
#include INCLUDE_FILENAME_FLASH_AWB_PARA
    },
    {0}
};

#include INCLUDE_FILENAME_ISP_LSC_PARAM
//};  //  namespace

#include INCLUDE_FILENAME_TSF

#include INCLUDE_FILENAME_FEATURE_PARA

typedef NSFeature::RAWSensorInfo<SENSOR_ID> SensorInfoSingleton_T;


namespace NSFeature {
template <>
UINT32
SensorInfoSingleton_T::
impGetDefaultData(CAMERA_DATA_TYPE_ENUM const CameraDataType, VOID*const pDataBuf, UINT32 const size) const
{
    UINT32 dataSize[CAMERA_DATA_TYPE_NUM] = {sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT),
                                             sizeof(NVRAM_CAMERA_3A_STRUCT),
                                             sizeof(NVRAM_CAMERA_SHADING_STRUCT),
                                             sizeof(NVRAM_LENS_PARA_STRUCT),
                                             sizeof(AE_PLINETABLE_T),
                                             0,
                                             sizeof(CAMERA_TSF_TBL_STRUCT),
                                             0,
                                             sizeof(NVRAM_CAMERA_FEATURE_STRUCT)
    };

    if (CameraDataType > CAMERA_NVRAM_DATA_FEATURE || NULL == pDataBuf || (size < dataSize[CameraDataType]))
    {
        return 1;
    }

    switch(CameraDataType)
    {
        case CAMERA_NVRAM_DATA_ISP:
            memcpy(pDataBuf,&CAMERA_ISP_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_ISP_PARAM_STRUCT));
            break;
        case CAMERA_NVRAM_DATA_3A:
            memcpy(pDataBuf,&CAMERA_3A_NVRAM_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_3A_STRUCT));
            break;
        case CAMERA_NVRAM_DATA_SHADING:
            memcpy(pDataBuf,&CAMERA_SHADING_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_SHADING_STRUCT));
            break;
        case CAMERA_DATA_AE_PLINETABLE:
            memcpy(pDataBuf,&g_PlineTableMapping,sizeof(AE_PLINETABLE_T));
            break;
        case CAMERA_DATA_TSF_TABLE:
            memcpy(pDataBuf,&CAMERA_TSF_DEFAULT_VALUE,sizeof(CAMERA_TSF_TBL_STRUCT));
            break;
        case CAMERA_NVRAM_DATA_FEATURE:
            memcpy(pDataBuf,&CAMERA_FEATURE_DEFAULT_VALUE,sizeof(NVRAM_CAMERA_FEATURE_STRUCT));
            break;
        default:
            break;
    }
    return 0;
}}; // NSFeature


