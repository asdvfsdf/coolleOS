#ifndef __STDIO_H__
#define __STDIO_H__

#include "sbi.h"
#include "string.h"
#include "stdarg.h"


void putchar(char ch);
void panic(const char* string);
int printf(const char* format, ...);


#endif