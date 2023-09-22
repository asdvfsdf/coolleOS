#include "sbi.h"


sbiret sbi_ecall(int eid, int fid, unsigned long arg0,
            unsigned long arg1, unsigned long arg2,unsigned long arg3,
            unsigned long arg4,unsigned long arg5){

	struct sbiret ret;

	register unsigned long a0 asm ("a0") = (unsigned long)(arg0);
	register unsigned long a1 asm ("a1") = (unsigned long)(arg1);
	register unsigned long a2 asm ("a2") = (unsigned long)(arg2);
	register unsigned long a3 asm ("a3") = (unsigned long)(arg3);
	register unsigned long a4 asm ("a4") = (unsigned long)(arg4);
	register unsigned long a5 asm ("a5") = (unsigned long)(arg5);
	register unsigned long a6 asm ("a6") = (unsigned long)(fid);
	register unsigned long a7 asm ("a7") = (unsigned long)(eid);
	asm volatile ("ecall"
		      : "+r" (a0), "+r" (a1)
		      : "r" (a2), "r" (a3), "r" (a4), "r" (a5), "r" (a6), "r" (a7)
		      : "memory");
	
    ret.error = a0;
	ret.value = a1;

	return ret;
}



long sbi_base_ecall(int fid, ...){

	va_list pArgs = NULL;
	va_start(pArgs,fid);
	long vArgs = va_arg(pArgs,long);

	sbiret ret;

	ret = sbi_ecall(BASE_EXTENSION_EID, fid, vArgs, 0, 0, 0, 0, 0);

	va_end(pArgs);

	if (!ret.error){
		return ret.value;
	}
	else{
		return ret.error;
	}

}

void sbi_putchar(int ch){

    sbi_ecall(SBI_CONSOLE_PUTCHAR,LEGACY_FUNC_FID,ch,0,0,0,0,0);

}

long sbi_set_timer(uint64_t stime_value){

	sbiret ret;

	ret = sbi_ecall(SBI_SET_TIMER,LEGACY_FUNC_FID,stime_value, 0, 0, 0, 0, 0);

	if (!ret.error){
		return ret.value;
	}
	else{
		return ret.error;
	}
	
}

long sbi_getchar(void){
	sbiret ret;

	ret = sbi_ecall(SBI_CONSOLE_GETCHAR,LEGACY_FUNC_FID, 0, 0, 0, 0, 0, 0);

	if (!ret.error){
		return ret.value;
	}
	else{
		return ret.error;
	}
	
}

long sbi_get_spec_version(void){

	return sbi_base_ecall(SBI_GET_SPEC_VERSION);

}

long sbi_get_impl_id(void){
	return sbi_base_ecall(SBI_GET_IMPL_ID);
}

long sbi_probe_extension(long extension_id){
	return sbi_base_ecall(SBI_PROBE_EXTENSION,extension_id);
}

long sbi_get_mvendorid(void){
	return sbi_base_ecall(SBI_GET_MVENDORID);
}

long sbi_get_marchid(void){
	return sbi_base_ecall(SBI_GET_MARCHID);
}

long sbi_get_mimpid(void){
	return sbi_base_ecall(SBI_GET_MIMPID);
}