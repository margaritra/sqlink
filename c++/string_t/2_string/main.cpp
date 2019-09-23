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

    char str[] = "";
    cout << "Enter str:";
	cin >> str;
	string_t st(str);

    cout<<"contains fun result:"<<endl;
	cout<<st.contains("Ri")<<endl;
    cout<<endl;

    st.toUpper();
	st.printString();
	cout<<endl;
	st.toLower();
	st.printString();
    cout<<endl;
	/*
	st.prepend("Borodin");
	st.printString();
    cout<<endl;
	
	
	st+= "Borodin";
	st.printString();
    cout<<endl;
	

	cout<< (st < "Rita")<<endl;
	cout<< (st > "Rita")<<endl;
	cout<< (st >= "Rita")<<endl;
	cout<< (st <= "Rita")<<endl;
	cout<< (st == "Rita")<<endl;
	cout<< (st != "Rita")<<endl;
	*/
    
	
	//cout << st; 
	
	//st+= "Borodin";
	
	
	//cout<< st[0]<<endl;
	//st[0] = 'M';
	
	//cout<< st<<endl;
	

	return 0;
}
