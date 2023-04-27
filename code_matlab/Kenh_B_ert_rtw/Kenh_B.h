/*
 * File: Kenh_B.h
 *
 * Code generated for Simulink model 'Kenh_B'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Jul  4 12:47:51 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Kenh_B_h_
#define RTW_HEADER_Kenh_B_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Kenh_B_COMMON_INCLUDES_
# define Kenh_B_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalio.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* Kenh_B_COMMON_INCLUDES_ */

#include "Kenh_B_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Product;                      /* '<Root>/Product' */
  real_T Product2;                     /* '<Root>/Product2' */
  boolean_T DigitalInput;              /* '<S4>/Digital Input' */
  boolean_T DigitalInput_m;            /* '<S3>/Digital Input' */
} B_Kenh_B_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S4>/Digital Input' */
  codertarget_arduinobase_block_T obj_c;/* '<S3>/Digital Input' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } XUNGA_B_PWORK;                     /* '<Root>/XUNG A_B' */

  int8_T Delay_DSTATE;                 /* '<Root>/Delay' */
  int8_T Delay1_DSTATE[100];           /* '<Root>/Delay1' */
  boolean_T DelayInput1_DSTATE;        /* '<S2>/Delay Input1' */
  uint8_T is_active_c3_Kenh_B;         /* '<Root>/Chart' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/Chart' */
} DW_Kenh_B_T;

/* Parameters (auto storage) */
struct P_Kenh_B_T_ {
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S7>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S8>/Slider Gain'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S5>/PWM'
                                        */
  uint32_T PWM_pinNumber_m;            /* Mask Parameter: PWM_pinNumber_m
                                        * Referenced by: '<S6>/PWM'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S2>/Delay Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S3>/Digital Input'
                                        */
  real_T DigitalInput_SampleTime_o;    /* Expression: -1
                                        * Referenced by: '<S4>/Digital Input'
                                        */
  real_T Constant1_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant2_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 334
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 60
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
  uint16_T Delay1_DelayLength;         /* Computed Parameter: Delay1_DelayLength
                                        * Referenced by: '<Root>/Delay1'
                                        */
  int8_T Delay_InitialCondition;       /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<Root>/Delay'
                                        */
  int8_T Delay1_InitialCondition;      /* Computed Parameter: Delay1_InitialCondition
                                        * Referenced by: '<Root>/Delay1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Kenh_B_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Kenh_B_T Kenh_B_P;

/* Block signals (auto storage) */
extern B_Kenh_B_T Kenh_B_B;

/* Block states (auto storage) */
extern DW_Kenh_B_T Kenh_B_DW;

/* Model entry point functions */
extern void Kenh_B_initialize(void);
extern void Kenh_B_step(void);
extern void Kenh_B_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Kenh_B_T *const Kenh_B_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Kenh_B'
 * '<S1>'   : 'Kenh_B/Chart'
 * '<S2>'   : 'Kenh_B/Detect Increase'
 * '<S3>'   : 'Kenh_B/Digital Input'
 * '<S4>'   : 'Kenh_B/Digital Input1'
 * '<S5>'   : 'Kenh_B/PWM'
 * '<S6>'   : 'Kenh_B/PWM1'
 * '<S7>'   : 'Kenh_B/Slider Gain'
 * '<S8>'   : 'Kenh_B/Slider Gain1'
 */
#endif                                 /* RTW_HEADER_Kenh_B_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
