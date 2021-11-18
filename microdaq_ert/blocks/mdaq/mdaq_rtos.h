#ifndef _MDAQ_RTOS_
#define _MDAQ_RTOS_

#include <stdint.h>

#define MDAQ_SEM_NORMAL         (0)
#define MDAQ_SEM_BINARY         (1)
#define MDAQ_RTOS_NO_IPC        (0)
#define MDAQ_RTOS_WITH_IPC      (1)

typedef struct mdaq_task_params
{
    uintptr_t arg0;
    uintptr_t arg1;
    uint8_t priority; /* 1 - 31 - 1 lowest priority */
    void *stack;
    uint32_t stackSize;
}mdaq_task_params_t;

void mdaq_rtos_start(uint32_t flag, int (*init_func)(void) );
int mdaq_rtos_clock_create(float period, void (*f)(uintptr_t));
int mdaq_rtos_sem_create(int count, uint32_t type);
void mdaq_rtos_sem_post(int sem);
int mdaq_rtos_sem_pend(int sem, uint32_t timeout);
void mdaq_rtos_sem_delete(int sem);
int mdaq_rtos_task_create(void (*func)(uintptr_t, uintptr_t), mdaq_task_params_t *params);
void mdaq_rtos_task_delete(int task);
void mdaq_rtos_task_exit(void);
void mdaq_rtos_task_sleep(uint32_t nticks);
void mdaq_rtos_task_yield(void);

#endif /* _MDAQ_RTOS_ */
