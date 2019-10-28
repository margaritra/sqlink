#include<iostream>
#include"parser.h"

using namespace std;

int main(int argc, char* argv[])
{
	Parser p;
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			p.parse(argv[i]);
		}
		catch (string err)
		{
			cout << err;
		}
	}
}
