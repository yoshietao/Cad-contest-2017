#include "parser.h"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;




int main(int argc,char** argv)
{
	ifstream ifs(argv[1]);
	parser p;
	p.set_param(&ifs);
}