#include <stdio.h>
#include <stdlib.h>

void funA(void * ptr);
void funB();

int main()
{
	void *ptr;
	ptr = funB;
	funA(ptr);
	printf("Im in main again\n");

	return 0;
}

void funA(void* ptr)
{
	void **p = &ptr;
	p--;
	*p = ptr;
	printf("I'm A function!\n");
}

void funB()
{
	printf("I'm B function!\n");
}
