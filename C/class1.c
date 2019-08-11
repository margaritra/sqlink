#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 6

int * my_insert(int num,int *array,int *count,int *capacity);


int main() {

   int capacity = 1;
   int *ip;
int *result;
   int num;
   int count = 0;
   int test = 0;
   
   printf("Enter the capacity: ");    
   scanf("%d",&capacity); 
   printf("\n");  

   
   /* allocate memory dynamically */
   ip = malloc( capacity * sizeof(int) );

   int temp = capacity;

	
   while(test < temp*2)
	{
		printf("Enter the number: ");    
		scanf("%d",&num); 
		ip = my_insert(num,ip,&count,&capacity);
		
		test++;
	}

	for(int i = 0; i < test;i++)
	{
		printf("%d\n",ip[i]);
	
	}
	
	free(ip);
return 0;
   
}

int* my_insert(int num,int *ip,int *count,int *capacity)
{
	int * temp;

	temp = ip;
	//printf("num in fun :%d\n",num);

	if(count < capacity)
	{
		ip[*count] = num;
		(*count)++;
		
	}
	else
	{	//(*capacity)++;
		ip = (int *)realloc(ip,((*capacity)+1)*sizeof(int));
		if(ip)
		{
			ip[*count] = num;
			(*count)++;
			(*capacity)++;
		}
		
	}
 	
	return ip;
}
























