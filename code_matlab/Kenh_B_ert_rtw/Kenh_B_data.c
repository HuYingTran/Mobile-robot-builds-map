/*
 * File: Kenh_B_data.c
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

/* Block parameters (auto storage) */
P_Kenh_B_T Kenh_B_P = {
  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S7>/Slider Gain'
   */
  80.0,

  /* Mask Parameter: SliderGain1_gain
   * Referenced by: '<S8>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: PWM_pinNumber
   * Referenced by: '<S5>/PWM'
   */
  5U,

  /* Mask Parameter: PWM_pinNumber_m
   * Referenced by: '<S6>/PWM'
   */
  6U,

  /* Mask Parameter: DetectIncrease_vinit
   * Referenced by: '<S2>/Delay Input1'
   */
  0,

  /* Expression: -1
   * Referenced by: '<S3>/Digital Input'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<S4>/Digital Input'
   */
  -1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant1'
   */
  100.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Constant7'
   */
  0.5,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant2'
   */
  1000.0,

  /* Expression: 334
   * Referenced by: '<Root>/Constant3'
   */
  334.0,

  /* Expression: 60
   * Referenced by: '<Root>/Constant4'
   */
  60.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant5'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant6'
   */
  1.0,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<Root>/Delay'
   */
  1U,

  /* Computed Parameter: Delay1_DelayLength
   * Referenced by: '<Root>/Delay1'
   */
  100U,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<Root>/Delay'
   */
  0,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<Root>/Delay1'
   */
  0
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
