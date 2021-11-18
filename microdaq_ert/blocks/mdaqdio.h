#ifndef __MDAQGPIO_H
#define __MDAQGPIO_H


void DIOConfig(unsigned char enc1_func, unsigned char enc2_func, 
		unsigned char pwm1_func, unsigned char pwm2_func, unsigned char pwm3_func,
		unsigned char dir_bank1, unsigned char dir_bank2, 
		unsigned char dir_bank3, unsigned char unused1, unsigned char unused2);

void DIOInit(unsigned char pin, unsigned char dir, unsigned char init_value);
void DIOSetStep(unsigned char pin, unsigned char value);
void DIOSetTerminate(unsigned char pin, unsigned char value);
void DIOGetStep(unsigned char pin, unsigned char *value);

void DIOFncKeyInit(unsigned char func_key);
void DIOFncKeyStep(unsigned char func_key, unsigned char *value);

#endif
