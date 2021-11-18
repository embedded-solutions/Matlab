/* mdaq_ao.h -- DAC driver for MicroDAQ device
 *
 * Copyright (C) 2013-2021 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef MDAQ_AO_H
#define MDAQ_AO_H

#include <stdint.h>

/* AO channel IDs */
enum mdaq_ao_ids
{
    AO1 = 1,
    AO2,
    AO3,
    AO4,
    AO5,
    AO6,
    AO7,
    AO8,
    AO9,
    AO10,
    AO11,
    AO12,
    AO13,
    AO14,
    AO15,
    AO16,
    AO17,
    AO18,
    AO19,
    AO20,
    AO21,
    AO22,
    AO23,
    AO24,
};

enum mdaq_ao_error_id
{
    ERR_AO_CHANNEL             = 1,
    ERR_AO_RANGE               = 2,
    ERR_AO_MODE                = 3,
    ERR_AO_FREQ                = 4,
    ERR_AO_HWID                = 5
};

int mdaq_ao_init(void);
int mdaq_ao_write( uint8_t ch[], uint8_t ch_count, const double *value);
int mdaq_ao_config_ch(uint8_t ch[], uint8_t ch_count, float range[]);
int mdaq_ao_scan_prepare_data(uint8_t ch, uint8_t range, double *value, uint32_t sample_count);
void mdaq_ao_info(void);

#endif /* MDAQ_AO_H */
