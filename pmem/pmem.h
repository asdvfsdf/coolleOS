#ifndef __PMEM_H__
#define __PMEM_H__

#include "lock.h"
#include "mem_qemu_virt.h"
#include "link.h"
#include "stdint.h"

extern char entry_stack_top[];


struct pmem_allocator
{
    struct lock* lock;
    Link* freelist;
    u64 page_num;

};

void pmem_init();





#endif