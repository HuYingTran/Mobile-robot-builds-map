/*
 * File: kenhA_B.c
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

#include "kenhA_B.h"
#include "kenhA_B_private.h"
#include "kenhA_B_dt.h"
#define kenhA_B_PinNumber              (2.0)
#define kenhA_B_PinNumber_b            (3.0)

/* Block signals (auto storage) */
B_kenhA_B_T kenhA_B_B;

/* Block states (auto storage) */
DW_kenhA_B_T kenhA_B_DW;

/* Real-time model */
RT_MODEL_kenhA_B_T kenhA_B_M_;
RT_MODEL_kenhA_B_T *const kenhA_B_M = &kenhA_B_M_;

/* Model step function */
void kenhA_B_step(void)
{
  boolean_T rtb_DigitalInput_i_0;
  boolean_T p;
  boolean_T p_0;
  real_T sampleTime;
  real_T sampleTime_0;
  int8_T rtb_DataTypeConversion;
  real_T tmp;
  uint8_T tmp_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(kenhA_B_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(kenhA_B_DW.IfActionSubsystem1_SubsysRanBC);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S8>/Slider Gain'
   */
  tmp = kenhA_B_P.SliderGain_gain * kenhA_B_P.Constant_Value;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_analogWrite(kenhA_B_P.PWM_pinNumber, tmp_0);

  /* DataTypeConversion: '<S7>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S9>/Slider Gain'
   */
  tmp = kenhA_B_P.SliderGain1_gain * kenhA_B_P.Constant1_Value;
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S7>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
  MW_analogWrite(kenhA_B_P.PWM_pinNumber_m, tmp_0);

  /* Start for MATLABSystem: '<S2>/Digital Input' */
  p = false;
  p_0 = true;
  if (!(kenhA_B_DW.obj_j.SampleTime == kenhA_B_P.DigitalInput_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(kenhA_B_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (kenhA_B_P.DigitalInput_SampleTime))) || rtIsInf
        (kenhA_B_P.DigitalInput_SampleTime)) {
      sampleTime = kenhA_B_P.DigitalInput_SampleTime;
    }

    kenhA_B_DW.obj_j.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S2>/Digital Input' */
  rtb_DigitalInput_i_0 = readDigitalPin((uint8_T)kenhA_B_PinNumber);

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  MATLABSystem: '<S2>/Digital Input'
   *  RelationalOperator: '<S1>/FixPt Relational Operator'
   *  UnitDelay: '<S1>/Delay Input1'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_DataTypeConversion = (int8_T)((int16_T)rtb_DigitalInput_i_0 > (int16_T)
    kenhA_B_DW.DelayInput1_DSTATE);

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  p = false;
  p_0 = true;
  if (!(kenhA_B_DW.obj.SampleTime == kenhA_B_P.DigitalInput_SampleTime_n)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(kenhA_B_P.DigitalInput_SampleTime_n)) && (!rtIsNaN
          (kenhA_B_P.DigitalInput_SampleTime_n))) || rtIsInf
        (kenhA_B_P.DigitalInput_SampleTime_n)) {
      sampleTime_0 = kenhA_B_P.DigitalInput_SampleTime_n;
    }

    kenhA_B_DW.obj.SampleTime = sampleTime_0;
  }

  /* MATLABSystem: '<S3>/Digital Input' */
  p = readDigitalPin((uint8_T)kenhA_B_PinNumber_b);

  /* If: '<Root>/If' incorporates:
   *  MATLABSystem: '<S3>/Digital Input'
   */
  if ((rtb_DataTypeConversion > 0) && (!p)) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Sum: '<S4>/Add' incorporates:
     *  Delay: '<S4>/Delay'
     */
    kenhA_B_B.Add_h++;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Update for If: '<Root>/If' */
    srUpdateBC(kenhA_B_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    if ((rtb_DataTypeConversion > 0) && (!p)) {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Sum: '<S5>/Add' incorporates:
       *  Delay: '<S5>/Delay'
       */
      kenhA_B_B.Add--;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */

      /* Update for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S5>/Action Port'
       */
      /* Update for If: '<Root>/If' */
      srUpdateBC(kenhA_B_DW.IfActionSubsystem1_SubsysRanBC);

      /* End of Update for SubSystem: '<Root>/If Action Subsystem1' */
    }
  }

  /* End of If: '<Root>/If' */
  /* Update for UnitDelay: '<S1>/Delay Input1' incorporates:
   *  MATLABSystem: '<S2>/Digital Input'
   *
   * Block description for '<S1>/Delay Input1':
   *
   *  Store in Global RAM
   */
  kenhA_B_DW.DelayInput1_DSTATE = rtb_DigitalInput_i_0;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rtExtModeUpload(0, kenhA_B_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0005s, 0.0s] */
    if ((rtmGetTFinal(kenhA_B_M)!=-1) &&
        !((rtmGetTFinal(kenhA_B_M)-kenhA_B_M->Timing.taskTime0) >
          kenhA_B_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(kenhA_B_M, "Simulation finished");
    }

    if (rtmGetStopRequested(kenhA_B_M)) {
      rtmSetErrorStatus(kenhA_B_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  kenhA_B_M->Timing.taskTime0 =
    (++kenhA_B_M->Timing.clockTick0) * kenhA_B_M->Timing.stepSize0;
}

/* Model initialize function */
void kenhA_B_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)kenhA_B_M, 0,
                sizeof(RT_MODEL_kenhA_B_T));
  rtmSetTFinal(kenhA_B_M, -1);
  kenhA_B_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  kenhA_B_M->Sizes.checksums[0] = (2766220568U);
  kenhA_B_M->Sizes.checksums[1] = (505093989U);
  kenhA_B_M->Sizes.checksums[2] = (2460273771U);
  kenhA_B_M->Sizes.checksums[3] = (3483617998U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    kenhA_B_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&kenhA_B_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&kenhA_B_DW.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(kenhA_B_M->extModeInfo,
      &kenhA_B_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(kenhA_B_M->extModeInfo, kenhA_B_M->Sizes.checksums);
    rteiSetTPtr(kenhA_B_M->extModeInfo, rtmGetTPtr(kenhA_B_M));
  }

  /* block I/O */
  (void) memset(((void *) &kenhA_B_B), 0,
                sizeof(B_kenhA_B_T));

  /* states (dwork) */
  (void) memset((void *)&kenhA_B_DW, 0,
                sizeof(DW_kenhA_B_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    kenhA_B_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    real_T sampleTime;
    real_T sampleTime_0;

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(kenhA_B_P.PWM_pinNumber);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S7>/PWM' */
    MW_pinModeOutput(kenhA_B_P.PWM_pinNumber_m);

    /* Start for MATLABSystem: '<S2>/Digital Input' */
    kenhA_B_DW.obj_j.isInitialized = 0L;
    if (((!rtIsInf(kenhA_B_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (kenhA_B_P.DigitalInput_SampleTime))) || rtIsInf
        (kenhA_B_P.DigitalInput_SampleTime)) {
      sampleTime = kenhA_B_P.DigitalInput_SampleTime;
    }

    kenhA_B_DW.obj_j.SampleTime = sampleTime;
    kenhA_B_DW.obj_j.isInitialized = 1L;
    digitalIOSetup((uint8_T)kenhA_B_PinNumber, false);

    /* End of Start for MATLABSystem: '<S2>/Digital Input' */

    /* Start for MATLABSystem: '<S3>/Digital Input' */
    kenhA_B_DW.obj.isInitialized = 0L;
    if (((!rtIsInf(kenhA_B_P.DigitalInput_SampleTime_n)) && (!rtIsNaN
          (kenhA_B_P.DigitalInput_SampleTime_n))) || rtIsInf
        (kenhA_B_P.DigitalInput_SampleTime_n)) {
      sampleTime_0 = kenhA_B_P.DigitalInput_SampleTime_n;
    }

    kenhA_B_DW.obj.SampleTime = sampleTime_0;
    kenhA_B_DW.obj.isInitialized = 1L;
    digitalIOSetup((uint8_T)kenhA_B_PinNumber_b, false);

    /* End of Start for MATLABSystem: '<S3>/Digital Input' */

    /* InitializeConditions for UnitDelay: '<S1>/Delay Input1'
     *
     * Block description for '<S1>/Delay Input1':
     *
     *  Store in Global RAM
     */
    kenhA_B_DW.DelayInput1_DSTATE = kenhA_B_P.DetectIncrease_vinit;

    /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
    /* SystemInitialize for Outport: '<S4>/Out1' */
    kenhA_B_B.Add_h = kenhA_B_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem1' */
    /* SystemInitialize for Outport: '<S5>/Out1' */
    kenhA_B_B.Add = kenhA_B_P.Out1_Y0_e;

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem1' */
  }
}

/* Model terminate function */
void kenhA_B_terminate(void)
{
  /* Start for MATLABSystem: '<S2>/Digital Input' */
  if (kenhA_B_DW.obj_j.isInitialized == 1L) {
    kenhA_B_DW.obj_j.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S2>/Digital Input' */

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  if (kenhA_B_DW.obj.isInitialized == 1L) {
    kenhA_B_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
