#ifndef __PMEM_H__
#define __PMEM_H__

#include "stddef.h"
#include "mem_qemu_virt.h"
#include "stdint.h"
#include "memlayout.h"

extern struct page* pages;
extern size_t npage;
extern const size_t nbase;
extern uint64_t va_pa_offset;

#define PGROUNDUP(sz)  (((sz)+PHYSICAL_PAGE_SIZE-1) & ~(PHYSICAL_PAGE_SIZE-1))
#define PGROUNDDOWN(a) (((a)) & ~(PHYSICAL_PAGE_SIZE-1))

#define PPN(la) (((uintptr_t)(la)) >> PHYSICAL_PAGE_SHIFT)

struct pmem_manager
{
    const char* name;
    void (*init)(void);
    void (*init_memmap)(struct page* base,size_t n);
    struct page *(*alloc_pages)(size_t n); 
    void (*free_pages)(struct page *base, size_t n);  
    size_t (*nr_free_pages)(void);  
    void (*check)(void);            
};

static inline struct page* pa2page(uintptr_t pa) {

    if (PPN(pa) >= npage) {
        panic("pa2page called with invalid pa");
    }
    return &(pages[PPN(pa) - nbase]);
}


void mem_init();

void init_manager();

#endif