#include "virtIO_t.h"
#include <string>

virtIO_t::virtIO_t()
{
	m_position = 0;
	m_path = '\0';
	m_access = '\0';
	m_status = 0;
	m_file =0;
}

virtIO_t::virtIO_t(const string& name, const access& mode)
{
	m_status= open(name,mode);
	if(m_status == ok_e)
	{
		m_path = name;
		m_access = mode;
		m_position = 0;
	}

	throw string("ERROR");

} 

virtIO_t::~virtIO_t()
{
	fclose(m_file);
}

status virtIO_t::open(const string& name,const string& mode)
{
	m_file= fopen(name, mode);
	if(m_file)
	{
		return ok_e;
	}

	return cant_open_file_e;
}

void virtIO_t::close(const string& name)
{
	fclose(m_file);
}

const string& virtIO_t::getpath() const
{
	return m_path;
}

size_t virtIO_t::length() const
{
	if(m_file) 
	{
		  fseek(m_file, 0 , SEEK_END);
		  size_t fileSize = ftell(m_file);
		  fseek(m_file, 0 , SEEK_SET);// needed for next read from beginning of file

		  return fileSize;
	}

	return 0;
}






