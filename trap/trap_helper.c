#include "trap_helper.h"
#include "time.h"
#include "stdio.h"

#define TICK_NUM 100

void print_regs(struct commregs* commregs) {
    printf("  zero     %x\n", commregs->zero);
    printf("  ra       %x\n", commregs->ra);
    printf("  sp       %x\n", commregs->sp);
    printf("  gp       %x\n", commregs->gp);
    printf("  tp       %x\n", commregs->tp);
    printf("  t0       %x\n", commregs->t0);
    printf("  t1       %x\n", commregs->t1);
    printf("  t2       %x\n", commregs->t2);
    printf("  s0       %x\n", commregs->s0);
    printf("  s1       %x\n", commregs->s1);
    printf("  a0       %x\n", commregs->a0);
    printf("  a1       %x\n", commregs->a1);
    printf("  a2       %x\n", commregs->a2);
    printf("  a3       %x\n", commregs->a3);
    printf("  a4       %x\n", commregs->a4);
    printf("  a5       %x\n", commregs->a5);
    printf("  a6       %x\n", commregs->a6);
    printf("  a7       %x\n", commregs->a7);
    printf("  s2       %x\n", commregs->s2);
    printf("  s3       %x\n", commregs->s3);
    printf("  s4       %x\n", commregs->s4);
    printf("  s5       %x\n", commregs->s5);
    printf("  s6       %x\n", commregs->s6);
    printf("  s7       %x\n", commregs->s7);
    printf("  s8       %x\n", commregs->s8);
    printf("  s9       %x\n", commregs->s9);
    printf("  s10      %x\n", commregs->s10);
    printf("  s11      %x\n", commregs->s11);
    printf("  t3       %x\n", commregs->t3);
    printf("  t4       %x\n", commregs->t4);
    printf("  t5       %x\n", commregs->t5);
    printf("  t6       %x\n", commregs->t6);
}

void print_trapframe(struct context* context) {
    printf("trapframe at %x\n", context);
    print_regs(&(context->commregs));
    printf("  status   %x\n", context->status);
    printf("  epc      %x\n", context->epc);
    printf("  badvaddr %x\n", context->badvaddr);
    printf("  cause    %x\n", context->cause);
}

void interrupt_handler(struct context* context){
    int64_t cause = (context->cause << 1) >> 1;
    switch (cause) {
        case IRQ_U_SOFT:
            printf("User software interrupt\n");
            break;
        case IRQ_S_SOFT:
            printf("Supervisor software interrupt\n");
            break;
        case IRQ_H_SOFT:
            printf("Hypervisor software interrupt\n");
            break;
        case IRQ_M_SOFT:
            printf("Machine software interrupt\n");
            break;
        case IRQ_U_TIMER:
            printf("User Timer interrupt\n");
            break;
        case IRQ_S_TIMER:
            clock_set_next_event();
            if (++tictok % TICK_NUM == 0) {
                printf("time interrupted\n");
            }
            break;
        case IRQ_H_TIMER:
            printf("Hypervisor software interrupt\n");
            break;
        case IRQ_M_TIMER:
            printf("Machine software interrupt\n");
            break;
        case IRQ_U_EXT:
            printf("User software interrupt\n");
            break;
        case IRQ_S_EXT:
            printf("Supervisor external interrupt\n");
            break;
        case IRQ_H_EXT:
            printf("Hypervisor software interrupt\n");
            break;
        case IRQ_M_EXT:
            printf("Machine software interrupt\n");
            break;
        default:
            //print_trapframe(tf);
            break;
    }
}


void exception_handler(struct context* context){
    switch (context->cause) {
        case CAUSE_MISALIGNED_FETCH:
            break;
        case CAUSE_FAULT_FETCH:
            break;
        case CAUSE_ILLEGAL_INSTRUCTION:
            break;
        case CAUSE_BREAKPOINT:
            break;
        case CAUSE_MISALIGNED_LOAD:
            break;
        case CAUSE_FAULT_LOAD:
            break;
        case CAUSE_MISALIGNED_STORE:
            break;
        case CAUSE_FAULT_STORE:
            break;
        case CAUSE_USER_ECALL:
            break;
        case CAUSE_SUPERVISOR_ECALL:
            break;
        case CAUSE_HYPERVISOR_ECALL:
            break;
        case CAUSE_MACHINE_ECALL:
            break;
        default:
            //print_trapframe(tf);
            break;
    }
}


//这里要分类并跳入对应的处理单元
void trap_helper(struct context* context){
    //scause对是对的，但这玩意为什么那么长啊？
    
    //printf("%x\n",(u64)context->casue);

    if((int64_t)context->cause < 0){
        interrupt_handler(context);
    }else{
        exception_handler(context);
    }

}