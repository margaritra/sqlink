#include <iostream>
using namespace std;
#include "head.h"
#include <string.h>
#include <math.h> 

int string_t::numofString = 0;

int string_t::m_dfltCapacity = 2;//4 bytes* 8bits = 32 and i need 64

bool string_t::m_caseSens = 1;

string_t::string_t()// default CTOR
{ 
	createString(0);
	numofString++;
} 

string_t::string_t(const char* s)//CTOR from "const char*"
{
	createString(s);
	numofString++;
}
string_t::string_t(const string_t& old_str)//copy CTOR
{
	createString(old_str.str);
}
string_t::~string_t()// destructor
{
	delete [] str;
	numofString--;
}
string_t& string_t::operator = (const string_t& s)// assignment operator
{
	if(this!= &s)
	{
		delete[]  str;
		createString(s.str);
	}
	
	return *this;
}

int string_t::compare(const char* s)// mem-function 'compare' which compares 2 strings and returns: 1 -if the object string less than parameter, 0 - if they are equal or 2 -if the object greater than parameter
{
	if(strcmp(str,s)<0)	
		return 1;

	else if(strcmp(str,s)<0)
		return 0;

	else if(strcmp(str,s)>0)
		return 2;
}


char* string_t::toUpper()
{
	int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<size;i++)
	{
		c= str[i];
		if(c >= 'a' && c <= 'z')
		{
			str[i] = c - sub;
		}
	}
	
	return str;
}

char* string_t::toLower()
{
	int i=0;
	char c;
	int sub = 'a' - 'A'; /*32*/
	for(i=0;i<size;i++)
	{
		c= str[i];
		if(c >= 'A' && c <= 'Z')
		{
			str[i] = c + sub;
		}
	}
	
	return str;
}

void string_t::prepend(const char* s)
{
	int newSize = strlen(s) + size +1;
	char* newStr = new char [newSize];
	
	int i= 0; 
	for(i; i< strlen(s); i++)
	{
		newStr[i] = s[i];
	}
	newStr[i] = ' ';
	
	strcat(newStr, str);	
	strcpy(str,newStr);
	
}

void string_t::prepend(const string_t& s)
{
	 prepend(s.str);
}

string_t& string_t::operator+=(const string_t& s)
{
	if(size < size + strlen(s.str))
	{
		char *ezer = new char[size+1];
		ezer = strcpy(ezer,str);
		
		delete[] str;
		size = size + strlen(s.str)+1;
		str= new char[size];
		strcpy(str,ezer);
		delete [] ezer;
	}

	strcat(str, s.str);	
	
	return *this;
}





bool string_t::contains(const string_t& s)
{
	int i = 0;
	int j = 0;
	
	for (i; i<size; i++)
		{
			if (str[i] == s.str[j])
			{

				while (str[i] == s.str[j]) 
				{
					i++;
					j++;
				}

				if (s.str[j] == '\0') 
				{
					return true;
				}
				else 
				{
					j = 0;
				}
			}
		}

	return false;
	
}

/*private func*/
char* string_t::createString(const char* s)
{
	if(s == 0)
	{
		m_capacity = m_dfltCapacity;
		str= new char[m_capacity];
	 	str[0] = '\0';
	}
	else
	{
		//copy ctor
		size = strlen(s);
		if(size >= m_dfltCapacity)
		{
			m_dfltCapacity = (int)(pow(2,log2(size)+1));
		}
		m_capacity = m_dfltCapacity;
		str= new char[m_capacity];
		strcpy(str,s);
	}
	 
	 return str;
}

char& string_t::operator[](size_t pos)
{
	
	return str[pos];
}


int string_t::returnFirstindex(const string_t& s)
{
	int i = 0;
	int j = 0;
	int place = -1;
	size = strlen(str);
	int size_s = strlen(s.str);
	
	for(i= 0;i<=size;i++)
		{
			while(i<size)
			{
				if(str[i]==s.str[j])
				{
					j++;
					i++;
					if(j == size_s)
					{
						place = i-j;
						return place;
					}
				}
				
				else if (str[i]!=s.str[j])
				{
					j = 0;
					i++;
				}
			}
		}
		

	return place;
}

int string_t::returnLastindex(const string_t& s)
{
	int i = 0;
	int j = 0;
	int place = -1;
	size = strlen(str);
	int size_s = strlen(s.str);
	
	for(i= 0;i<=size;i++)
		{
			while(i<size)
			{
				if(str[i]==s.str[j])
				{
					j++;
					i++;
					if(j == size_s)
					{
						place = i;
						return place;
					}
				}
				
				else if (str[i]!=s.str[j])
				{
					j = 0;
					i++;
				}
			}
		}
		

	return place;

}

string_t string_t::operator()(unsigned int start,unsigned int len)
{
	int i =0;
	int j = 0;
	size = strlen(str);
	char* newStr= new char[size+1];

	for(i = start;i<=len;i++)
	{
		newStr[j] = str[i];
		j++;
	}
	string_t temp(newStr);
	delete[]newStr;
	return temp;
}
