#pragma once
#include"virtIO_t.h"

class asciiIO_t : public virtIO_t{
public:
	asciiIO_t()
			:virtIO_t(){};

	asciiIO_t(const string& i_path, const string& i_access)
			:virtIO_t(i_path, i_access){};

	virtual ~asciiIO_t(){}

	virtual asciiIO_t& operator<<(char c) { return fPrintf(c, "%c");};
	virtual asciiIO_t& operator >> (char& c) {return fScanf(c, "%c");};

	virtual asciiIO_t& operator<<(unsigned char c) { return fPrintf(c, "%u");};
	virtual asciiIO_t& operator >> (unsigned char& c) {return fScanf(c, "%u");};

	virtual asciiIO_t& operator<<(int num){ return fPrintf(num, "%d");};
	virtual asciiIO_t& operator >> (int& num) {return fScanf(num, "%d");};

	virtual asciiIO_t& operator<<(unsigned int num) { return fPrintf(num, "%u");};
	virtual asciiIO_t& operator >> (unsigned int& num){return fScanf(num, "%u");};

	virtual asciiIO_t& operator<<(float num) {return fPrintf(num, "%f");};
	virtual asciiIO_t& operator >> (float& num){return fScanf(num, "%f");};

	virtual asciiIO_t& operator<<(short num) { return fPrintf(num, "%i");};
	virtual asciiIO_t& operator >> (short& num){return fScanf(num, "%i");};

	virtual asciiIO_t& operator<<(unsigned short num) { return fPrintf(num, "%hu");};
	virtual asciiIO_t& operator >> (unsigned short& num){return fScanf(num, "%hu");};

	virtual asciiIO_t& operator<<(long num) { return fPrintf(num, "%ld");};
	virtual asciiIO_t& operator >> (long& num){return fScanf(num, "%ld");};

	virtual asciiIO_t& operator<<(unsigned long num) { return fPrintf(num, "%lu");};
	virtual asciiIO_t& operator >> (unsigned long& num){return fScanf(num, "%lu");};

	virtual asciiIO_t& operator<<(double num) { return fPrintf(num, "%lf");};
	virtual asciiIO_t& operator >> (double& num){return fScanf(num, "%lf");};

private:
	asciiIO_t(const asciiIO_t& a){};
	asciiIO_t& operator=(const asciiIO_t& a){};

	template <class T>
	asciiIO_t& fScanf(T& var, const char* format);

	template <class T>
	asciiIO_t& fPrintf(T var, const char* format);
};


template <class T>
asciiIO_t& asciiIO_t::fScanf(T& var, const char* format)
{
	if(m_status == ok_e && m_fileP)
	{
		fscanf(m_fileP, format, &var);
		return *this;
	}

	throw readErr_es;
}

template <class T>
asciiIO_t& asciiIO_t::fPrintf(T var, const char* format)
{
	if(m_status == ok_e && m_fileP)
	{
		if(m_access == "w" || m_access == "w+" || m_access == "r+")
		{
			fprintf(m_fileP, format, var);

			return *this;
		}
		else
		{
			m_status = writeErr_e;
		}
	}

	throw writeErr_e;
}