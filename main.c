#include "sbi.h"
#include "string.h"


void main()
{
    SBI_PUTCHAR('H');
    SBI_PUTCHAR('e');
    SBI_PUTCHAR('l');
    SBI_PUTCHAR('l');
    SBI_PUTCHAR('o');
    SBI_PUTCHAR('\n');
    panic("OS is a fucking bitch");

    while(1) {}
}
