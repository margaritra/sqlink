#include <stdio.h>
#include <stdlib.h>
#include "da.h"


da_t* my_create(int capacity)
{
	da_t * frst_da ;
	if(frst_da)
	{
		frst_da = malloc(sizeof(da_t));
		frst_da->capacity = capacity;
		frst_da->index = 0;
		frst_da->arr = malloc(capacity*sizeof(int));
		return frst_da;
	}
}


int my_insert(da_t *ip,int num)
{
 	da_t * temp;

	temp->arr = ip->arr;
	
	if(ip->index < ip->capacity)
	{
		ip->arr[ip->index] = num;
		(ip->index)++;
		
	}
	else
	{	
		ip->arr = realloc(ip->arr,((ip->capacity)*2)*sizeof(int));
		if(temp->arr)
		{
			ip = temp;
			
			ip->capacity *=2;
		}
		else
		{
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
	if(arr->index!=0)
	{
		for(int i = 0; i < arr->index ;i++)
		{
			printf("%d\n",arr->arr[i]);
		}
	}

}

void destroy_da(da_t *ip)
{
	//printf("destroy : \n");
	if((ip->arr)!=0)
	{
		free(ip->arr);
	}
	if (ip!=0)
	{
		free(ip);
	}
	
}

