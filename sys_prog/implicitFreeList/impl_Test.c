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
