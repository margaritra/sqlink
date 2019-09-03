#include<stdio.h>
#include "implicit_head.h"



void test(char *list,int size)
{
	char * header;
	char * yourlocation;
	header = memInit(list,size);
	yourlocation = memAlloc(header,15);
}

int main()
{
	int size = 1000;
	char *list;
	test(list,size);
	return 0;
}


	
	/*
		*pi = 76411;
	for(i = 0; i<size;i++)
	{
		printf("list [%d",i);
		printf("] = %d\n",list[i]);
	}
	*/