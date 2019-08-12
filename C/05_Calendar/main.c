#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int capacity = 1;
	int num;//for switch
	int first = 1;
	int result = 0;
   	calendar_t *calendar = 0;
	calendar_t *meet = 0;
   
   	printf("Enter the amount of meetings for today: ");    
   	scanf("%d",&capacity); 
   	printf("\n");  

	do{
		printf("0: create_ad() \n");
		printf("1: create_meet() \n");
		printf("2: insert_appointment() \n");
		printf("3: Remove_appointment() \n");
		printf("4: Find_appointment() \n");
		printf("5: destroy_AD() \n");
		printf("5: print_AD() \n");
		printf("7: if you want to quit \n");
		printf("Enter the number of function: \n");
		scanf("%d",&num);

		switch(num)
		{
			case 0: 
			calendar = calendar_t* create_ad(calendar);
			break;

			case 1:	
			meet = meating_t* create_meet();
			break;

			case 2:	
			result = insert_appointment(calendar,meet,first);
			break;

			case 3:	
			break;

			case 4:	
			break;

			case 5:	
			break;
			
			case 6:	
			break;

			case 7:	
			break;
	
		}
		
			
	}
	while(num!=7)		
	
	return 0;
}
