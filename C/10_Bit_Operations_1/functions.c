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
	printf("******************************************************\n");
	printf("x = ");
	printFromCharToDecimal(x);

	y = x ^ ezer;

	printf("x inverted = ");
	printFromCharToDecimal(y);
	printf("******************************************************\n\n");
}



int rotateTheBits(int r,unsigned char x)
{
	printf("******************************************************\n");
	printf("x = ");
	printFromCharToDecimal(x);	
	
	unsigned char temp1;
	unsigned char temp2;

	temp1 = x>>r;
	temp2 = x<<(8-r);

	x = temp1 | temp2;
	
	printf("x rotated by %d = ",r);
	printFromCharToDecimal(x);
	printf("******************************************************\n\n");
}

int setbits(unsigned char x,int p,int n,unsigned char y)
{
	unsigned char mask;
	unsigned char maskXbeg;
	unsigned char maskXend;
	
	mask = y << (p-1);
	mask = mask>>8-p;
	
	maskXbeg = x>>p;
	maskXbeg = maskXbeg<<p;
	
	int pos = (8-p)+n;
	maskXend = x<<pos;
	maskXend = maskXend>>pos;

	maskXbeg = maskXbeg | maskXend;
	x = maskXbeg | mask;

	printf("******************************************************\n\n");
	Int2Bin(x);
	printf("******************************************************\n\n");
	return x;
}


int setbitsZeroOrOne(unsigned int w,int i,int j,int value)
{
	unsigned int mask;

	if(i>=32 || i<0 || j>=32 || j<0){
		return 0;
	}
	
	if(value == 1)
	{
		mask = 0xffffffff;
		mask = (mask << i) >> i;
		mask = (mask >> 32-j-1)<<(32-j-1);

		w = mask | w;
	}
	else
	{
		mask = w;
		mask = (mask << i) >> i;
		mask = (mask >> 32-j-1)<<(32-j-1);

		w = mask^w;
	}
	printf("******************************************************\n\n");
	printf("w: ");
	Int2Bin(w);
	printf("******************************************************\n\n");
	
	return w;
}


int Bin2Int(int bin)
{
	int rem = 0;
	int base = 1;
	int decimal = 0;


	 while (bin > 0)
    {
        rem = bin % 10;
        decimal = decimal + rem * base;
        bin = bin / 10 ;
        base = base * 2;
    }
	return decimal;
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
