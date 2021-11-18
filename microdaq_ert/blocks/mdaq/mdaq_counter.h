
/* mdaq_counter.h -- counter driver for MicroDAQ device
 *
 * Copyright (C) 2020 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

/*
 * MicroDAQ Counter is a 64bit counter which is started by default
 * on system boot. The counter can only be read, user is not allowed
 * to change its state.
 */
#ifndef MDAQ_COUNTER_H_
#define MDAQ_COUNTER_H_

#include <stdint.h>

#define MDAQ_COUNTER0             (0u)
#define MDAQ_COUNTER1             (1u)

/* Counter frequency 200MHz */
#define MDAQ_COUNTER_FREQ         (200000000)

#define MDAQ_COUNTER_CYC_PER_US   (200)
#define MDAQ_COUNTER_CYC_PER_MS   (200000)
#define MDAQ_COUNTER_CYC_PER_SEC  (200000000)

uint64_t mdaq_counter_read(uint8_t timer);
void mdaq_usleep(uint32_t us);

#endif /* MDAQ_COUNTER_H_ */
