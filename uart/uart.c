#include "stdint.h"

//疑似：https://github.com/qemu/qemu/blob/master/include/hw/riscv/opentitan.h
//疑似：https://github.com/qemu/qemu/blob/master/hw/riscv/opentitan.c#L207

#define UART_BASE 0x10000000

#define UART_RBR 0x0
#define UART_THR 0x0
#define UART_IER 0x1
#define UART_IIR 0x2
#define UART_FCR 0x2
#define UART_LCR 0x3
#define UART_MCR 0x4
#define UART_LSR 0x5
#define UART_MSR 0x6
#define UART_SCR 0x7


static inline volatile uint8_t *R(int off) {
    return (volatile uint8_t *)((uint8_t *)UART_BASE + off);
}

void myputchar(char c) {
    *(char *)R(UART_THR) = c;
}

char mygetchar() {
    return *(char *)R(UART_RBR);
}



