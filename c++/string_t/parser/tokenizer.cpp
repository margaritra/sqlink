
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;
#include <iostream>
#include "tokenizer.h"


TokenIzer::TokenIzer(string one_line)
{
	checkLine(one_line);
}

void TokenIzer::checkLine(string str)
{
   	vector <int> cont_of_pos;//container of keywords positions 
   	string token;
   	string delimiter;

   	int pos = 0;
   	int pos_of_del_in_str;

   	int size_kw = kw.size();
   	int size_of_keyword;

  
   	for(int i = 0;i < size_kw; i++)
   	{
      	pos = 0;
      	delimiter = kw[i];
      	while(pos < str.length())
      	{
         	size_of_keyword = kw[i].length();
         	pos_of_del_in_str = str.find(delimiter,pos);
         	if(pos_of_del_in_str != -1)
         	{
            	cont_of_pos.push_back(pos_of_del_in_str);
            	cont_of_pos.push_back(pos_of_del_in_str+size_of_keyword);
            	pos = pos_of_del_in_str+size_of_keyword;
         	}
         	else
         	{
            	pos = 0;
            	break;
         	}
      	}
   	}

   	//sort the conteiner of keywords positions
   	sort(cont_of_pos.begin(), cont_of_pos.end());

   	//split the string by cont_of_pos
	pos = 0;

	for(int i=0; i<cont_of_pos.size(); i++)
	{
		if(cont_of_pos[i]!=pos)
		{
			token = str.substr(pos,cont_of_pos[i]-pos); //substr (size_t pos = 0, size_t len = npos) const;
			pos = cont_of_pos[i];
			container.push_back(token);
		}		
	}

	//display the container
	for (int i=0; i<container.size(); i++)  
	{
		cout << container[i] << "\n";
	}

}








