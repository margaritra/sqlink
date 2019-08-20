#include <stdio.h>
#include <string.h>
#include"darray_int.h"

void testFunc()
{
	darray *myDarr;
	int myInt;
	AdtStatus tmp;
	tmp = darrayCreate(&myDarr,100);
	printf("result of create is :%d\n",tmp);

	myDarr = darrayAdd(myDarr,8);
	myDarr = darrayAdd(myDarr,10);
	myDarr = darrayAdd(myDarr,81);
	myDarr = darrayAdd(myDarr,82);
	myDarr = darrayAdd(myDarr,8);
	//printf("result of Add is :%d\n",tmp);

	print_AD(myDarr);



	//darrayDelete(myDarr,&myInt);
	//printf("%d\n",myInt);
}

int main()
{
	testFunc();
	return 0;
}
