#include "sbi.h"
#include "uart.h"

void main()
{
    SBI_PUTCHAR('H');
    SBI_PUTCHAR('e');
    SBI_PUTCHAR('l');
    SBI_PUTCHAR('l');
    SBI_PUTCHAR('o');
    SBI_PUTCHAR('\n');
    myputchar('f');
    while(1) {}
}
