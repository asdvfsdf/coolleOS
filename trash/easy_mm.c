#include "easy_mm.h"
#include "pmem.h"
#include "lock.h"
#include "mem_qemu_virt.h"
#include "memlayout.h"
#include "list.h"



static void easy_init(void) {
    //将空闲列表置为0，空闲列表中内存数也为0

}

//传入的地址是可分配内存的初始值
static void easy_init_memmap(struct page* base,size_t n){
    
}

//我不需要将实际物理地址和pages结构体联系在一起啊，我只管分配就行了呀
//可是最开始只有一个页啊
static struct page* easy_alloc_pages(size_t n){
    
    
    return ;

}

void easy_free_pages(struct page *base, size_t n){

}

size_t easy_nr_free_pages(){

}

static void easy_check(){
    struct page* p = NULL;
    p = easy_alloc_pages(2);
    printf("the address of the page i allocate is %x\n",p);
    struct page* p1 = NULL;
    p = easy_alloc_pages(1);
    printf("the address of the page i allocate is %x\n",p1);
}

const struct pmem_manager easy_mm = 
{
    .name = "easy_pmem_manager",
    .init = easy_init,
    .init_memmap = easy_init_memmap,
    .alloc_pages = easy_alloc_pages,
    .free_pages = easy_free_pages,
    .nr_free_pages = easy_nr_free_pages,
    .check = easy_check,
};

