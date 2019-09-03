#include <stdio.h>
#include "implicit_head.h"

#define SET_FREE(header) ((header) & 0xefffffff)
#define SET_OCCUPIED(header) ((header) | 0x80000000)

void* memInit(void* buffer,int size)
{
    buffer = malloc(size + 4);
    if(buffer==NULL)
    {
        return 0;
    }
    ((int *)buffer)[0] = size;    
    ((int *)buffer)[1] = size - 4;  
    return buffer;    
}

void* memAlloc(void* buffer,int size)//size = 15
{
    if(size > 2147483648){
        return 0;
    }
    
    int bytesToEnd = ((int *)buffer)[0] - 4;
    
    void *header = buffer + 4;
    int block_size = blockSize(header);

    while(!(isFree(header) && block_size >= size))
    {                
        if(bytesToEnd - 4 - block_size==0){
            return 0;
        }        
        bytesToEnd = bytesToEnd - 4 - block_size;
        header = getNextBlock(header);        
        block_size = blockSize(header);        
    }    
        
    if(block_size - 4 - size > 0){
        ((int*)header)[0] = size;
        ((int*)header)[0] = SET_OCCUPIED(((int*)header)[0]);
        ((int*)(header + 4 + size))[0] = block_size - 4 - size;
    }
    else{
        ((int*)header)[0] = SET_OCCUPIED(((int*)header)[0]);
        return header;
    }
    return header;

}

 int blockSize(header)
 {
    return SET_FREE(((int*)header)[0]);
 }



void * getNextBlock(void* header)
{
    return header+ SET_FREE(((int *)header)[0])+4;
}
int isFree(int header){
    if(0x80000000 & header == 0x80000000){
        return 0;
    }
    else{
        return 1;
    }
}

void* memFree(void* header)
{
    
}