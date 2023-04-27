/*
 * kenhA_B_dt.h
 *
 * Code generation for model "kenhA_B".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Jul  3 15:56:11 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_block_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_block_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&kenhA_B_B.Add), 2, 0, 2 }
  ,

  { (char_T *)(&kenhA_B_DW.obj), 14, 0, 2 },

  { (char_T *)(&kenhA_B_DW.Scope_PWORK.LoggedData), 11, 0, 1 },

  { (char_T *)(&kenhA_B_DW.DelayInput1_DSTATE), 8, 0, 1 },

  { (char_T *)(&kenhA_B_DW.IfActionSubsystem1_SubsysRanBC), 2, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&kenhA_B_P.SliderGain_gain), 0, 0, 2 },

  { (char_T *)(&kenhA_B_P.PWM_pinNumber), 7, 0, 2 },

  { (char_T *)(&kenhA_B_P.DetectIncrease_vinit), 8, 0, 1 },

  { (char_T *)(&kenhA_B_P.DigitalInput_SampleTime), 0, 0, 4 },

  { (char_T *)(&kenhA_B_P.Delay_DelayLength), 5, 0, 2 },

  { (char_T *)(&kenhA_B_P.Out1_Y0), 2, 0, 4 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] kenhA_B_dt.h */
