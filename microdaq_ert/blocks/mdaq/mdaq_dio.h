/* mdaq_dio.h -- DIO driver for MicroDAQ device
 *
 * Copyright (C) 2013-2021 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */ 

#ifndef MDAQ_DIO_
#define MDAQ_DIO_

#include <stdint.h>

#define DIO_ERROR           (0xff)
#define DIO_STATE_LOW       (0)
#define DIO_STATE_HIGH      (1)

#define DIO_DIR_OUTPUT      (0)
#define DIO_DIR_INPUT       (1)

#define DIO_FUNC_SET        (0)
#define DIO_FUNC_UNSET      (1)

/* DIO channels */
enum mdaq_dio_ids
{
	DIO1 = 1,
	DIO2, 
	DIO3, 
	DIO4, 
	DIO5, 
	DIO6, 
	DIO7, 
	DIO8, 
	DIO9, 
	DIO10, 
	DIO11, 
	DIO12, 
	DIO13, 
	DIO14, 
	DIO15, 
	DIO16,
	DIO17,
	DIO18,
	DIO19,
	DIO20,
	DIO21,
	DIO22,
	DIO23,
	DIO24,
	F1,
	SYS,
	F2,
	D1,
	D2,
};


enum mdaq_bank_ids
{
	DIO_BANK1 = 1,
	DIO_BANK2,
	DIO_BANK3,
	DIO_BANK4
};

enum mdaq_dio_func_ids
{
    DIO_FUNC = 0,
    ENC_A_FUNC,
	ENC_B_FUNC,
	ENC_I_FUNC,
	ENC_S_FUNC,
	PWM_A_FUNC,
	PWM_B_FUNC,
	CNT_FUNC,
	AI_CLK_FUNC,
	AO_CLK_FUNC,
	UART_TX_FUNC,
    UART_RX_FUNC,
    HS_DO_FUNC,
    HS_DI_FUNC,
};

enum mdaq_bank_dir_ids
{
    DIO_OUTPUT = 0,
    DIO_INPUT = 1
};

uint8_t mdaq_dio_init( void);
uint8_t mdaq_dio_is_initialized(void);
uint8_t mdaq_dio_dir( uint8_t dio, uint8_t dir);
uint8_t mdaq_bank_dir( uint8_t bank, uint8_t dir);

uint8_t mdaq_dio_write( uint8_t dio, uint8_t value);
uint8_t mdaq_dio_read( uint8_t dio);

uint8_t mdaq_dio_func( uint8_t dio, uint8_t function);

#endif /* MDAQ_DIO_ */ 
