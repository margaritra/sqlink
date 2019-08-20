#include <stdlib.h>
#include "darray_int.h"
struct darray{
	int *arr;
	int index;
	int capacity;
	int initial_capacity;
};
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	darray *tempArr;
	tempArr = malloc(sizeof(darray*));

	if(tempArr)
	{
		tempArr->index = 0;
		tempArr->capacity = initial_capacity;
		tempArr->initial_capacity = initial_capacity;
		tempArr->arr =  malloc(initial_capacity*sizeof(int));
		if(tempArr->arr)
		{
			*dArr = tempArr;
			return OK;
		}

	}
	return AllocationError;
}
/* Add number to the end. */
darray *   darrayAdd(darray *dArr,  int  _item)
{
	int *temp;
	temp = dArr->arr;
	if(dArr)
	{
		if(dArr->index<dArr->capacity)
			{
				dArr->arr[dArr->index] =_item;
				dArr->index++;
				return dArr;
			}
		else
		{
			dArr->arr = realloc(dArr->arr,((dArr->capacity)*2)*sizeof(int));
			if(dArr->arr!=NULL)
			{
				printf("in my_insert realloc : \n");
				dArr->capacity *=2;
				dArr->arr[dArr->index] =_item;
				dArr->index++;
				return dArr;
			}
			else
			{
				dArr->arr=temp;
				return dArr;
			}
		}
	}
	return dArr;
}
void print_AD(darray *dArr)
{
	
	int i;
	if(dArr!=NULL)
	{
		for(i=0;i<dArr->index;i++)
		{
			printf("*******************************************\n");
			printf("array :%d \n",dArr->arr[i]);
			printf("*******************************************\n");
		}
	}
}
/* Delete number from the end. */
AdtStatus   darrayDelete(darray *dArr,  int* _item)
{
	if(dArr!=NULL)
	{
		if(dArr->capacity > dArr->initial_capacity && )
			{//realloc}
	//index --;
	}
	return AllocationError;
}
AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
	return OK;
}
AdtStatus   darraySet(darray *dArr, size_t _index, int  _item)
{
	return OK;
}
AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	return OK;
}
/* in place (ascending) sorting an array of size arraySize */
AdtStatus darraySort(darray *dArr, size_t arraySize)
{
	return OK;
}
AdtStatus darrayDestroy(darray *dArr)
{
	int i = 0;
	if(dArr)
	{
		if(dArr->arr)
		{
		free(dArr->arr);
		}
	free(dArr);
	return OK;
	}
	return AllocationError;
}
