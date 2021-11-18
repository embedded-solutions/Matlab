/* mdaq_ai.h -- Adc driver for MicroDAQ device
 *
 * Copyright (C) 2013 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef MDAQ_AI_H
#define MDAQ_AI_H

#include <stdint.h>

/* AI channel id */
enum mdaq_ai_channel_id
{
    AI1 = 1,
    AI2,
    AI3,
    AI4,
    AI5,
    AI6,
    AI7,
    AI8,
    AI9,
    AI10,
    AI11,
    AI12,
    AI13,
    AI14,
    AI15,
    AI16,
    AI17,
    AI18,
    AI19,
    AI20,
    AI21,
    AI22,
    AI23,
    AI24,
    AI25,
    AI26,
    AI27,
    AI28,
    AI29,
    AI30,
    AI31,
    AI32,
    AI33,
    AI34,
    AI35,
    AI36,
    AI37,
    AI38,
    AI39,
    AI40,
    AI41,
    AI42,
    AI43,
    AI44,
    AI45,
    AI46,
    AI47,
    AI48
};

enum mdaq_ai_error_id
{
    ERR_AI_CHANNEL_NO          = 1,
    ERR_AI_RANGE               = 2,
    ERR_AI_MODE                = 3,
    ERR_AI_POLARITY            = 4,
    ERR_AI_MULTI_RANGE         = 5,
    ERR_AI_CONSEC_CHANNEL      = 6,
    ERR_AI_FIRST_CHANNEL       = 7,
    ERR_AI_DIFF_MODE           = 8,
    ERR_AI_DIFF_CHANNEL        = 9,
    ERR_AI_SINGLE_MODE         = 10,
    ERR_AI_SINGLE_CHANNEL      = 11,
    ERR_AI_FREQ                = 12,
    ERR_AI_HWID                = 13,
    ERR_AI_NOT_INITIALIZED     = 14,
    ERR_AI_CH_NOT_INITIALIZED  = 15
}; 

/* Terminal configuration */
#define AI_SINGLE               (1 << 28)
#define AI_DIFF                 (1 << 29)

int mdaq_ai_init(void);
int mdaq_ai_config_ch(uint8_t ch[], uint8_t ch_count, float range[], uint32_t opt[]);
int mdaq_ai_read(uint8_t ch[], uint8_t ch_count, double *data);
int mdaq_ai_read_raw( uint8_t ch[], uint8_t ch_count, int32_t *data);
int mdaq_ai_read2(uint8_t ch[], uint8_t ch_count, uint32_t oversampling, double *data);
int mdaq_ai_scan_init(uint8_t ch[], uint8_t ch_count, float *range, uint8_t *mode, int32_t scan_count, float *freq);
void mdaq_ai_info(void);

#endif /* MDAQ_AI_H */
