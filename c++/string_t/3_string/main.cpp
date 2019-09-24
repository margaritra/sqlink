#include <iostream>
using namespace std;
#include <string.h>
#include "head.h"

int main() 
{
	int choice;
	
	char newStr[] = "";

//	cout << "Enter String:";
//	cin >> str;
	string_t str;
/*

	string_t str1("GeeksQuiz"); 
    string_t str2 = str1;
	


    str1.printString(); // the same
    str2.printString();

    str2.setString("OK"); 

    str1.printString(); // NOT the same
    str2.printString();

    cout << str1.length() << endl;
    
    cout << str2.length() << endl;

    
    str1.setString("test");

    cout << "str1: " << str1.getString() << endl;

	cout << str2.compare(str1.getString())<< endl;

	cout << "num of string: " << string_t::nOfString << endl;

	cout << "caseSens: "<< string_t::setcaseSens << endl;

	bool caseSens = 0;

	cout << "setandReturncaseSens: "<<str1.setandReturncaseSens(caseSens) << endl;


	string_t str3("m"); 

	cout << "str1: " << str1.getString() << endl;//test

	cout << "str3: " << str3.getString() << endl;//te

	

	cout << "return first index: " << str1.returnFirstindex(str3) << endl;
	cout << "return last index: " << str1.returnLastindex(str3) << endl;

	cout<< "the returned string :" << str1(1,3) <<endl;//est


*/

	cout << endl<<"Choose option:" << endl;
	do 
	{
		cout << endl;
		cout << "1.Set string" << endl;
		cout << "2.Get string" << endl;
		cout << "3.Get string length" << endl;
		cout << "4.Print string" << endl;
		cout << "5.Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter String: ";
			cin >> newStr;
			str.setString(newStr);
			break;
		case 2:
			str.getString();
			break;
		case 3:
			str.length();
			break;
		case 4:
			cout << endl<<"The string: ";
			str.printString();
			break;
		default:
			cout <<"Wrong choice please try again"<<endl;
			break;
		}
		
	} while (choice != 5);

	return 0;
}
