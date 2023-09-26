#include "pmem.h"

#define PGROUNDUP(sz)  (((sz)+PAGE_SIZE-1) & ~(PAGE_SIZE-1))

extern char entry_stack_top[];

void allocator_init(u64 KERNEL_END, u64 PHYSICAL_MEM_END){
    
    lockit(allocator->lock);

    initLink(allocator->freelist);

    unlockit(allocator->lock);
}

void pmem_init(){
    
    static struct pmem_allocator allocator;
    allocator.freelist = NULL;
    init_lock(allocator.lock,"pmem_allocator");
    allocator.page_num = 0; 

    allocator_init();


    

}