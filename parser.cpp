#include "parser.h"
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void set_coords(string, boundary*);
void set_blocks(istream*, vector<block>*, vector<via>*, vector<block>*);

vector<block> v_shape,v_obstacle;
vector<via> v_via;
boundary v_boundary;

void parser::set_param(istream* ifs)
{
	string str,str1,garbage;
	node temp;
	*ifs>>garbage>>garbage>>viacost;
	*ifs>>garbage>>garbage>>spacing;
	*ifs>>garbage>>garbage>>str>>str1;
	set_coords(str+' '+str1,&v_boundary);
	//cout<<v_boundary.right_up.x<<endl;
	*ifs>>garbage>>garbage>>n_metal_layers;
	*ifs>>garbage>>garbage>>n_routed_shapes;
	*ifs>>garbage>>garbage>>n_routed_vias;
	*ifs>>garbage>>garbage>>n_obstacles;
	set_blocks(ifs,&v_shape,&v_via,&v_obstacle);
}

int parser::get_viacost()
{
	return viacost;
}
int parser::get_spacing()
{
	return spacing;
}
int parser::get_n_metal_layers()
{
	return n_metal_layers;
}
int parser::get_n_routed_shapes()
{
	return n_routed_shapes;
}
int parser::get_n_routed_vias()
{
	return n_routed_vias;
}
int parser::get_n_obstacles()
{
	return n_obstacles;
}
vector<block>* parser::get_routed_shape()
{
	return &v_shape;
}
vector<via>* parser::get_routed_via()
{
	return &v_via;
}
vector<block>* parser::get_obstacle()
{
	return &v_obstacle;
}
boundary* parser::get_boundary()
{
	return &v_boundary;
}

void set_coords(string str,boundary* b1)
{
	string a;
	stringstream ss;
	node A,B;
	cout<<"str str1"<<str<<endl;
	
	int j = 1;
	while(str[j]!=',')
	{
		a = a+str[j];
		j++;
	}
	ss<<a<<' ';
	j++;
	a.clear();
	while(str[j]!=')')
	{
		a = a+str[j];
		j++;
	}
	ss<<a<<' ';
	j=j+3;
	a.clear();	
	while(str[j]!=',')
	{
		a = a+str[j];
		j++;
	}		
	ss<<a<<' ';
	j++;
	a.clear();
	while(str[j]!=')')
	{
		a = a+str[j];
		j++;
	}ss<<a<<' ';
	ss>>A.x>>A.y>>B.x>>B.y;
	b1->left_down = A;
	b1->right_up = B;
}

void set_blocks(istream* ifs, vector<block>* vs, vector<via>* vv, vector<block>* vo)
{
	string name,temp,str1,str2;
	stringstream ss;
	boundary n_temp;
	block B;
	via V;
	while(*ifs>>name)
	{
		if(name == "RoutedVia")
		{
			string a;
			*ifs>>temp;
			temp = temp.substr(1,temp.length());
			//cout<<temp<<endl;
			ss<<temp<<' ';
			*ifs>>str1;

			int j = 1;
			while(str1[j]!=',')
			{
				a = a+str1[j];
				j++;
			}
			ss<<a<<' ';
			j++;
			a.clear();
			while(str1[j]!=')')
			{
				a = a+str1[j];
				j++;
			}
			ss<<a<<' ';
			ss>>V.layer>>V.location.x>>V.location.y;
			vv->push_back(V);
		}else
		{
			*ifs>>temp;
			temp = temp.substr(1,temp.length());
			//cout<<temp<<endl;
			ss<<temp;
			ss>>B.layer;
			*ifs>>str1>>str2;
			set_coords(str1+' '+str2,&n_temp);
			B.left_down = n_temp.left_down;
			B.right_up = n_temp.right_up;
			if(name == "RoutedShape")
				vs->push_back(B);
			else
				vo->push_back(B);
		}
		
	}
}