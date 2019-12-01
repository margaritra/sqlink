
#ifndef HEAD_H
#define HEAD_H

class  string_t
{
	public:
		string_t();// default CTOR
		string_t(const char* s);//CTOR from "const char*"
		string_t(const string_t& old_str);//copy CTOR
		~string_t();// destructor
		string_t& operator = (const string_t& s);// assignment operator
		int length();// mem-function 'length' which returns length of the string
		void setString(const char* s);// mem-function 'setString' which gets as a parameter "const char*"
		const char* getString();// mem-function 'getString' which returns "const char*"
		int compare(const char* s);// mem-function 'compare' which compares 2 strings and returns: 1 -if the object string less than parameter, 0 - if they are equal or 2 -if the object greater than parameter
		void printString();

    private:
    	char* str;
    	int size;
};



#endif


