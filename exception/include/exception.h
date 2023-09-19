#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "stdint.h"

// Supervisor Interrupt Enable
#define SIE_SEIE (1L << 9) // external
#define SIE_STIE (1L << 5) // timer
#define SIE_SSIE (1L << 1) // software

// Supervisor Status Register, sstatus
#define SSTATUS_SPP (1L << 8)  // Previous mode, 1=Supervisor, 0=User
#define SSTATUS_SPIE (1L << 5) // Supervisor Previous Interrupt Enable
#define SSTATUS_UPIE (1L << 4) // User Previous Interrupt Enable
#define SSTATUS_SIE (1L << 1)  // Supervisor Interrupt Enable
#define SSTATUS_UIE (1L << 0)  // User Interrupt Enable



#define IRQ_S_SOFT  1
#define IRQ_S_TIMER 5
#define IRQ_S_EXT   9

#define EXC_INST_MISALIGNED   0
#define EXC_INST_ACCESS       1
#define EXC_BREAKPOINT        3
#define EXC_LOAD_MISALIGNED   4
#define EXC_LOAD_ACCESS       5
#define EXC_STORE_MISALIGNED  6
#define EXC_STORE_ACCESS      7
#define EXC_U_SYSCALL         8
#define EXC_S_SYSCALL         9
#define EXC_INST_PAGE_FAULT   12
#define EXC_LOAD_PAGE_FAULT   13
#define EXC_STORE_PAGE_FAULT  15

typedef struct Context
{
    uint64_t gpr[32];
    uint64_t scause;
    uint64_t sstatus;
    uint64_t sepc; 
}Context;


static inline uint64_t get_sie(){
    uint64_t x;
    asm volatile("csrr %0, sie" : "=r"(x));
    return x;
}

static inline uint64_t get_sip(){
    uint64_t x;
    asm volatile("csrr %0, sip" : "=r"(x));
    return x;
}

static inline void set_sie(uint64_t x){
    asm volatile("csrw sie, %0" : : "r"(x));
}

static inline void set_sip(uint64_t x){
    asm volatile("csrw sip, %0" : : "r"(x));
}

static inline uint64_t get_sstatus(){
    uint64_t x;
    asm volatile("csrr %0, sstatus" : "=r"(x));
    return x;
}

static inline void set_sstatus(uint64_t x){
    asm volatile("csrw sstatus, %0" : : "r"(x));
}

static inline void set_stvec(uint64_t x){
    asm volatile("csrw stvec, %0" : : "r"(x));
}

//这玩意应该在内核一开始就进行
extern void trap_entry();

static inline void  const_set_stvec(){
    asm volatile("csrw stvec, %0" : : "r"(trap_entry));
}

void table_val_set(void);
void interrupt_disable(void);
void interrupt_enable(void);
void enable_time_interrupt(void);
void init_exception();


#endif




















