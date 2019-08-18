#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int num;
	char str[16] = "abcdefghijklmnop";

	do{
		printf("1: withoutBitField(); \n");
		printf("2: withBitField \n");
		printf("3: if you want to quit \n");
		printf("Enter the number of function: \n");
		scanf("%d",&num);

		switch(num)
		{
			case 1:	
			withoutBitField(str);
			break;

			case 2:	
			withBitField(str);
			break;

			case 3:	
			break;
	
		}
		
			
	}
	while(num!=3);

	
	
	return 0;
}


