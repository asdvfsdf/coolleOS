#ifndef __TRAP_INIT_H__
#define __TRAP_INIT_H__

#include "stdio.h"
#include "register.h"

static inline void trap_enable(void){
    set_sstatus_bit_1(SSTATUS_SIE);
}

static inline void trap_disable(void){
    set_sstatus_bit_0(SSTATUS_SIE);
}

void trap_init();


#endif