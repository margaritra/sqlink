#include<stdio.h>
#include <stdlib.h>
#include "implicit_head.h"

void test(char *list,int size)
{
	char * header;
	int yourlocation;
	

	header = memInit(list,size);

	int mysize = 5;

	header = memAlloc(header,mysize);
	if(header==0)
	{
		printf("ERROR ALLOCATION!!!\n");
	}
	else
	{
		printf("SUCCESSFULLY ALLOCATED!!!\n");
	}

	//mysize = 5;

	//header = memAlloc(header,mysize);
	int statusFree = memFree(header);

	if(statusFree==0)
	{
		printf("FREE ERROR!!!\n");
	}
	else
	{
		printf("SUCCESSFULLY FREE!!!\n");
	}
	
}

int main()
{
	int size = 16;
	char *list = malloc(size+4);
	test(list,size);
	return 0;
}
