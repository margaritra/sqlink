#include "virtIO_t.h"

virtIO_t::virtIO_t()
{
	m_fileP = 0;
	m_path;
	m_access; /*default ctor of string is empty string by default*/
	m_position = 0;
	m_status = ok_e;
}

virtIO_t::virtIO_t(const string& i_path, const string& i_access)
{
	open(i_path, i_access);
} 

virtIO_t::~virtIO_t()
{
	close();
}

void virtIO_t::open(const string& i_path, const string& i_access)
{
	if (i_access!= "r" && i_access != "w" && i_access != "r+" && i_access != "w+")
	{
		throw bad_access_e;
	}

	m_fileP = fopen(i_path.c_str(), i_access.c_str());

	if(m_fileP)
	{
		m_path = i_path;
		m_access = i_access;
		m_position = 0;
	}
	else
	{
		throw cant_open_file_e;
	}
}

void virtIO_t::close()
{
	if(m_fileP)
	{
		close();
	}
}

size_t virtIO_t::getLength() const
{
	if(m_fileP) 
	{
		  fseek(m_fileP, 0 , SEEK_END); //move file pointer to a specific position
		  size_t fileLenght = ftell(m_fileP); //position of pointer
		  fseek(m_fileP, m_position, SEEK_SET);// needed for next read from last position of file

		  return fileLenght;
	}

	return 0;
}

void virtIO_t::setPosition(const size_t& position)
{
	if (m_fileP && position <= getLength())
	{
		fseek(m_fileP, position, SEEK_SET);
		m_position = position;
	}
}

inline size_t virtIO_t::getPosition() const
{
	return ftell(m_fileP);
}






