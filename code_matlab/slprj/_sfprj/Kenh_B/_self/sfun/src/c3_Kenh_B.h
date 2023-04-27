#ifndef __c3_Kenh_B_h__
#define __c3_Kenh_B_h__

/* Type Definitions */
#ifndef typedef_SFc3_Kenh_BInstanceStruct
#define typedef_SFc3_Kenh_BInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  int32_T *c3_sfEvent;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_Kenh_B;
} SFc3_Kenh_BInstanceStruct;

#endif                                 /*typedef_SFc3_Kenh_BInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Kenh_B_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Kenh_B_get_check_sum(mxArray *plhs[]);
extern void c3_Kenh_B_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
