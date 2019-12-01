#include <iostream>
using namespace std;
#include "head.h"
#include <string.h>



string_t::string_t()// default CTOR
{ 
	size = 1;
    str = new char[size];
} 

string_t::string_t(const char* s)//CTOR from "const char*"
{
	size = strlen(s); 
    str = new char[size+1]; 
    strcpy(str, s); 
}
string_t::string_t(const string_t& old_str)//copy CTOR
{
	size = old_str.size; 
    str = new char[size+1]; 
    strcpy(str, old_str.str); 
}
string_t::~string_t()// destructor
{
	delete [] str;
}
string_t& string_t::operator = (const string_t& s)// assignment operator
{
	if(this != &s) 
     *str = *(s.str);
  
   return *this; 
}
int string_t::length()// mem-function 'length' which returns length of the string
{
	return strlen(this->str);
}
void string_t::setString(const char* s)// mem-function 'setString' which gets as a parameter "const char*"
{
	strcpy(str,s);
}
const char* string_t::getString()// mem-function 'getString' which returns "const char*"
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
	int i;
	for(int i=0;i<strlen(str);i++)
	cout << str[i];
	cout << endl;
}