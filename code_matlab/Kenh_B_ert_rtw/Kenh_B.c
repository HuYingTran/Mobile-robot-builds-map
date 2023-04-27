/*
 * File: Kenh_B.c
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

#include "Kenh_B.h"
#include "Kenh_B_private.h"
#include "Kenh_B_dt.h"
#define Kenh_B_PinNumber               (2.0)
#define Kenh_B_PinNumber_e             (3.0)

/* Block signals (auto storage) */
B_Kenh_B_T Kenh_B_B;

/* Block states (auto storage) */
DW_Kenh_B_T Kenh_B_DW;

/* Real-time model */
RT_MODEL_Kenh_B_T Kenh_B_M_;
RT_MODEL_Kenh_B_T *const Kenh_B_M = &Kenh_B_M_;

/* Model step function */
void Kenh_B_step(void)
{
  int_T idxDelay;
  boolean_T p;
  boolean_T p_0;
  real_T sampleTime;
  real_T sampleTime_0;
  int8_T rtb_Add;
  uint8_T tmp;

  /* Start for MATLABSystem: '<S4>/Digital Input' */
  p = false;
  p_0 = true;
  if (!(Kenh_B_DW.obj.SampleTime == Kenh_B_P.DigitalInput_SampleTime_o)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(Kenh_B_P.DigitalInput_SampleTime_o)) && (!rtIsNaN
          (Kenh_B_P.DigitalInput_SampleTime_o))) || rtIsInf
        (Kenh_B_P.DigitalInput_SampleTime_o)) {
      sampleTime = Kenh_B_P.DigitalInput_SampleTime_o;
    }

    Kenh_B_DW.obj.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Input' */
  Kenh_B_B.DigitalInput = readDigitalPin((uint8_T)Kenh_B_PinNumber_e);

  /* Sum: '<Root>/Add' incorporates:
   *  Delay: '<Root>/Delay'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Add = (int8_T)(((int16_T)Kenh_B_B.DigitalInput > (int16_T)
                      Kenh_B_DW.DelayInput1_DSTATE) + Kenh_B_DW.Delay_DSTATE);

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant7'
   *  Delay: '<Root>/Delay1'
   *  Product: '<Root>/Divide1'
   *  Product: '<Root>/SAMPLE TIME'
   *  Sum: '<Root>/Sum'
   */
  Kenh_B_B.Product = (real_T)(int8_T)(rtb_Add - Kenh_B_DW.Delay1_DSTATE[0]) /
    (Kenh_B_P.Constant1_Value * Kenh_B_P.Constant7_Value) *
    Kenh_B_P.Constant2_Value;

  /* Product: '<Root>/Product2' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Product: '<Root>/Divide'
   */
  Kenh_B_B.Product2 = Kenh_B_B.Product / Kenh_B_P.Constant3_Value *
    Kenh_B_P.Constant4_Value;

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  p = false;
  p_0 = true;
  if (!(Kenh_B_DW.obj_c.SampleTime == Kenh_B_P.DigitalInput_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(Kenh_B_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (Kenh_B_P.DigitalInput_SampleTime))) || rtIsInf
        (Kenh_B_P.DigitalInput_SampleTime)) {
      sampleTime_0 = Kenh_B_P.DigitalInput_SampleTime;
    }

    Kenh_B_DW.obj_c.SampleTime = sampleTime_0;
  }

  /* MATLABSystem: '<S3>/Digital Input' */
  Kenh_B_B.DigitalInput_m = readDigitalPin((uint8_T)Kenh_B_PinNumber);

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<S7>/Slider Gain'
   */
  sampleTime = Kenh_B_P.SliderGain_gain * Kenh_B_P.Constant5_Value;
  if (sampleTime < 256.0) {
    if (sampleTime >= 0.0) {
      tmp = (uint8_T)sampleTime;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S5>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_analogWrite(Kenh_B_P.PWM_pinNumber, tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Gain: '<S8>/Slider Gain'
   */
  sampleTime = Kenh_B_P.SliderGain1_gain * Kenh_B_P.Constant6_Value;
  if (sampleTime < 256.0) {
    if (sampleTime >= 0.0) {
      tmp = (uint8_T)sampleTime;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_analogWrite(Kenh_B_P.PWM_pinNumber_m, tmp);

  /* Update for UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  Kenh_B_DW.DelayInput1_DSTATE = Kenh_B_B.DigitalInput;

  /* Update for Delay: '<Root>/Delay' */
  Kenh_B_DW.Delay_DSTATE = rtb_Add;

  /* Update for Delay: '<Root>/Delay1' */
  for (idxDelay = 0; idxDelay < 99; idxDelay++) {
    Kenh_B_DW.Delay1_DSTATE[idxDelay] = Kenh_B_DW.Delay1_DSTATE[idxDelay + 1];
  }

  Kenh_B_DW.Delay1_DSTATE[99] = rtb_Add;

  /* End of Update for Delay: '<Root>/Delay1' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rtExtModeUpload(0, Kenh_B_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0005s, 0.0s] */
    if ((rtmGetTFinal(Kenh_B_M)!=-1) &&
        !((rtmGetTFinal(Kenh_B_M)-Kenh_B_M->Timing.taskTime0) >
          Kenh_B_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Kenh_B_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Kenh_B_M)) {
      rtmSetErrorStatus(Kenh_B_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Kenh_B_M->Timing.taskTime0 =
    (++Kenh_B_M->Timing.clockTick0) * Kenh_B_M->Timing.stepSize0;
}

/* Model initialize function */
void Kenh_B_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Kenh_B_M, 0,
                sizeof(RT_MODEL_Kenh_B_T));
  rtmSetTFinal(Kenh_B_M, -1);
  Kenh_B_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  Kenh_B_M->Sizes.checksums[0] = (3749733268U);
  Kenh_B_M->Sizes.checksums[1] = (2233917866U);
  Kenh_B_M->Sizes.checksums[2] = (2153548543U);
  Kenh_B_M->Sizes.checksums[3] = (1667571029U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Kenh_B_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Kenh_B_M->extModeInfo,
      &Kenh_B_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Kenh_B_M->extModeInfo, Kenh_B_M->Sizes.checksums);
    rteiSetTPtr(Kenh_B_M->extModeInfo, rtmGetTPtr(Kenh_B_M));
  }

  /* block I/O */
  (void) memset(((void *) &Kenh_B_B), 0,
                sizeof(B_Kenh_B_T));

  /* states (dwork) */
  (void) memset((void *)&Kenh_B_DW, 0,
                sizeof(DW_Kenh_B_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Kenh_B_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    int16_T i;

    /* Start for MATLABSystem: '<S4>/Digital Input' */
    Kenh_B_DW.obj.isInitialized = 0L;
    if (((!rtIsInf(Kenh_B_P.DigitalInput_SampleTime_o)) && (!rtIsNaN
          (Kenh_B_P.DigitalInput_SampleTime_o))) || rtIsInf
        (Kenh_B_P.DigitalInput_SampleTime_o)) {
      sampleTime = Kenh_B_P.DigitalInput_SampleTime_o;
    }

    Kenh_B_DW.obj.SampleTime = sampleTime;
    Kenh_B_DW.obj.isInitialized = 1L;
    digitalIOSetup((uint8_T)Kenh_B_PinNumber_e, false);

    /* End of Start for MATLABSystem: '<S4>/Digital Input' */
    /* Start for MATLABSystem: '<S3>/Digital Input' */
    Kenh_B_DW.obj_c.isInitialized = 0L;
    if (((!rtIsInf(Kenh_B_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (Kenh_B_P.DigitalInput_SampleTime))) || rtIsInf
        (Kenh_B_P.DigitalInput_SampleTime)) {
      sampleTime_0 = Kenh_B_P.DigitalInput_SampleTime;
    }

    Kenh_B_DW.obj_c.SampleTime = sampleTime_0;
    Kenh_B_DW.obj_c.isInitialized = 1L;
    digitalIOSetup((uint8_T)Kenh_B_PinNumber, false);

    /* End of Start for MATLABSystem: '<S3>/Digital Input' */
    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
    MW_pinModeOutput(Kenh_B_P.PWM_pinNumber);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(Kenh_B_P.PWM_pinNumber_m);

    /* InitializeConditions for UnitDelay: '<S2>/Delay Input1'
     *
     * Block description for '<S2>/Delay Input1':
     *
     *  Store in Global RAM
     */
    Kenh_B_DW.DelayInput1_DSTATE = Kenh_B_P.DetectIncrease_vinit;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    Kenh_B_DW.Delay_DSTATE = Kenh_B_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    for (i = 0; i < 100; i++) {
      Kenh_B_DW.Delay1_DSTATE[i] = Kenh_B_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay1' */

    /* SystemInitialize for Chart: '<Root>/Chart' */
    Kenh_B_DW.is_active_c3_Kenh_B = 0U;
  }
}

/* Model terminate function */
void Kenh_B_terminate(void)
{
  /* Start for MATLABSystem: '<S4>/Digital Input' */
  if (Kenh_B_DW.obj.isInitialized == 1L) {
    Kenh_B_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Input' */

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  if (Kenh_B_DW.obj_c.isInitialized == 1L) {
    Kenh_B_DW.obj_c.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
