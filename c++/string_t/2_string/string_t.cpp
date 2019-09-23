#include <iostream>
using namespace std;
#include "head.h"
#include <string.h>



string_t::string_t()// default CTOR
{ 
	createString(0);
} 

string_t::string_t(const char* s)//CTOR from "const char*"
{
	createString(s);
}
string_t::string_t(const string_t& old_str)//copy CTOR
{
	createString(old_str.str);
}
string_t::~string_t()// destructor
{
	delete [] str;
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
int string_t::length()// mem-function 'length' which returns length of the string
{
	return strlen(this->str);
}
void string_t::setString(const char* s)// mem-function 'setString' which gets as a parameter "const char*"
{
	delete[]  str;
	createString(s);
}
char* string_t::getString() const// mem-function 'getString' which returns "const char*"
{
	return str;
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
void string_t::printString()
{
	cout<<str;
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

char* string_t::prepend(const char* s)
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
	
	return str;
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

bool string_t::operator<(const string_t& s)
{
	if(strcmp(str, s.str) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator>(const string_t& s)
{
	if(strcmp(str, s.str) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator>=(const string_t& s)
{
	if(strcmp(str, s.str) > 0 || strcmp(str, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator<=(const string_t& s)
{
	if(strcmp(str, s.str) < 0 || strcmp(str, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator==(const string_t& s)
{
	if(strcmp(str, s.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool string_t::operator!=(const string_t& s)
{
	if(strcmp(str, s.str) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
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
		str= new char[4];
	 	str[0] = '\0';
	}
	else
	{
		//copy ctor
		size = strlen(s);
		str= new char[size+1];
		strcpy(str,s);
	}
	 
	 return str;
}

char& string_t::operator[](size_t pos)
{
	
	return str[pos];
}



ostream& operator<<(ostream& os,const string_t& s)
{
	os << s.getString();
	
	return os;
}

istream& operator>>(istream& is, string_t& s)
{
	char str[128];
	is>> str;
	s.setString(str);
		
	return is;
}









