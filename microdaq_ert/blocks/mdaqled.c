#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
#include <string.h>
#include "mdaq_dio.h"
#endif 
static dio_init_done = 0; 
void mdaqled_set(unsigned char led, unsigned char state)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)

	mdaq_dio_init(); 

    if (led == 1)
        if (state == 0)
            mdaq_dio_write(D1, 0);
        else
            mdaq_dio_write(D1, 1);
    else if (led == 2)
        if (state == 0)
            mdaq_dio_write(D2, 0);
        else
            mdaq_dio_write(D2, 1);
    else
    {
        /* Shouldn't get here, but switch off LEDs for good */
        mdaq_dio_write(D1, 1);
        mdaq_dio_write(D2, 1);
    }
#endif
}
