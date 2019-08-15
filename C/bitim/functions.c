#include <stdio.h>
#include <stdlib.h>
#include "head.h"

bitmap* createBitmap(int nf)
{
	bitmap* m_nf = malloc(sizeof(bitmap));
	int n,size;
	if(m_nf!=0)
	{	
		printf("enter the number of features:\n");
		scanf("%d\n",&n);
		m_nf->m_nf = n;
		size = nf/sizeof(int);

		m_nf->m_arr = malloc(sizeof(int)*size);
		if(m_nf->m_arr!=0)
		{
			return m_nf;
		}
	}
}

int isbit(bitmap* bm ,int n)
{
	unsigned int a = 1;
	int c = 0; 
	c = a << n;
	printf("before:\n");
	Int2Bin(a);
	printf("after:\n");
	Int2Bin(c);
	
	
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









