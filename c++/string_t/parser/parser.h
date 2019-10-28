#pragma once
#include<string>
#include <fstream>
#include"tokenIzer.h"
#include"analyzer.h"

using namespace std;

class Parser {
public:
	Parser() { m_lineNumber = 0; };
	void parse(const string& i_path);
	~Parser() { m_file.close(); };

private:
	Parser(const Parser& p) {};
	Parser& operator=(const Parser& p) {};

	ifstream m_file;
	int m_lineNumber;
	TokenIzer m_tokenizer;
	Analyzer m_analyzer;

	vector<string>::const_iterator first;
	vector<string>::const_iterator last;
};

void Parser::parse(const string& i_path)
{
	m_file.open(i_path);
	if (m_file)
	{
		string line;
		while (getline(m_file, line))
		{
			m_lineNumber++;
			m_tokenizer.tokenIzer(line);
			//m_tokenizer.printTokens();
			m_analyzer.analyzer(m_tokenizer.getTokens(), m_lineNumber);
			m_tokenizer.tokenClear();
		}
	}
	else
	{
		throw string("Error in openning file");
	}
}