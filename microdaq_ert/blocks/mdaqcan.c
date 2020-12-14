#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
#include <stdint.h>
#include "mdaq_can.h"
#endif


void mdaqcan_send(char *len, unsigned int *id, unsigned char data[])
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    int result; 
    can_frame_t f; 
    
    
    if(*id < 0x7ff && *len < 9 && *len > -1)
    {
        memset((void *)&f, 0x0, sizeof(can_frame_t)); 

        f.id = *id; 
        f.len  = *len; 
        memcpy(f.data, data, 8); 

        mdaq_can_write(&f); 
    }

#endif
}


void mdaqcan_recv( char *len, unsigned int *id, unsigned char data[])
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    int result; 
    can_frame_t f; 
    
    memset((void *)&f, 0x0, sizeof(can_frame_t)); 
    
    result = mdaq_can_read(&f, 0); 
    if(result > -1)
    {
        *len = f.len; 
        *id = f.id;
        memcpy(data, f.data, 8); 
    }
    else
    {
        *len = -1;  
    } 
#endif
}

void mdaqcan_conf(unsigned int rate)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    uint32_t baud_LUT[] = {0,  B10000, 	B20000,	B50000, B100000, B125000, B250000, B500000, B800000, B1000000}; 
    
    mdaq_can_open(baud_LUT[rate]); 
    
#endif
}
