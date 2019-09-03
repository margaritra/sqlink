
#ifndef _MYhead_H_
#define _MYhead_H_


void* memInit(void* buffer,int size);
void* memAlloc(void* header,int size);
void* memFree(void* header);
#endif
