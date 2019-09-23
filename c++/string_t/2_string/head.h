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
		char* getString() const;// mem-function 'getString' which returns "const char*"
		int compare(const char* s);// mem-function 'compare' which compares 2 strings and returns: 1 -if the object string less than parameter, 0 - if they are equal or 2 -if the object greater than parameter
		void printString();
		char* toUpper();
		char* toLower();
		char* prepend(const char* str);
		string_t& operator+=(const string_t &);
		bool operator<(const string_t &);
		bool operator>(const string_t &);
		bool operator>=(const string_t &);
		bool operator<=(const string_t &);
		bool operator==(const string_t &);
		bool operator!=(const string_t &);
		char& operator[](size_t );
		char& operator[](size_t );
		//const char& operator[] (size_t pos) const;
		bool contains(const string_t &);

    private:
    	char* str;
    	int size;
		char* createString(const char*);
};

ostream& operator<<(ostream& os,const string_t& s);
ostream& operator>>(ostream& is, string_t& s);

#endif
