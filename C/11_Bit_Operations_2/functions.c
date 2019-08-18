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

char * withoutBitField(char *str)
{
	char temp1,temp2;
	int i = 0;

	for(i;i<16;i++)
	{
		str[i] = str[i] - 'a';
		printf("str[%d]:",i);
		printFromCharToDecimal(str[i]);
		temp1 = str[i];
		if((i+1)<16)
		{
			str[i+1] = str[i+1] -'a';
			printf("str[%d]:",i+1);
			printFromCharToDecimal(str[i+1]);
			temp2 = str[i+1];
		}
		
		str[i] = temp1 | temp2;
		printf("temp1 | temp2 : str[%d]:",i);
		printFromCharToDecimal(str[i]);
		temp2 = temp2<<4; 
		printf("temp2 :");
		printFromCharToDecimal(temp2);
		str[i] = temp1 | temp2; 
		printf("final : str[%d] :",i);
		printFromCharToDecimal(str[i]);
 		i= i+1;
	}
	
	return str;
}

int withBitField(char *str)
{
	union un un;
	int i = 0;

	for(i;i<16;i++)
	{
		str[i] = str[i] - 'a'; 
		un.lr.right = str[i];
		printf("un.lr.right %d:",i);
		printFromCharToDecimal(un.lr.right);
		if((i+1)<16)
		{
			str[i+1] = str[i+1] -'a';
			un.lr.left = str[i+1];
			printf("un.lr.left :%d ",i+1);
			printFromCharToDecimal(un.lr.left);
		}
		i= i+1;
		printf("un.c :%d ",i);
		printFromCharToDecimal(un.c);
	}
	return 1;
}




















