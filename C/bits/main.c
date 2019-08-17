#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int n = 4;
	int nf = 0;
	int num ;
	int bin;
	int result3,result4;
	bitmap* bm;

	printf("enter the number of features:\n");
	scanf("%d",&nf);


	bm = createBitmap(nf);
	

	do{
		printf("1: isbit() status of bit \n");
		printf("2: bitON() \n");
		printf("3: bitOFF() \n");
		printf("4: if you want to quit \n");
		printf("Enter the number of function: \n");
		scanf("%d",&num);

		switch(num)
		{
			case 1:	
			printf("enter the location:\n");
			scanf("%d",&n);
			isbit(bm ,n);
			break;

			case 2:	
			printf("enter the location:\n");
			scanf("%d",&n);
			bitON(bm ,n);
			break;

			case 3:
			printf("enter the location:\n");
			scanf("%d",&n);	
			bitOFF(bm ,n);	
			break;
	
		}
		
			
	}
	while(num!=4);

	
	
	return 0;
}

