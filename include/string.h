#ifndef __STRING_H__
#define __STRING_H__

#include "uart.h"
#include "stdint.h"

void putchar(char ch);
void panic(const char* string);

#endif