/*
 * untitled_dt.h
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.6
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Sun Jul  3 15:30:40 2022
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
  { (char_T *)(&untitled_B.FFT.re), 0, 1, 2 },

  { (char_T *)(&untitled_B.Product2), 0, 0, 1 },

  { (char_T *)(&untitled_B.Sum), 2, 0, 1 },

  { (char_T *)(&untitled_B.DigitalInput), 8, 0, 2 }
  ,

  { (char_T *)(&untitled_DW.obj), 14, 0, 2 },

  { (char_T *)(&untitled_DW.Scope_PWORK.LoggedData), 11, 0, 3 },

  { (char_T *)(&untitled_DW.Delay_DSTATE), 2, 0, 101 },

  { (char_T *)(&untitled_DW.DelayInput1_DSTATE), 8, 0, 1 },

  { (char_T *)(&untitled_DW.is_active_c3_untitled), 3, 0, 1 },

  { (char_T *)(&untitled_DW.doneDoubleBufferReInit), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&untitled_P.SliderGain_gain), 0, 0, 2 },

  { (char_T *)(&untitled_P.PWM_pinNumber), 7, 0, 2 },

  { (char_T *)(&untitled_P.DetectIncrease_vinit), 8, 0, 1 },

  { (char_T *)(&untitled_P.DigitalInput_SampleTime), 0, 0, 9 },

  { (char_T *)(&untitled_P.Delay_DelayLength), 5, 0, 2 },

  { (char_T *)(&untitled_P.Delay_InitialCondition), 2, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] untitled_dt.h */
