#pragma once
#include"virtIO_t.h"

class binIO_t : public virtIO_t{
public:
	
	binIO_t():virtIO_t(){};

	binIO_t(const string& i_path, const string& i_access)
			:virtIO_t(i_path, i_access){};

	virtual ~binIO_t(){}

	virtual binIO_t& operator<<(char c) { return fWrite(c);};
	virtual binIO_t& operator>>(char& c) {return fRead(c);};

	virtual binIO_t& operator<<(unsigned char c) { return fWrite(c);};
	virtual binIO_t& operator>>(unsigned char& c) {return fRead(c);};

	virtual binIO_t& operator<<(int num){ return fWrite(num);};
	virtual binIO_t& operator>>(int& num) {return fRead(num);};

	virtual binIO_t& operator<<(unsigned int num) { return fWrite(num);};
	virtual binIO_t& operator>>(unsigned int& num){return fRead(num);};

	virtual binIO_t& operator<<(float num) {return fWrite(num);};
	virtual binIO_t& operator>>(float& num){return fRead(num);};

	virtual binIO_t& operator<<(short num) { return fWrite(num);};
	virtual binIO_t& operator>>(short& num){return fRead(num);};

	virtual binIO_t& operator<<(unsigned short num) { return fWrite(num);};
	virtual binIO_t& operator>>(unsigned short& num){return fRead(num);};

	virtual binIO_t& operator<<(long num) { return fWrite(num);};
	virtual binIO_t& operator>>(long& num){return fRead(num);};

	virtual binIO_t& operator<<(unsigned long num) { return fWrite(num);};
	virtual binIO_t& operator>>(unsigned long& num){return fRead(num);};

	virtual binIO_t& operator<<(double num) { return fWrite(num);};
	virtual binIO_t& operator>>(double& num){return fRead(num);};

	virtual binIO_t& operator>>(void* Buf);
	virtual binIO_t& operator<<(const void* Buf);
	void operator,(int len);//for read/write blocks

private:
	binIO_t(const binIO_t& a){};
	binIO_t& operator=(const binIO_t& a){};

	template <class T>
	binIO_t& fRead(T& var);

	template <class T>
	binIO_t& fWrite(T var);
};

	template <class T>
	binIO_t& binIO_t::fRead(T& var)
	{
		if(m_status == ok_e && m_fileP)
		{
			*this >> &var, sizeof(T);
			return *this;
		}

		throw readErr_es;
	}

	template <class T>
	binIO_t& binIO_t::fWrite(T var)
	{
		if(m_status == ok_e && m_fileP)
		{
			if(m_access != "r")
			{
				*this >> &var, sizeof(T);
				return *this;
			}
		}
		
		throw writeErr_e;
	}