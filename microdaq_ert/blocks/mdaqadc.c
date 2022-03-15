#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
#include <string.h>
#include "mdaq_ai.h"
#endif 

void ADCInit(unsigned char *ch, unsigned char ch_count, float *range, unsigned char *mode)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    if( ch_count > AI48 )
        return;
    unsigned char i; 
    unsigned int opt[AI48] = {0}; 

    for(i = 0; i < ch_count; i++)
        opt[i] = mode[i] == 0 ? AI_SINGLE : AI_DIFF; 

    mdaq_ai_init();
    mdaq_ai_config_ch(ch, ch_count, range, opt);

#endif
}

void ADCStep(unsigned char *ch, unsigned char ch_count, unsigned int oversampling, double *value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    if( ch_count > AI16 )
        return;

    if(oversampling)
        mdaq_ai_read2(ch, ch_count, oversampling > 4 ? 4 : oversampling, value);
    else
        mdaq_ai_read(ch, ch_count, value);
#endif
}
