#pragma once
#include <iostream>
using namespace std;
#include <vector> 
#include <string>
#include <algorithm>//for sort


class TokenIzer
{
public:

	TokenIzer(){}
	~TokenIzer(){}
	TokenIzer(string one_line);
	void checkLine(string str);
	
private:
	vector <string> container;

	vector <string> kw{"char", "short", "int", "long", "float", "double", "void", "if", "else", "for" , "while", "class","private", "public", "protected", "main", "const", "virtual",
			"++", "--", "==", "->" , "=", "+", "-", "*", "&" "<<”", ">>","(", ")", "[", "]" , "{" , "}" ,";" ,"<", ">"};
};







