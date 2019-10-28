#pragma once
#include <vector> 
#include <set>
#include<string>
#include<iostream>
using namespace std;

class Analyzer {
public:
	Analyzer();
	~Analyzer();

	void analyzer(const vector<string> &tokens, int lineNumber);


private:
	/*Functions*/
	Analyzer(const Analyzer& ap) {};
	Analyzer& operator=(const Analyzer& a) {};

	void setPredefinedTypes();
	void setkeyWords();
	void setOperators();
	void setDelimeters();

	void printRule(const string &s, int lineNumber) const { cout << "line " << lineNumber << ":  error, " << s << endl; };
	void printCloseBracesError(const string &open, const string &close, int lineNumber) const { cout << "line " << lineNumber << ":  error,is illegal  '" << open << "' has to be before '" << close << "'" << endl; };
	void printBracesMatchError(int lineNumber) { cout << "Number of open braces dose not match number of close braces." << endl; };
	void printElseError(int lineNumber) { cout << "line " << lineNumber << ":  error, 'else' without 'if'" << endl; };

	/*Rules*/
	void mainRule(const string& token, int index, int lineNumber);
	void bracesRule(const string& token, int lineNumber);
	void elseRule(int lineNumber);
	void predefinedTypesRule(const string& token, int lineNumber);
	void plusMinusRule(const string& token, int lineNumber);
	void varNameRule(const string& token, int lineNumber);
	void multipleDeclareRule(const string& token, int lineNumber);

	bool checkVariableNameOk(const string& token, int lineNumber);
	void checkIfVariableNameDeclared(const string& token, int lineNumber);
	

	int isPredefinedTypes(const string& token);

	/*counters*/
	int parenthesesCount; //(
	int bracketsCount; //[
	int bracesCount; //{
	int operatorPlusCount; // + -
	int operatorMinusCount;
						   /*flags*/
	bool ifFlag;
	bool isOpenParentheses; //(
	bool isOpenBrackets;//[
	bool isOpenBraces; //{



	 /*Language words*/
	set<string> m_predefinedTypes;
	set<string> m_keyWords;
	set<string> m_operators;
	set<string> m_delimeters;

	set<string> declaredVariables;

	set<string>::iterator it;

};