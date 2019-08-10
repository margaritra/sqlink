#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int my_str_cmp(const char * str1, const char * str2);
char *my_str_cpy( char * str1, const char * str2);
char *my_str_cat( char * str1, const char * str2);

int main () {

   int result = 0;
   char *result1 ;
   char *result2;

   char str1[50] = "wwww";
   char str2[50] = "zczxczxc";

   result = my_str_cmp(str1,str2);
   printf("%d\n",result);
   

   result1 = my_str_cpy(str1,str2);
   printf("%s\n",result1);

   result2 = my_str_cat(str1,str2);
   printf("result2 :%s\n",result2);
   
   return 0;
}

int my_str_cmp(const char * str1, const char * str2)
{
	int i = 0;
	for (i;i<strlen(str1);i++)
	{
		if(str1[i]!=str2[i])
		{
			
			if(str1[i]>str2[i])
			{
				return 1;
			}
			else {return -1;}
		}
		if(str1[i]=='\0' && str2[i]=='\0')
		{
			return 0;
		}
		
	}

}

char *my_str_cpy( char * str1, const char * str2)
{
	if(strcmp(str2, "")!=0)
	{
		for (int i = 0;i<strlen(str2);i++)
		{
			str1[i] = str2[i];
			if (i == (strlen(str1)-1))
			{
				str1[i] = '\0';
			}
		}
	}
	return str1;
}


char *my_str_cat( char * str1, const char * str2)
{
	int j;
	
	if(strcmp(str2, "")!=0)
	{		
		j = strlen(str1);	
		for(int k = 0;k<strlen(str2);k++)
		{
			str1[j] = str2[k];
			j++;
		}
	}
	return str1;
	
}
