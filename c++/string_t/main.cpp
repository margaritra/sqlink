#include <iostream>
using namespace std;
#include <string.h>
#include "head.h"

int main() 
{
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

    cout << str1.getString() << endl;

	cout << str2.compare(str1.getString())<< endl;

	return 0;
}
