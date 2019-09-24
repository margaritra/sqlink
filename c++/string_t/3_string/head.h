#ifndef HEAD_H
#define HEAD_H
#include <string.h>

class  string_t
{
	public:
		string_t();// default CTOR
		string_t(const char* s);//CTOR from "const char*"
		string_t(const string_t& old_str);//copy CTOR
		~string_t();// destructor
		string_t& operator = (const string_t& s);// assignment operator
		inline int length();// mem-function 'length' which returns length of the string
		inline void setString(const char* s);// mem-function 'setString' which gets as a parameter "const char*"
		inline char* getString() const;// mem-function 'getString' which returns "const char*"
		int compare(const char* s);// mem-function 'compare' which compares 2 strings and returns: 1 -if the object string less than parameter, 0 - if they are equal or 2 -if the object greater than parameter
		inline void printString();
		char* toUpper();
		char* toLower();
		void prepend(const char* str);
		void prepend(const string_t& str);
		string_t& operator+=(const string_t&);
		inline bool operator<(const string_t&);
		inline bool operator>(const string_t&);
		inline bool operator>=(const string_t&);
		inline bool operator<=(const string_t&);
		inline bool operator==(const string_t&);
		inline bool operator!=(const string_t&);
		inline char& operator[](size_t );
		bool contains(const string_t&);
		static inline int nOfString();
		static inline void setDfltCapacity(size_t dfltCapacity);
		static inline size_t getDfltCapacity();
		static inline bool setcaseSens(bool caseSens);
		static inline bool getcaseSens();
		inline bool setandReturncaseSens(bool caseSens);
		
		int returnFirstindex(const string_t& s);
		int returnLastindex(const string_t& s);
		string_t operator()(int start, uint len);



    private:
    	char* str;
    	int size;
		char* createString(const char*);
		static int numofString;
		static 	int m_dfltCapacity;
		int m_capacity;
		static bool m_caseSens;

};

inline ostream& operator<<(ostream& os,const string_t& s);
inline ostream& operator>>(ostream& is, string_t& s);

inline int string_t::nOfString()
{
	return numofString;
}

inline void string_t::setDfltCapacity(size_t dfltCapacity)
{
		m_dfltCapacity = dfltCapacity;
}

inline size_t string_t::getDfltCapacity()
{
	return m_dfltCapacity;
}

inline bool string_t::setcaseSens(bool caseSens)
{
	//bool ezer = m_caseSens;
	m_caseSens = caseSens;
	//return ezer;
}

inline bool string_t::setandReturncaseSens(bool caseSens)
{
	bool ezer = m_caseSens;
	m_caseSens = caseSens;
	return ezer;
}

inline bool string_t::getcaseSens()
{
	return m_caseSens;
}

inline int string_t::length()// mem-function 'length' which returns length of the string
{
	return strlen(this->str);
}

inline void string_t::setString(const char* s)// mem-function 'setString' which gets as a parameter "const char*"
{
	delete[]  str;
	createString(s);
}

inline char* string_t::getString() const// mem-function 'getString' which returns "const char*"
{
	return str;
}

inline void string_t::printString()
{
	cout<<str;
}

inline bool string_t::operator<(const string_t& s)
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

inline bool string_t::operator>(const string_t& s)
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

inline bool string_t::operator>=(const string_t& s)
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

inline bool string_t::operator<=(const string_t& s)
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

inline bool string_t::operator==(const string_t& s)
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

inline bool string_t::operator!=(const string_t& s)
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

inline ostream& operator<<(ostream& os,const string_t& s)
{
	os << s.getString();
	
	return os;
}

inline istream& operator>>(istream& is, string_t& s)
{
	char str[128];
	is>> str;
	s.setString(str);
		
	return is;
}




#endif


