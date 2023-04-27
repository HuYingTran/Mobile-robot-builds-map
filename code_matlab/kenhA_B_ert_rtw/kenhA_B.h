/*
 * File: kenhA_B.h
 *
 * Code generated for Simulink model 'kenhA_B'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jul  3 15:56:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_kenhA_B_h_
#define RTW_HEADER_kenhA_B_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef kenhA_B_COMMON_INCLUDES_
# define kenhA_B_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_digitalio.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* kenhA_B_COMMON_INCLUDES_ */

#include "kenhA_B_types.h"

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
  int8_T Add;                          /* '<S5>/Add' */
  int8_T Add_h;                        /* '<S4>/Add' */
} B_kenhA_B_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_block_T obj; /* '<S3>/Digital Input' */
  codertarget_arduinobase_block_T obj_j;/* '<S2>/Digital Input' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<Root>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<Root>/If Action Subsystem' */
} DW_kenhA_B_T;

/* Parameters (auto storage) */
struct P_kenhA_B_T_ {
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S8>/Slider Gain'
                                        */
  real_T SliderGain1_gain;             /* Mask Parameter: SliderGain1_gain
                                        * Referenced by: '<S9>/Slider Gain'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S6>/PWM'
                                        */
  uint32_T PWM_pinNumber_m;            /* Mask Parameter: PWM_pinNumber_m
                                        * Referenced by: '<S7>/PWM'
                                        */
  boolean_T DetectIncrease_vinit;      /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S1>/Delay Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: -1
                                        * Referenced by: '<S2>/Digital Input'
                                        */
  real_T DigitalInput_SampleTime_n;    /* Expression: -1
                                        * Referenced by: '<S3>/Digital Input'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint16_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<S4>/Delay'
                                        */
  uint16_T Delay_DelayLength_j;        /* Computed Parameter: Delay_DelayLength_j
                                        * Referenced by: '<S5>/Delay'
                                        */
  int8_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  int8_T Delay_InitialCondition;       /* Computed Parameter: Delay_InitialCondition
                                        * Referenced by: '<S4>/Delay'
                                        */
  int8_T Out1_Y0_e;                    /* Computed Parameter: Out1_Y0_e
                                        * Referenced by: '<S5>/Out1'
                                        */
  int8_T Delay_InitialCondition_c;     /* Computed Parameter: Delay_InitialCondition_c
                                        * Referenced by: '<S5>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_kenhA_B_T {
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
extern P_kenhA_B_T kenhA_B_P;

/* Block signals (auto storage) */
extern B_kenhA_B_T kenhA_B_B;

/* Block states (auto storage) */
extern DW_kenhA_B_T kenhA_B_DW;

/* Model entry point functions */
extern void kenhA_B_initialize(void);
extern void kenhA_B_step(void);
extern void kenhA_B_terminate(void);

/* Real-time Model object */
extern RT_MODEL_kenhA_B_T *const kenhA_B_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Add' : Unused code path elimination
 */

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
 * '<Root>' : 'kenhA_B'
 * '<S1>'   : 'kenhA_B/Detect Increase'
 * '<S2>'   : 'kenhA_B/Digital Input'
 * '<S3>'   : 'kenhA_B/Digital Input1'
 * '<S4>'   : 'kenhA_B/If Action Subsystem'
 * '<S5>'   : 'kenhA_B/If Action Subsystem1'
 * '<S6>'   : 'kenhA_B/PWM'
 * '<S7>'   : 'kenhA_B/PWM1'
 * '<S8>'   : 'kenhA_B/Slider Gain'
 * '<S9>'   : 'kenhA_B/Slider Gain1'
 */
#endif                                 /* RTW_HEADER_kenhA_B_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
