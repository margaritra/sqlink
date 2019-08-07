#include <stdio.h>

int func1(int k);
int func2(int n);
int func3(int m);
 
int main () {
	
   int result,result1,n,m,k = 0;

   printf("enter number: ") ;

   scanf("%d",&k);

   result = func1(k);

	
   printf("enter number: ") ;

   scanf("%d",&n);

   result = func2(n);

   printf("enter number: ") ;

   scanf("%d",&m);

   result1 = func3(m);
 
   return 0;
}


int func1(int n)
{
	for(int row = 0;row <n; row++)
	{
		//printf("row = %d\n",row);
		for (int col = 0;col<n;col++)
		{
			if(col<= row)
			{
			//printf("col = %d",col);
			printf("*");
			}
			
		}
printf("\n");
	
	}
}

int func2(int n)
{
	int size = (n*2)-1;
	int col = 0;
	int back,j = 0;
	

	for(int row = 0;row <=size/2; row++)
	{
		for (col = 0;col<=size/2;col++)
		{	
		
			if(col <= row )
			{
			
				printf("*");
			}
			
	}

	printf("\n");
	}
	for(int i = n-1;i>0;i--)
	{
		for (j = 0;j<=size/2;j++)
		{	
		
			if(j < i )
			{
			
				printf("*");
			}
			
	}printf("\n");
	}
}

int func3(int m)
{
	int count = 1;
	int i = 0;
	int k = 0;
	int g = 0;

	for (i ; i<m; i++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");
	count+=2;

	for(i = 1;i<m;i++)
	{
		for(k = 0;k<m-i;k++)
		{
			printf(" ");
		}
		for(g = 0 ;g<count;g++)
		{
			printf("*");
		}
		g = 0;
		printf("\n");
		count+=2;
	}

	
}










