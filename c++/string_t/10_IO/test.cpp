#include "virtIO_t.h"
#include"asciiIO_t.h"
#include"binIO_t.h"
#include<iostream>

using namespace std;

//num Status { ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_es };
int main()
{
	string path = "/home/ubuntu/Rita/copyofgit/10_IO/test.txt";
	string mode = "w";
	int i=100;
	//int j=10;

	virtIO_t* ascii = new asciiIO_t();

	//virtIO_t* binIO = new binIO_t();

	try
	{
		//binIO->open(path , mode);

		ascii->open(path , mode);
		*ascii<<i;//cout

		//*ascii>>j;//cin
		//cout<<endl<<j<<endl;


	}

	catch(virtIO_t::Status error)
	{
		switch(error)
		{
			case 1:
				cout<<"cant_open_file_e"<<endl;
				break;
			case 2:
				cout<<"bad_access_e"<<endl;
				break;
			default:
				break;
		}
	}

	return 0;
}
