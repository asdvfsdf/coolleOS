#include "easy_mem.h"
#include "stdio.h"
#include "mem_qemu_virt.h"

static struct easy_page* page_start;

static u64 constant;

static u64 page_not;

static u64 page_num;

//这什么几把问题啊，太几把抽象了吧

void easy_init_mem(){
    
    printf("the mem manager is easy mem\n");    
    printf("the mem:\n");
    printf("%x--opensbi--%x--kernel--%x--memory--%x\n",PHYSICAL_MEM_BEGAIN,KERNEL_BASE,KERNEL_END,PHYSICAL_MEM_END);

    //8个4k正好可以管理128M,但是前面的opensbi和内核部分和page部分是要求始终不动的，这是初始化要做的

    page_start = (struct easy_page*)ROUNDUP(KERNEL_END,PAGE_SIZE);

    page_num = (PHYSICAL_MEM_END - PHYSICAL_MEM_BEGAIN) / PAGE_SIZE;

    constant = (u64)ROUNDUP((u64)page_start + ((u64)(sizeof(struct easy_page))) * page_num,PAGE_SIZE);

    printf("the num of page is %x,the start of mem to allocate is %x\n",page_num,constant);

    page_not = (constant - PHYSICAL_MEM_BEGAIN) /PAGE_SIZE;

    u64 page_can = page_num - page_not;

    printf("the start of page that can be allocate is %x\n",page_not);

    for(u64 i = 0; i < page_not;i++){
        page_start[i].flags = 1;
        //printf("%x is unallocatable\n",i);
    }
   

    for(u64 i = page_not;i < page_num;i++){
        page_start[i].flags = 0;
        //printf("%x is allocatable\n",i);
    }

    printf("the init is ok!\n");
    
} 
//找空闲页（大小合适），地址转换（page到实际地址）
u64 easy_alloc(u64 num){

    int alloc = 0;

    for(u64 i = page_not; i < page_num; i++){
        alloc = i;
        if (page_start[i].flags == 0)
        {   
            int n = 1; int flag = 0;

            while(page_start[++i].flags == 0){
                n++;
                if(n == num){
                    printf("i find it\n");
                    flag = 1;
                    break;   
                }
            }

            if(flag == 1){
                break;
            }else{
                i += n-1;
            }
            
        }
    }

    printf("the allocated page is %x\n",alloc);

    for (size_t i = alloc; i < alloc + num; i++)
    {
        page_start[i].flags = 1;
    }

    u64 ret = PHYSICAL_MEM_BEGAIN + alloc*4096;

    printf("the physical address of the allocated page is %x\n",ret);

    //返回page_start[alloc]对应物理页的地址
    return ret;
}