

#include <stdio.h>
#include <string.h>

char *my_squeeze(char *s1,char *s2);
int string_location(char *s1,char *s2);

int main()
{
	char *result;
	int result1 = 0;


	char s1[10] = "ABCDEF";
	char s2[10] = "BKE";

	char str1[10] = "ABCDEF";
	char str2[10] = "BKE";


	result = my_squeeze(s1,s2);
	printf("The result of SECOND exercise : %s\n ",result);

	result1 = string_location(str1,str2);
	printf("The result of THIRD exercise : %d\n ",result1);
	
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

int string_location(char *s1,char *s2)
{
	int i = 0;
	int j = 0;
    int size_s1 = strlen(s1);
	int size_s2 = strlen(s2);
	int place = -1;

	if(strcmp(s1, "")!=0 && strcmp(s2, "")!=0)
	{	
		for(i;i<size_s1;i++)
		{
			while(i<size_s1)
			{
				if(s1[i]==s2[j])
				{
					j++;
					i++;
				}
				if(j == size_s2)
				{
					place = i-j;
					return place;
				}
				else if (s1[i]!=s2[j] && i<size_s1)
				{
					j = 0;
					i++;
				}
			}
		}
		
	}
	return place;
}
