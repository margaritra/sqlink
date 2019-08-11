#include <stdio.h>
#include <stdlib.h>
#include "da.h"

int main()
{
	int capacity = 1;
   	da_t *ip = 0;
	int result = 0;

   	int num;
   	int count = 0;
  	int test = 0;
   
   	printf("Enter the capacity: ");    
   	scanf("%d",&capacity); 
   	printf("\n");  
	int temp = capacity;


	ip = my_create(capacity);

	if(ip)
	{
		while(test < temp*2)
		{
			printf("Enter the number: ");    
			scanf("%d",&num); 
			result = my_insert(ip,num);
			
			test++;
		}
	}
	
	if(result ==1)
	{
		print_da(ip);
	}
	
        destroy_da(ip);
	
	//printf("after destroy :\n");
	//print_da(ip);

return 0;
}
