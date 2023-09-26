#include "pmem.h"

extern char entry_stack_top[];

void allocator_init(struct pmem_allocator* allocator){
    
    lockit(allocator->lock);

    initLink(allocator->freelist);

    unlockit(allocator->lock);
}

void pmem_init(){
    
    static struct pmem_allocator allocator;
    allocator.freelist = NULL;
    init_lock(allocator.lock,"pmem_allocator");
    allocator.page_num = 0; 

    allocator_init(&allocator);


    

}