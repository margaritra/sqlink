#include"analyzer.h"
#include <algorithm>


Analyzer::Analyzer()
{

	setPredefinedTypes();
	setkeyWords();
	setOperators();

	parenthesesCount = 0;
	bracketsCount = 0;
	bracesCount = 0;
	operatorPlusCount = 0;
	operatorMinusCount =0;

	ifFlag = false;
	isOpenParentheses = false; //(
	isOpenBrackets = false;//[
	isOpenBraces = false; //{
}

void Analyzer::setPredefinedTypes()
{
	m_predefinedTypes.insert("char");
	m_predefinedTypes.insert("short");
	m_predefinedTypes.insert("int");
	m_predefinedTypes.insert("long");
	m_predefinedTypes.insert("float");
	m_predefinedTypes.insert("double");
	m_predefinedTypes.insert("void");
}

void Analyzer::setkeyWords()
{
	m_keyWords.insert("if");
	m_keyWords.insert("else");
	m_keyWords.insert("for");
	m_keyWords.insert("while");
	m_keyWords.insert("class");
	m_keyWords.insert("private");
	m_keyWords.insert("public");
	m_keyWords.insert("protected");
	m_keyWords.insert("main");
	m_keyWords.insert("const");
	m_keyWords.insert("virtual");

}

void Analyzer::setOperators()
{
	m_operators.insert("++");
	m_operators.insert("--");
	m_operators.insert("==");
	m_operators.insert("->");
	m_operators.insert("(");
	m_operators.insert(")");
	m_operators.insert("[");
	m_operators.insert("]");
	m_operators.insert("{");
	m_operators.insert("}");
	m_operators.insert(";");
	m_operators.insert("<");
	m_operators.insert(">");
	m_operators.insert("=");
	m_operators.insert("+");
	m_operators.insert("-");
	m_operators.insert("*");
	m_operators.insert("&");
	m_operators.insert("<<");
	m_operators.insert(">>");
}

void Analyzer::setDelimeters()
{
	m_delimeters.insert("(");
	m_delimeters.insert(")");
	m_delimeters.insert("[");
	m_delimeters.insert("]");
	m_delimeters.insert("");
	m_delimeters.insert("{");
	m_delimeters.insert("}");
	m_delimeters.insert(";");
	m_delimeters.insert("<");
	m_delimeters.insert(">");
	m_delimeters.insert("=");
	m_delimeters.insert("+");
	m_delimeters.insert("-");
	m_delimeters.insert("*");
	m_delimeters.insert("&");
	m_delimeters.insert("<<");
	m_delimeters.insert(">>");
}

Analyzer::~Analyzer()
{
}


void Analyzer::analyzer(const vector<string> &tokens, int lineNumber)
{
	for (int i = 0; i< tokens.size(); ++i)
	{
		mainRule(tokens[i], i, lineNumber);
		if (tokens[i] == "(" || tokens[i] == ")" || tokens[i] == "[" || tokens[i] == "]" || tokens[i] == "{" || tokens[i] == "}")
		{
			bracesRule(tokens[i], lineNumber);
		}
		else if (tokens[i] == "if")
		{
			ifFlag = true;
		}
		else if (tokens[i] == "else")
		{
			elseRule(lineNumber);
		}
		else if (m_predefinedTypes.find(tokens[i]) != m_predefinedTypes.end())//check if double type
		{
			if (i < tokens.size()-1)
			{
				multipleDeclareRule(tokens[i + 1], lineNumber);
			}
		}
		else if( i>0 && m_predefinedTypes.find(tokens[i-1]) != m_predefinedTypes.end())
		{
			bool isOk= checkVariableNameOk(tokens[i],lineNumber);
			if (m_keyWords.find(tokens[i]) != m_keyWords.end()) 
			{
				cout << "line " << lineNumber << " - error, illegal variable name cant be a keyword" << endl;
			}
			else
			{
				declaredVariables.insert(tokens[i]);
			}
		}
		else if(tokens[i] == "+" || tokens[i] == "-")
		{
			plusMinusRule(tokens[i], lineNumber);
			if ((i < tokens.size() - 1 && tokens[i] != tokens[i + 1]) || tokens.size()==1)
			{
				operatorPlusCount = 0;
				operatorMinusCount = 0;
			}
		}
	}
}

void Analyzer::mainRule(const string& token, int index, int lineNumber)
{
	bool isMainOk = true;

	if (index == 0 && lineNumber == 1 && token != "main")
	{
		isMainOk = false;
	}
	else if (index == 0 && lineNumber != 1 && token == "main")
	{
		isMainOk = false;
	}

	if (isMainOk != true)
	{
		printRule("illegal - declaration before 'main'", lineNumber);
	}

}

void Analyzer::bracesRule(const string& token, int lineNumber)
{
	if (token == "(")
	{
		parenthesesCount++;
		isOpenParentheses = true;
	}
	else if (token == ")")
	{
		parenthesesCount--;
		if (!isOpenParentheses)
		{
			printCloseBracesError("(", ")", lineNumber);
		}
		else
		{
			isOpenParentheses = false;
		}
	}
	else if (token == "[")
	{
		bracketsCount++;
		isOpenBrackets = true;
	}
	else if (token == "]")
	{
		bracketsCount--;
		if (!isOpenBrackets)
		{
			printCloseBracesError("[", "]", lineNumber);
		}
		else
		{
			isOpenBrackets = false;
		}

	}
	else if (token == "{")
	{
		bracesCount++;
		isOpenBraces = true;
	}
	else if (token == "}")
	{
		bracesCount--;
		if (!isOpenBraces)
		{
			printCloseBracesError("{", "}", lineNumber);
		}
		else
		{
			isOpenBraces = false;
		}
	}
}

void Analyzer::elseRule(int lineNumber)
{
	if (!ifFlag)
	{
		printElseError(lineNumber);
	}
	else
	{
		ifFlag = false;
	}
}

void Analyzer::multipleDeclareRule(const string& token, int lineNumber)
{
	if (m_predefinedTypes.find(token) != m_predefinedTypes.end())
	{
		cout << "line "<< lineNumber<< " : error, error multiple type declaration"<<endl;
	}
}

bool Analyzer::checkVariableNameOk(const string& token, int lineNumber)
{
	if (token[0] != '_' && !isalpha(token[0]))
	{
		cout << "line " << lineNumber << " - error, illegal variable name" << endl;
		return false;
	}
	return true;
}

void Analyzer::plusMinusRule(const string& token, int lineNumber)
{
	if (token == "+")
	{
		operatorPlusCount++;
		if (operatorPlusCount == 3)
		{
			cout << "line " << lineNumber << ": error, no operator +++" << endl;
			operatorPlusCount = 0;
		}
	}
	else
	{
		operatorMinusCount++;
		if (operatorMinusCount ==3)
		{
			cout << "line " << lineNumber << ": error, no operator +++" << endl;
			operatorMinusCount = 0;
		}	
	}
}
