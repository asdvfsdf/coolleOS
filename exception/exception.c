#include "exception.h"
#include "string.h"
#include "syscall.h"


void table_val_set(void){

}

void interrupt_disable(void){
    set_sie(0);
    set_sip(0);
}

//开启时钟中断实际上是设置Supervisor Interrupt Enable(sie)
void interrupt_enable(void){
    set_sstatus(get_sstatus()|SSTATUS_SIE);
}

//通过设置SIE位就可以达到使能或者关闭中断的作用
void enable_time_interrupt(void){
    set_sie(get_sie()|SIE_SEIE);
}




void diff_exception()
{   
    panic("diff it\n");
    // uint64_t cause = c->scause & ~(1ul << 63);
    // if (c->scause & (1ul << 63))
    // {
    //         panic("I have no idea about this");
    // }
    // else
    // {
    //     switch(cause)
    //     {
    //         case EXC_U_SYSCALL:
    //             handle_syscall(c);
    //             c->sepc += 4;
    //     }
    // }
}