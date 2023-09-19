#include "syscall.h"
#include "string.h"
#include "exception.h"

void handle_syscall(Context *c)
{   
    switch(c->gpr[17])
    {
        case SYS_io_setup:
            panic("unimplemented syscall io_setup");
            break;
    }
}


