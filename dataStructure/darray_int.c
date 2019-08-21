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

/* Delete number from the end. */
AdtStatus   darrayDelete(darray *dArr,  int* _item)
{
	int * temp;
	temp = dArr->arr;
	if(dArr!=NULL)
	{
		if(dArr->capacity > dArr->initial_capacity && dArr->index<=(size_t)(0.75*((dArr->capacity/2))))
			{
				temp= realloc(temp,((dArr->capacity)/2)*sizeof(int));
			}
		if(temp!=NULL)
		{
			dArr->arr= temp;
			dArr->capacity = dArr->capacity/2;
		}
		else
		{
			return AllocationError;
		}
		*_item = dArr->arr[dArr->index];
		dArr->index--;
		return OK;
	}
	return AllocationError;
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

int darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	//_numOfItems = dArr->index;
	return  dArr->index;
}

AdtStatus darraySort(darray *dArr, size_t arraySize)
{
	if(dArr!=NULL)
	{
		int i, j;
		int temp;  
   		for (i = 0; i < dArr->index-1; i++)     
   		{
			for (j = 0; j < dArr->index-i-1; j++) 
			{
				if (dArr->arr[j] > dArr->arr[j+1])  
				{
					temp = dArr->arr[j];
					dArr->arr[j] = dArr->arr[j+1];
					dArr->arr[j+1] = temp;
				} 
			} 
		} 
		return OK;
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