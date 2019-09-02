#include <stdio.h>
#include "libN.h"

int main()
{
	//printf("Im in main again\n");
	funLib();
	funLib2();
	funLib3();
	return 0;
}

void funLib()
{
	printf("im in lib!\n");
}