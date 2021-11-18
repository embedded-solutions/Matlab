/* mdaq_pru.h -- PRU driver for MicroDAQ device
 *
 * Copyright (C) 2021 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef _MDAQ_PRU_H_
#define _MDAQ_PRU_H_

#include <stdint.h>

uint16_t mdaq_pru_write(uint16_t dst, const uint8_t *src,  uint16_t size);
uint16_t mdaq_pru_read(uint16_t dst, uint8_t *src, uint16_t size);

#endif /* _MDAQ_PRU_H_ */

