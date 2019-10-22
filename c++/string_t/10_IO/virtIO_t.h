#ifndef virtIO_t_H
#define virtIO_t_H
#include <string>

typedef enum {ok_e ,cant_open_file_e, bad_access_e, writeErr_e, readErr_e} status;
typedef enum {r,w,r+,w+} access;

class  virtIO_t
{
public:

virtIO_t();//dflt COTR
virtual ~virtIO_t();//dstrctr
virtIO_t(const string& name,const access& mode);//COTR from name&mode
status open(const string& name,const string& mode);
void close(const string& name);

const string& getpath() const;
inline access getaccess() const;

size_t length() const;

inline size_t getposition() const;
inline void setposition(const size_t& pos);

inline int getstatus() const;
inline void setstatus(const status& stat);


virtual virtIO_t& operator>>(int& num) = 0;//fwrite()
virtual virtIO_t& operator<<(int num) = 0;//fprintf(fp,"%d",num)

virtual virtIO_t& operator>>(float& num) = 0;//fwrite()
virtual virtIO_t& operator<<(float num) = 0;//fprintf(fp,"%f",num)


private:
virtIO_t(const virtIO_t& v){};// copy COTR
virtIO_t& operator = (const virtIO_t& v){};// assignment operator

string m_path;
size_t m_position;
string m_access;
string m_status;
File* m_file;
};


inline size_t virtIO_t::getposition() const
{
	return m_position;
}

inline void virtIO_t::setposition(const size_t& position)
{
	m_position = position;
}

inline int virtIO_t::getstatus() const
{
	return m_status;
}

inline void virtIO_t::setstatus(const status& stat)
{
	m_status = stat;
}

inline access virtIO_t::getaccess() const
{
	return m_access;
}


#endif
