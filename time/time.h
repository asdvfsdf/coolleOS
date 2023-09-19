#ifndef __TIME_H__
#define __TIME_H__
#include "stdint.h"

static inline uint64_t return_time(){
    uint64_t t;
    asm volatile("csrr %0, time":"=r"(t));
    return t;
}

void init_time();

#endif