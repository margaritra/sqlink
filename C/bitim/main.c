#include <stdio.h>
#include <stdlib.h>
#include "head.h"

int main()
{
	int n = 3;
	int nf = 72;
	int bin;
	int result3,result4;
	bitmap* bm;

	bm = createBitmap(nf);
	isbit(bm ,n);
	
	printf("Enter the number to convert: ");    
	scanf("%d",&n);  
	result3 = Int2Bin(n);
	printf("%d\n",result3);

	printf("Enter the binary number to convert: ");    
	scanf("%d",&n);  
	result4 = Bin2Int(n);
	printf("%d\n",result4);
	
	
	
	return 0;
}
