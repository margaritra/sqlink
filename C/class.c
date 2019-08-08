#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int my_str_cmp(const char * str1, const char * str2);

int main () {

   char str1[12] = "Hello";
   char str2[12] = "Hllo";
   int result = 0;

   result = my_str_cmp(str1,str2);
   printf("%d\n",result);
   
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

