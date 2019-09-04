#include <stdio.h>

#include "implicit_head.h"

#define SET_FREE(header) ((header) & 0xefffffff)
#define SET_OCCUPIED(header) ((header) | 0x80000000)

void* memInit(void* buffer,int size)
{
	if(buffer==NULL)
	{
		return 0;
	}
	
	//buffer = (char*)buffer + 1;// for test

	if(((unsigned long)buffer)%4!=0)
	{
		size = size-(4-((unsigned long)buffer)%4);
		if(size%4!=0)
		{
			size = size-(size%4);
		}
		
		buffer = (char*)buffer + (4-((unsigned long)buffer)%4);
		
	}

	((int *)buffer)[0] = size; //1000   
	((int *)buffer)[1] = size - 4;  //the first header 996
	
	return buffer;    
}


int blockSize(void *header)
{
   return SET_FREE(((int*)header)[0]);
}


int isFree(void * header)
{
	if(0x80000000 & *((int*)header) == 0x80000000)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void * getNextBlock(void* header)
{
    return header+ SET_FREE(((int *)header)[0])+4;
}




void * memAlloc(void* buffer,int size)
{
	if(size > 2147483647 || SET_FREE(((int *)buffer)[0]) == 0)//2^31 0111111111111....
	{
		return 0;
    	}
    
	int bytesToEnd = ((int *)buffer)[0] - 4;

	void *header = buffer + 4;//9992
	int block_size = blockSize(header);//9992

	while(!(isFree(header) && block_size >= size))
	{                
		if(bytesToEnd - 4 - block_size==0)//the next block is in the end
		{
			return 0;
        	}        
		bytesToEnd = bytesToEnd - 4 - block_size;
		header = getNextBlock(header);        
		block_size = blockSize(header);        
	}    
        
	if((block_size - 4) - size > 0 && (block_size - 4) - size > 4)//if you choose the big memory then split it
	{
        	((int*)header)[0] = size;
        	((int*)header)[0] = SET_OCCUPIED(((int*)header)[0]);
        	((int*)(header + 4 + size))[0] = block_size - 4 - size;
	}
	if((block_size - 4) - size >= 0 && (block_size - 4) - size < 4) //your memory is exactly the size you need then no split  --block_size - 4 - size = 0
	{
		((int*)header)[0] = SET_OCCUPIED(((int*)header)[0]);
		return header;
	}
	return header;
}

int memFree(void* header)
{
	void* nexthead;
	if(header!=NULL)
	{
		if(!isFree(header))//not free
		{                       
			((int*)header)[0] = SET_FREE(((int*)header)[0]); 
		}
		nexthead = getNextBlock(header); 
 
		if(isFree(nexthead))//next block is free
		{
			((int*)header)[0] = ((int*)header)[0] + ((int*)nexthead)[0] -1;// head =+ next head
		}	
		 		
		return 1;
        
	}
	return 0;
}





