
#include<iostream>
#include<string>
//#include <fstream>
#include"parser.h"


Parser::Parser()
{
	m_lineNumber = 0;
};

void Parser::open(const string& i_path)//open the file and check if it's ok
{
   	m_file.open("test.txt"); 
	if(m_file)
	{
		cout<<"OK"<<endl;
	}
}

void Parser::parse(const string& i_path)
{
	open(i_path);

	string str;

	while (getline(m_file, str)) 
	{
		m_tokenizer.checkLine(str);
		m_lineNumber++;
 		//m_a.analyzer(m_lineNumber);
   	}
}
