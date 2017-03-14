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

	vector<block> vshape;

	parser p;
	p.set_param(&ifs);
	cout<<p.get_viacost()<<endl;
	cout<<p.get_spacing()<<endl;
	cout<<p.get_n_obstacles()<<endl;
	//cout<<p.get_routed_shape()[2].layer<<endl;
	vshape = *p.get_routed_shape();
	cout<<vshape[2].layer<<' '<<vshape[2].left_down.x<<' '<<vshape[2].left_down.y<<endl;
}