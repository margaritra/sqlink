#pragma once
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class virtIO_t{
public:
	virtIO_t();
	virtIO_t(const string& i_path, const string& i_access);
	virtual ~virtIO_t();

	//enum Status { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_es };
	typedef enum  { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_es }Status;

	void open(const string& name, const string& access);
	void close();

	const string& getPath() const { return m_path; };
	const string& getAccess() const { return m_access; };
	Status getStatus() const { return m_status; };  
	void setStatus(const Status& status){ m_status = status; };

	size_t getLength() const;

	size_t getPosition() const;
	void setPosition(const size_t& position);

	virtual virtIO_t& operator<<(char c) = 0;
	virtual virtIO_t& operator>>(char& c) = 0;
	virtual virtIO_t& operator<<(unsigned char c) = 0;
	virtual virtIO_t& operator>>(unsigned char& c) = 0;
	virtual virtIO_t& operator<<(int num) = 0; /*fprintf(fp,%d,num) in ascii- need to check mode. in binary fwrite() */
	virtual virtIO_t& operator>>(int& num) = 0;
	virtual virtIO_t& operator<<(unsigned int num) = 0; 
	virtual virtIO_t& operator>>(unsigned int& num) = 0;
	virtual virtIO_t& operator<<(float num) = 0;
	virtual virtIO_t& operator>>(float& num) = 0;
	virtual virtIO_t& operator<<(short num) = 0;
	virtual virtIO_t& operator>>(short& num) = 0;
	virtual virtIO_t& operator<<(unsigned short num) = 0;
	virtual virtIO_t& operator>>(unsigned short& num) = 0;
	virtual virtIO_t& operator<<(long num) = 0;
	virtual virtIO_t& operator>>(long& num) = 0;
	virtual virtIO_t& operator<<(unsigned long num) = 0;
	virtual virtIO_t& operator>>(unsigned long& num) = 0;
	virtual virtIO_t& operator<<(double num) = 0;
	virtual virtIO_t& operator>>(double& num) = 0;
	
protected:
	FILE* m_fileP;
	string m_path;
	string m_access;
	Status m_status;
	size_t m_position;
	
private:
	virtIO_t(const virtIO_t& v){};
	virtIO_t& operator=(const virtIO_t& v){};
};











