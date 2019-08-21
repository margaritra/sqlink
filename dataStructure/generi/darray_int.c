#include <stdlib.h>
#include<stdio.h>
#include "darray_int.h"
struct darray{
	void **arr;
	int index;
	int capacity;
	int initial_capacity;
};
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
	darray *tempArr;
	tempArr = malloc(sizeof(darray *));

	if(tempArr)
	{
		tempArr->index = 0;
		tempArr->capacity = initial_capacity;
		tempArr->initial_capacity = initial_capacity;
		tempArr->arr =  malloc(initial_capacity*sizeof(void*));
		if(tempArr->arr)
		{
			*dArr = tempArr;
			return OK;
		}

	}
	return AllocationError;
}
/* Add number to the end. */
darray *   darrayAdd(darray *dArr,  void  *_item)
{
	void *temp;
	temp = dArr->arr;
	if(dArr)
	{
		if(dArr->index<dArr->capacity)
			{
				dArr->arr[dArr->index] =_item;
				dArr->index++;
				//print_AD(myDarr);
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
				//print_AD(dArr);
				return dArr;
			}
			else
			{
				dArr->arr=temp;
				//print_AD(dArr);
				return dArr;
			}
		}
	}
	return dArr;
}

/* Delete number from the end. */

AdtStatus darrayDelete(darray *dArr,  void** _item)
{
	void * temp;
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
		//print_AD(myDarr);
		return OK;
	}
	return AllocationError;
}

/*
static void print_AD(darray *dArr)
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
*/
int darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	//_numOfItems = dArr->index;
	return  dArr->index;
}
/*
static int myPartition(darray *dArr,int low,int high)
{
	int i;
    
	pivot = dArr->arr[dArr->index]; 
 
    	i = (low - 1)  // Index of smaller element

    	for (j = low; j <= high- 1; j++)
   	 {
      	  // If current element is smaller than or
      	  // equal to pivot
        	if (arr[j] <= pivot)//vectorsCompare -----------to use function compare!!!!!!! 
        	{
          	  i++;    // increment index of smaller element
                  arr[i] and arr[j]
        	}
    	}
    swap arr[i + 1] and arr[high])
    return (i + 1)
}

AdtStatus darraySort(darray *dArr)
{
	int i;
	for(i = 0;i<dArr->index;i++)
	{
		if ((dArr->index-dArr->index+i) < dArr->arr[dArr->index])
		{
        		pi = partition(dArr, (dArr->index-dArr->index+i), dArr->arr[dArr->index]);

        		darraySort(arr, low, pi - 1);  // Before pi
       			darraySort(arr, pi + 1, high); // After pi
		}
    }
}

*/

AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item)
{
	return OK;
}
AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item)
{
	return OK;
}

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i = 0;  
	if(dArr)
	{
		if(dArr->arr)
		{
			for(i;i<dArr->index;i++)
			{
				destroyFunc(dArr->arr[i],context);
			}
		free(dArr->arr);
		}
	free(dArr);
	return OK;
	}
	return AllocationError;
}