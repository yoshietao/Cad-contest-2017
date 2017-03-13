#include "parser.h"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


void parser::set_param(istream* ifs)
{
	string str;
	getline(*ifs,str);
	cout<<str<<endl;
}


