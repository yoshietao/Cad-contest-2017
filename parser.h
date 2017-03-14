#ifndef Parser_h
#define Parser_h

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

struct node{
public:
	int x;
	int y;
};

struct boundary{
public:
	node left_down;
	node right_up;
};

struct via{
public:
	int layer;
	node location;
};

struct block{
public:
	int layer;
	node left_down;
	node right_up;
};

class parser{
public:
	void set_param(istream*);
	int get_viacost();
	int get_spacing();
	boundary* get_boundary();
	int get_n_metal_layers();
	int get_n_routed_shapes();
	int get_n_routed_vias();
	int get_n_obstacles();
	vector<block>* get_routed_shape();
	vector<via>* get_routed_via();
	vector<block>* get_obstacle();
	
private:
	int viacost;
	int spacing;
	int n_metal_layers;
	int n_routed_shapes;
	int n_routed_vias;
	int n_obstacles;
};

#endif