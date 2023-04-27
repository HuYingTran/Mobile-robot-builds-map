/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jul  3 15:30:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
#define untitled_PinNumber             (2.0)
#define untitled_PinNumber_b           (3.0)

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Block states (auto storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model step function */
void untitled_step(void)
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
  if (!(untitled_DW.obj.SampleTime == untitled_P.DigitalInput_SampleTime_o)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(untitled_P.DigitalInput_SampleTime_o)) && (!rtIsNaN
          (untitled_P.DigitalInput_SampleTime_o))) || rtIsInf
        (untitled_P.DigitalInput_SampleTime_o)) {
      sampleTime = untitled_P.DigitalInput_SampleTime_o;
    }

    untitled_DW.obj.SampleTime = sampleTime;
  }

  /* MATLABSystem: '<S4>/Digital Input' */
  untitled_B.DigitalInput = readDigitalPin((uint8_T)untitled_PinNumber_b);

  /* Sum: '<Root>/Add' incorporates:
   *  Delay: '<Root>/Delay'
   *  RelationalOperator: '<S2>/FixPt Relational Operator'
   *  UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_Add = (int8_T)(((int16_T)untitled_B.DigitalInput > (int16_T)
                      untitled_DW.DelayInput1_DSTATE) + untitled_DW.Delay_DSTATE);

  /* Sum: '<Root>/Sum' incorporates:
   *  Delay: '<Root>/Delay1'
   */
  untitled_B.Sum = (int8_T)(rtb_Add - untitled_DW.Delay1_DSTATE[0]);

  /* Product: '<Root>/Product2' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Product: '<Root>/Divide'
   *  Product: '<Root>/Divide1'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product1'
   */
  untitled_B.Product2 = (real_T)untitled_B.Sum / (untitled_P.Constant_Value *
    untitled_P.Constant1_Value) * untitled_P.Constant2_Value /
    untitled_P.Constant3_Value * untitled_P.Constant4_Value;

  /* S-Function (sdspfft2): '<Root>/FFT' */
  untitled_B.FFT.re = untitled_B.Product2;
  untitled_B.FFT.im = 0.0;

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  p = false;
  p_0 = true;
  if (!(untitled_DW.obj_c.SampleTime == untitled_P.DigitalInput_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    if (((!rtIsInf(untitled_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (untitled_P.DigitalInput_SampleTime))) || rtIsInf
        (untitled_P.DigitalInput_SampleTime)) {
      sampleTime_0 = untitled_P.DigitalInput_SampleTime;
    }

    untitled_DW.obj_c.SampleTime = sampleTime_0;
  }

  /* MATLABSystem: '<S3>/Digital Input' */
  untitled_B.DigitalInput_m = readDigitalPin((uint8_T)untitled_PinNumber);

  /* DataTypeConversion: '<S5>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Gain: '<S7>/Slider Gain'
   */
  sampleTime = untitled_P.SliderGain_gain * untitled_P.Constant5_Value;
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
  MW_analogWrite(untitled_P.PWM_pinNumber, tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Gain: '<S8>/Slider Gain'
   */
  sampleTime = untitled_P.SliderGain1_gain * untitled_P.Constant6_Value;
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
  MW_analogWrite(untitled_P.PWM_pinNumber_m, tmp);

  /* Update for UnitDelay: '<S2>/Delay Input1'
   *
   * Block description for '<S2>/Delay Input1':
   *
   *  Store in Global RAM
   */
  untitled_DW.DelayInput1_DSTATE = untitled_B.DigitalInput;

  /* Update for Delay: '<Root>/Delay' */
  untitled_DW.Delay_DSTATE = rtb_Add;

  /* Update for Delay: '<Root>/Delay1' */
  for (idxDelay = 0; idxDelay < 99; idxDelay++) {
    untitled_DW.Delay1_DSTATE[idxDelay] = untitled_DW.Delay1_DSTATE[idxDelay + 1];
  }

  untitled_DW.Delay1_DSTATE[99] = rtb_Add;

  /* End of Update for Delay: '<Root>/Delay1' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rtExtModeUpload(0, untitled_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0005s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1145523713U);
  untitled_M->Sizes.checksums[1] = (1720386092U);
  untitled_M->Sizes.checksums[2] = (1878264310U);
  untitled_M->Sizes.checksums[3] = (1303925409U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    untitled_DW.obj.isInitialized = 0L;
    if (((!rtIsInf(untitled_P.DigitalInput_SampleTime_o)) && (!rtIsNaN
          (untitled_P.DigitalInput_SampleTime_o))) || rtIsInf
        (untitled_P.DigitalInput_SampleTime_o)) {
      sampleTime = untitled_P.DigitalInput_SampleTime_o;
    }

    untitled_DW.obj.SampleTime = sampleTime;
    untitled_DW.obj.isInitialized = 1L;
    digitalIOSetup((uint8_T)untitled_PinNumber_b, false);

    /* End of Start for MATLABSystem: '<S4>/Digital Input' */
    /* Start for MATLABSystem: '<S3>/Digital Input' */
    untitled_DW.obj_c.isInitialized = 0L;
    if (((!rtIsInf(untitled_P.DigitalInput_SampleTime)) && (!rtIsNaN
          (untitled_P.DigitalInput_SampleTime))) || rtIsInf
        (untitled_P.DigitalInput_SampleTime)) {
      sampleTime_0 = untitled_P.DigitalInput_SampleTime;
    }

    untitled_DW.obj_c.SampleTime = sampleTime_0;
    untitled_DW.obj_c.isInitialized = 1L;
    digitalIOSetup((uint8_T)untitled_PinNumber, false);

    /* End of Start for MATLABSystem: '<S3>/Digital Input' */
    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
    MW_pinModeOutput(untitled_P.PWM_pinNumber);

    /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
    MW_pinModeOutput(untitled_P.PWM_pinNumber_m);

    /* InitializeConditions for UnitDelay: '<S2>/Delay Input1'
     *
     * Block description for '<S2>/Delay Input1':
     *
     *  Store in Global RAM
     */
    untitled_DW.DelayInput1_DSTATE = untitled_P.DetectIncrease_vinit;

    /* InitializeConditions for Delay: '<Root>/Delay' */
    untitled_DW.Delay_DSTATE = untitled_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    for (i = 0; i < 100; i++) {
      untitled_DW.Delay1_DSTATE[i] = untitled_P.Delay1_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<Root>/Delay1' */

    /* SystemInitialize for Chart: '<Root>/Chart' */
    untitled_DW.is_active_c3_untitled = 0U;
  }
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* Start for MATLABSystem: '<S4>/Digital Input' */
  if (untitled_DW.obj.isInitialized == 1L) {
    untitled_DW.obj.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S4>/Digital Input' */

  /* Start for MATLABSystem: '<S3>/Digital Input' */
  if (untitled_DW.obj_c.isInitialized == 1L) {
    untitled_DW.obj_c.isInitialized = 2L;
  }

  /* End of Start for MATLABSystem: '<S3>/Digital Input' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
