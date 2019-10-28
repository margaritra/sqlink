#pragma once
#include <vector> 
#include<ctype.h>
#include<iostream>
#include<string>
using namespace std;
//extern "C"

class TokenIzer
{
public:
	TokenIzer() {};
	~TokenIzer() {};
	void tokenIzer(const string& str);
	void tokenClear() { m_tokens.clear(); };
	void printTokens() const;
	vector<string> getTokens() const { return m_tokens; };

private:
	TokenIzer(const TokenIzer& ti) {};
	TokenIzer& operator=(const TokenIzer& ti) {};
	bool isDelimiter(const char *c);

	const char* delimiters[15] = { "(", ")", "[", "]" , "{" , "}" ,";" ,"<", ">", "=", "+", "-", "*", "&" "<<”", ">>" };
	vector<string> m_tokens;
};

bool TokenIzer::isDelimiter(const char *c)
{
	if (isalpha(c[0]) || isdigit(c[0]))
		return false;

	for (int i = 0; i < 16; i++)
	{
		if (c[0] == *(delimiters)[i])
			return true;
	}

	return false;
}

void TokenIzer::tokenIzer(const string& str)
{
	string tok;

	for (int i = 0; i< str.length(); i++)
	{
		if (!isspace(str[i]))
		{
			if (!(isDelimiter(&str[i])))
			{
				tok += str[i];
				/*if (i == str.length() - 1) // if end of line push the token
				{
				m_tokens.push_back(tok);
				}*/
			}
			else
			{
				if (!tok.empty())
				{
					m_tokens.push_back(tok);
				}
				tok = str[i];
				m_tokens.push_back(tok);
				tok = "";
			}
		}
		else
		{
			if (!tok.empty())
			{
				m_tokens.push_back(tok);
				tok = "";
			}
		}
	}

	if (!tok.empty())
	{
		m_tokens.push_back(tok);
	}
}

void TokenIzer::printTokens() const
{
	for (int i = 0; i < m_tokens.size(); i++)
	{
		cout << m_tokens[i] << endl;
	}
}









