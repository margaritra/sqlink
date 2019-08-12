#include <stdio.h>
#include <stdlib.h>
#include "head.h"


da_t* my_create(int capacity)
{
	da_t * frst_da ;
	if(frst_da)
	{
		frst_da = malloc(sizeof(da_t));
		frst_da->capacity = capacity;
		frst_da->index = 0;

		frst_da->arr = malloc(capacity*sizeof(intPtr));//sizeof(intPtr)
		return frst_da;
	}
}


int my_insert(da_t *ip,intPtr num)//intPtr num
{
 	intPtr* temp;

	temp = ip->arr;
	
	if(ip->index < ip->capacity)
	{
		ip->arr[ip->index] = num;
		printf("in my_insert : \n");
		(ip->index)++;
		
	}
	else
	{	
		ip->arr = realloc(ip->arr,((ip->capacity)*2)*sizeof(intPtr));//sizeof(intPtr)
		if(ip->arr!=NULL)
		{
			printf("in my_insert realloc : \n");
			ip->capacity *=2;
		}
		else
		{
			ip->arr=temp;
			return 0;
		}
		ip->arr[ip->index] = num;
		(ip->index)++;
		
	}
 	
	return 1;
}


void print_da(da_t* arr)
{
	//int size_arr = sizeof(arr)/sizeof(arr[0]);
	//printf("size :%d\n",size_arr);
	if(arr!=0 && arr->arr!=0)
	{
		for(int i = 0; i < arr->index ;i++)
		{
			printf("%d\n",*(arr->arr[i]));//*(arr->arr[i])
		}
	}

}

void destroy_da(da_t *ip)
{
	//printf("destroy : \n");
	if((ip->arr)!=0)
	{
		//free(arr->arr[i]);
		free(ip->arr);
	}
	if (ip!=0)
	{
		free(ip);
	}
	
}


