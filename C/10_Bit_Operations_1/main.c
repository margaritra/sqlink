#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int num;
	int rotate = 3;
	
	unsigned char x = 'a';
	

	do{
		printf("1:invertsTheBits() \n");
		printf("2:rotateTheBits()  \n");
		printf("3: if you want to quit \n");
		printf("Enter the number of function: \n");
		scanf("%d",&num);

		switch(num)
		{
			case 1:	
			//printf("Enter x: \n");
			//scanf("%d",&x);
			invertsTheBits(x);
			break;
			
			case 2:	
			//printf("Enter x: \n");
			//scanf("%d",&x);
			rotateTheBits(rotate,x);
			break;

			case 3:	
			break;
	
		}
		
			
	}
	while(num!=3);

	
	
	return 0;
}


