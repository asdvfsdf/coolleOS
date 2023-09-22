/* mostly come from riscv-spi document */
#ifndef _SBI_H
#define _SBI_H

#include "stdio.h"
#include "stdint.h"
#include "stdarg.h"
#include "string.h"

//Standard SBI Errors 
#define SBI_SUCCESS 0
#define SBI_ERR_FAILED -1
#define SBI_ERR_NOT_SUPPORTED -2
#define SBI_ERR_INVALID_PARAM -3
#define SBI_ERR_DENIED -4
#define SBI_ERR_INVALID_ADDRESS -5
#define SBI_ERR_ALREADY_AVAILABLE -6
#define SBI_ERR_ALREADY_STARTED -7
#define SBI_ERR_ALREADY_STOPPED -8
#define SBI_ERR_NO_SHMEM -9

//Legacy Function List
#define LEGACY_FUNC_FID 0
#define SBI_SET_TIMER 0
#define SBI_CONSOLE_PUTCHAR 1
#define SBI_CONSOLE_GETCHAR 2
#define SBI_CLEAR_IPI 3
#define SBI_SEND_IPI 4
#define SBI_REMOTE_FENCE_I 5
#define SBI_REMOTE_SFENCE_VMA 6
#define SBI_REMOTE_SFENCE_VMA_ASID 7
#define SBI_SHUTDOWN 8

//Base Extension
#define BASE_EXTENSION_EID 0x10
#define SBI_GET_SPEC_VERSION 0
#define SBI_GET_IMPL_ID 1
#define SBI_GET_IMPL_VERSION 2
#define SBI_PROBE_EXTENSION 3
#define SBI_GET_MVENDORID 4
#define SBI_GET_MARCHID 5
#define SBI_GET_MIMPID 6

typedef struct sbiret {
        long error;
        long value;
}sbiret;

sbiret sbi_ecall(int eid, int fid, unsigned long arg0,unsigned long arg1, unsigned long arg2,unsigned long arg3, unsigned long arg4,unsigned long arg5);

//sbi base extension
long sbi_base_ecall(int fid, ...);
long sbi_get_spec_version(void);
long sbi_get_impl_id(void);
long sbi_probe_extension(long extension_id);
long sbi_get_mvendorid(void);
long sbi_get_marchid(void);
long sbi_get_mimpid(void);

//sbi legacy extension
long sbi_set_timer(uint64_t stime_value);
void sbi_putchar(int ch);
long sbi_getchar(void);


#endif
