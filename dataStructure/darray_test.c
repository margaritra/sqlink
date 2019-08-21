#include <stdio.h>
#include <string.h>
#include"darray_int.h"

void testFunc()
{
	darray *myDarr;
	int myInt;
	int res;
	int numOfItems;
	AdtStatus tmp;
	tmp = darrayCreate(&myDarr,100);
	printf("result of create is :%d\n",tmp);

	myDarr = darrayAdd(myDarr,8);
	myDarr = darrayAdd(myDarr,10);
	myDarr = darrayAdd(myDarr,81);
	myDarr = darrayAdd(myDarr,82);
	darrayDelete(myDarr,&myInt);
	
	print_AD(myDarr);

	//res = darrayItemsNum(myDarr,&numOfItems);
	//printf("there is numOfItems %d\n",res);

	myDarr = darrayAdd(myDarr,2);
	darraySort(myDarr, numOfItems);
	printf("result after sort \n");

	print_AD(myDarr);

	darrayDestroy(myDarr);
	

	


	//darrayDelete(myDarr,&myInt);
	//printf("%d\n",myInt);
}

int main()
{
	testFunc();
	return 0;
}