#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

void printFromCharToDecimal(char c)
{
  int i;
  for (i = 0; i < 8; i++) 
	{
      		printf("%d", !!((c<<i)& 0x80));
  	}
  printf("\n");
}

void invertsTheBits(unsigned char x)
{
	
	int i = 0;
	char y;
	unsigned int ezer = 255;

	printf("x = ");
	printFromCharToDecimal(x);

	y = x ^ ezer;

	printf("x inverted = ");
	printFromCharToDecimal(y);
}



int rotateTheBits(int r,unsigned char x)
{
	printf("x = ");
	printFromCharToDecimal(x);	

	x = x<<r;
	
	
	printf("x rotated by %d = ",r);
	printFromCharToDecimal(x);
}








 int Int2Bin(int n)
{
	int a[100];
	int i = 0;

	
	if(n>=0)
	{
		for(i=0;n>0;i++)    
		{    
			a[i]=n%2;    
			n=n/2;    
		}

	        printf("\n The Binary number is = "); 
		for(i =i-1; i>=0 ;i--)
		{
			printf("%d",a[i]);
		} 
		printf("\n");
	}
	if(n<0)
	{
		return 0;   
	}
}

