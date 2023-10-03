#ifndef __TRAP_HELPER_H__
#define __TRAP_HELPER_H__

#include "stdint.h"

#define IRQ_U_SOFT   0
#define IRQ_S_SOFT   1
#define IRQ_H_SOFT   2
#define IRQ_M_SOFT   3
#define IRQ_U_TIMER  4
#define IRQ_S_TIMER  5
#define IRQ_H_TIMER  6
#define IRQ_M_TIMER  7
#define IRQ_U_EXT    8
#define IRQ_S_EXT    9
#define IRQ_H_EXT    10
#define IRQ_M_EXT    11
#define IRQ_COP      12
#define IRQ_HOST     13

#define CAUSE_MISALIGNED_FETCH 0x0
#define CAUSE_FAULT_FETCH 0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_BREAKPOINT 0x3
#define CAUSE_MISALIGNED_LOAD 0x4
#define CAUSE_FAULT_LOAD 0x5
#define CAUSE_MISALIGNED_STORE 0x6
#define CAUSE_FAULT_STORE 0x7
#define CAUSE_USER_ECALL 0x8
#define CAUSE_SUPERVISOR_ECALL 0x9
#define CAUSE_HYPERVISOR_ECALL 0xa
#define CAUSE_MACHINE_ECALL 0xb

struct commregs {
    u64 zero;  // Hard-wired zero
    u64 ra;    // Return address
    u64 sp;    // Stack pointer
    u64 gp;    // Global pointer
    u64 tp;    // Thread pointer
    u64 t0;    // Temporary
    u64 t1;    // Temporary
    u64 t2;    // Temporary
    u64 s0;    // Saved register/frame pointer
    u64 s1;    // Saved register
    u64 a0;    // Function argument/return value
    u64 a1;    // Function argument/return value
    u64 a2;    // Function argument
    u64 a3;    // Function argument
    u64 a4;    // Function argument
    u64 a5;    // Function argument
    u64 a6;    // Function argument
    u64 a7;    // Function argument
    u64 s2;    // Saved register
    u64 s3;    // Saved register
    u64 s4;    // Saved register
    u64 s5;    // Saved register
    u64 s6;    // Saved register
    u64 s7;    // Saved register
    u64 s8;    // Saved register
    u64 s9;    // Saved register
    u64 s10;   // Saved register
    u64 s11;   // Saved register
    u64 t3;    // Temporary
    u64 t4;    // Temporary
    u64 t5;    // Temporary
    u64 t6;    // Temporary
};

struct context
{
    struct commregs commregs;
    u64 status;
    u64 epc;
    u64 badvaddr;
    u64 cause;
};


void trap_helper();


#endif