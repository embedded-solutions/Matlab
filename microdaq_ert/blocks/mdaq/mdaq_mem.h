/* mdaq_mem.h -- Simple memory allocator for MicroDAQ device
 *
 * Copyright (C) 2021 Embedded Solutions
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 */

#ifndef _MDAQ_MEM_H_
#define _MDAQ_MEM_H_

#include <stdint.h>


#define MDAQ_USER_MEMORY_BASE       (0xe8000000)
#define MDAQ_USER_MEMORY_SIZE       (0x08000000)        /* 128 MB */

/*
 * Shall be used when IPC with zero-copy is required
 * It allocates memory from internal shared pool region
 * Returns pointer to memory or NULL if not able to allocate
 *
 * This is simple memory allocator for max performance,
 * it does not implements deallocation!
 *
 */
void *mdaq_malloc(uint32_t size);

#endif /* _MDAQ_MEM_H_ */

