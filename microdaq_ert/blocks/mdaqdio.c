#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
#include <string.h>
#include "mdaq_dio.h"
#endif 

void DIOConfig(unsigned char enc1_func, unsigned char enc2_func, 
		unsigned char pwm1_func, unsigned char pwm2_func, unsigned char pwm3_func,
		unsigned char dir_bank1, unsigned char dir_bank2, 
		unsigned char dir_bank3, unsigned char unused1, unsigned char unused2)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)

	uint8_t bank, dio; 
	mdaq_dio_init(); 

	/* set ENC function */ 
	if(enc1_func)
	{
		mdaq_dio_func(DIO6, ENC_A_FUNC); 
		mdaq_dio_func(DIO8, ENC_B_FUNC); 
	}
	else
	{
		mdaq_dio_func(DIO6, DIO_FUNC); 
		mdaq_dio_func(DIO8, DIO_FUNC); 
	}	

	if(enc2_func)
	{
		mdaq_dio_func(DIO11, ENC_A_FUNC); 
		mdaq_dio_func(DIO4, ENC_B_FUNC); 
	}
	else
	{
		mdaq_dio_func(DIO11, DIO_FUNC); 
		mdaq_dio_func(DIO4, DIO_FUNC); 
	}

	/* set PWM function */ 
	if(pwm1_func)
	{
		mdaq_dio_func(DIO7, PWM_A_FUNC); 
		mdaq_dio_func(DIO5, PWM_B_FUNC); 
	}
	else
	{
		mdaq_dio_func(DIO7, DIO_FUNC); 
		mdaq_dio_func(DIO5, DIO_FUNC); 
	}
 
	if(pwm2_func)
	{
		mdaq_dio_func(DIO22, PWM_A_FUNC); 
		mdaq_dio_func(DIO20, PWM_B_FUNC); 
	}
	else
	{
		mdaq_dio_func(DIO22, DIO_FUNC); 
		mdaq_dio_func(DIO20, DIO_FUNC); 
	}

 
	if(pwm3_func)
	{
		mdaq_dio_func(DIO1, PWM_A_FUNC); 
		mdaq_dio_func(DIO3, PWM_B_FUNC); 
	}
	else
	{
		mdaq_dio_func(DIO1, DIO_FUNC); 
		mdaq_dio_func(DIO3, DIO_FUNC); 
	}

	/* set bank1 direction DIO1-8 */ 
	bank = 1; 
	for(dio = 1; dio <= 8; dio++ )
		mdaq_dio_dir((bank - 1) * 8 + dio, (1 << (dio - 1) & dir_bank1) ? DIO_DIR_OUTPUT : DIO_DIR_INPUT); 

	bank = 2; 
	for(dio = 1; dio <= 8; dio++ )
		mdaq_dio_dir((bank - 1) * 8 + dio, (1 << (dio - 1) & dir_bank2) ? DIO_DIR_OUTPUT : DIO_DIR_INPUT); 

	bank = 3; 
	for(dio = 1; dio <= 8; dio++ )
		mdaq_dio_dir((bank - 1) * 8 + dio, (1 << (dio - 1) & dir_bank3) ? DIO_DIR_OUTPUT : DIO_DIR_INPUT); 
	

#endif    
}


void DIOInit(unsigned char pin, unsigned char dir, unsigned char init_value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
	mdaq_dio_init(); 
	if(init_value == 1)
		mdaq_dio_write(pin, DIO_STATE_LOW);
	else if (init_value == 2)
		mdaq_dio_write(pin, DIO_STATE_HIGH);

#endif    
}
void DIOSetStep(unsigned char pin, unsigned char value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    mdaq_dio_write(pin, value); 
#endif    
}

void DIOSetTerminate(unsigned char pin, unsigned char value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
	if(value == 1)
		mdaq_dio_write(pin, DIO_STATE_LOW);
	else if (value == 2)
		mdaq_dio_write(pin, DIO_STATE_HIGH);

#endif    
}

void DIOGetStep(unsigned char pin, unsigned char *value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    *value = mdaq_dio_read(pin); 
#endif    
}

void DIOFncKeyStep(unsigned char func_key, unsigned char *value)
{
#if (!defined MATLAB_MEX_FILE) && (!defined MDL_REF_SIM_TGT)
    if ( func_key == 1 ) 
        *value = mdaq_dio_read(F1);
    else if ( func_key == 2 ) 
        *value = mdaq_dio_read(F2);
#endif    
}


