#include "sbi.h"
#include "string.h"
#include "exception.h"
#include "syscall.h"
#include "time.h"

void main()
{
    panic("CoolleOS welcome!\n");
    const_set_stvec();
    enable_time_interrupt();
    init_time();
    interrupt_enable();
    internal_syscall(0,0,0,0,0,0,0);
}