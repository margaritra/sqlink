#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int num;
	int rotate = 3;
	int bin;
	
	unsigned char x1 = 'a';
	int result;
	unsigned char x = 170;
	unsigned char y = 167;
	unsigned int w = 0xf345a03e;
	int p = 6;
	int n = 3;
	int value = 1; 
	int i = 12;
	int j = 25;
	

	do{
		printf("1:invertsTheBits() \n");
		printf("2:rotateTheBits()  \n");
		printf("3:setbits()  \n");
		printf("4:setbitsZeroOrOne()  \n");
		printf("5: if you want to quit \n");
		printf("Enter the number of function: \n");
		scanf("%d",&num);

		switch(num)
		{
			case 1:	
			invertsTheBits(x1);
			break;
			
			case 2:	
			rotateTheBits(rotate,x);
			break;

			case 3:
			setbits(x,p,n,y);	
			break;

			case 4:
			setbitsZeroOrOne(w,i,j,value);
			break;
	
		}
		
			
	}
	while(num!=5);

	
	
	return 0;
}
