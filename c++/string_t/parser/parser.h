#pragma once // any file containing #pragma once will only actually be included once, even if the programmer includes it multiple times.
#include<iostream>
#include<string>
#include <fstream>
#include"tokenizer.h"
using namespace std;

class Parser
{
public:

	Parser();

	void open(const string& i_path);

	void parse(const string& i_path);

	~Parser()
	{
		m_file.close();
	}



private:
	Parser(const Parser& p) {};
	Parser& operator=(const Parser& p) {};

	ifstream m_file; ////This data type represents the input file stream and is used to read information from files.
	int m_lineNumber;
	TokenIzer m_tokenizer;
	//Analyzer m_a;
};