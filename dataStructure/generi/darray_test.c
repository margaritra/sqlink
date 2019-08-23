#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"darray_int.h"
#include <math.h>

typedef struct
{
	int x;
	int y;
}vector;


int vectorsCompare(void* _elemA, void* _elemB)
{
	int leng1, leng2;
	vector* vector1 = (vector*) _elemA;
	vector* vector2 = (vector*) _elemB;

	leng1 = vector1->x + vector1->y;
	leng2 = vector2->x + vector2->y;

	if(leng1 == leng2)
	{
		printf("%d", leng1-leng2);
		return leng1-leng2;
	}
	else if(leng1 > leng2)
	{
		printf("%d", leng1+leng2);
		return leng1+leng2;
	}
	else if(leng1 < leng2)
	{
		printf("%d", leng1-leng2);
		return leng1-leng2;
	}
}
void swapLocation(void* arri, void* arrj)
{
	int* arr1 = (int*) arri;
	int* arr2 = (int*) arrj;
	int temp = *arr1; 
    *arr1 = *arr2; 
    *arr2 = temp; 
}

void destroyVector(void *_elem, void *context)
{
	if(_elem!=NULL)
	{
		vector* vectorElem = (vector*)_elem;//struct
		if(context!=NULL)
		{
			FILE *file = (FILE *)context;
			fprintf(file,"%d %d",vectorElem->x,vectorElem->y);
			free(vectorElem);
		}
	}
}

void testFunc()
{
	darray *myDarr;
	int *myInt;
	int res;
	int numOfItems;
	int item = 5;
	int x= 2;

	//x = pow(x,2);
	//printf("the pow is :%d",x);

	AdtStatus tmp;
	char filename[] = "vector.txt";

	vector *vec = malloc(sizeof(vector));

	vec->x = 5;
	vec->y = 5;

	FILE * file = fopen(filename,"w");

	tmp = darrayCreate(&myDarr,100);

	darrayAdd(myDarr,vec);

	vec->x = 10;
	vec->y = 7;

	darrayAdd(myDarr,vec);

	vec->x = 10;
	vec->y = 9;

	darrayAdd(myDarr,vec);
	darraySort(myDarr);
	
	//darrayDelete(myDarr,myInt);
	

	//res = darrayItemsNum(myDarr,&numOfItems);
	//printf("there is numOfItems %d\n",res);

	//myDarr = darrayAdd(myDarr,vec);
	//darraySort(myDarr);
	

	darrayDestroy(myDarr,destroyVector,file);
	
	

	//darrayDelete(myDarr,&myInt);
	//printf("%d\n",myInt);
}


int main()
{
	testFunc();
	return 0;
}
