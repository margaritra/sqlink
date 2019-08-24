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
	
	return leng1-leng2;	
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
/*
void print_AD(darray *dArr,int length)
{
	
	int i;
	if(dArr!=NULL)
	{
		printf("*******************************************\n");
		for(i=0;i< length ;i++)
		{			
			//printf("array :%d \n",dArr->arr[i]);
			printVector((vector *)dArr->arr[i]);
			printf(",");
			
		}
		printf("*******************************************\n");
	}
}
void printVector(vector* vec){
	printf("(%d,%d)",vec->x,vec->y);
}
*/
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
	int length;

	vector *vec = malloc(sizeof(vector));
	FILE * file = fopen(filename,"w");

	tmp = darrayCreate(&myDarr,100);

	vec->x = 5;
	vec->y = 5;

	darrayAdd(myDarr,vec);

	vec->x = 10;
	vec->y = 7;

	darrayAdd(myDarr,vec);

	vec->x = 10;
	vec->y = 9;

	darrayAdd(myDarr,vec);
	darraySort(myDarr,vectorsCompare);

	
	length = darrayItemsNum(myDarr,&numOfItems);
	//print_AD(myDarr,length);
	
	//darrayDelete(myDarr,myInt);
	

	
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
