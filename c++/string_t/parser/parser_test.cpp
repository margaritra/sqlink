#include<iostream>
#include <fstream>
#include"parser.h"

using namespace std;
int main(int argc, char* argv[])
{
   Parser p;
   p.parse("test.txt");
}