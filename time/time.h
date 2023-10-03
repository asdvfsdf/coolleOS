#ifndef __TIME_H__
#define __TIME_H__

#include "stdint.h"
#include "register.h"
#include "sbi.h"

extern volatile size_t tictok;

static uint64_t timebase = 1000;

static inline unsigned long get_time(void){
    
    unsigned long x;
    asm volatile("rdtime %0" : "=r"(x));
    return x;
}

void clock_set_next_event();


void clock_init();

#endif