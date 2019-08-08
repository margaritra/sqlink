

#include <stdio.h>
#include <string.h>

char *my_squeeze(char *s1,char *s2);

int main()
{
	char *result;
	char s1[10] = "ABCDEF";
	char s2[10] = "BKE";
	result = my_squeeze(s1,s2);
	printf("The result is : %s\n ",result);
	
	return 0;
}

char *my_squeeze(char *s1,char *s2)
{
	//printf("%s\n%s\n",s1,s2);
	int i = 0;
	int j = 0;
    int size_s2 = strlen(s2);
	int size_s1 = strlen(s1);
	
	
	//if my strings are not empty => strcmp(s1, "")!=0

	 if(strcmp(s1, "")!=0 && strcmp(s2, "")!=0)
	{	
		for (i;i<size_s2;i++)
		{
			j = 0;
			for(j;j<size_s1;j++)
			{
				
				if(s2[i] == s1[j] && s1[j]!= '\0')
				{
					for (int k = j;k<size_s1;k++)
					{
						s1[k] =s1[k+1];
						if(s1[k]==(size_s1-1))
						{
							s1[k+1] = '\0';
						}
					}
				}
			}	
			
		}
		
	}
	
	 return s1;
	
	
}

