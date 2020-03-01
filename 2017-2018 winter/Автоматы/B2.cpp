#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<cmath>
#include<map>
#include<set>
#include<climits>
#include<queue>

using namespace std;

//FILE* in = fopen("comments.in", "r");
//FILE* out = fopen("comments.out", "w");

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

struct node;

struct edge
{
	node* to;
	bool print_curr;
	char to_print;
};

struct node
{
	bool is_term;
	edge to[256];
};

int main()
{
	ifstream in("comments.in");
	ofstream out("comments.out");
	vector<node*> nodes(6);
	for (int i = 0; i < 6; ++i)
	{
		nodes[i] = new node;
		nodes[i]->is_term = false;
		for (int j = 0; j < 256; ++j)
		{
			nodes[i]->to[j].print_curr = false;
			nodes[i]->to[j].to_print = '&';
		}
	}
	nodes[0]->is_term = true;
	for (int i = 0; i < 256; ++i)
	{
		if (i != '/' && i != '{')
		{
			nodes[0]->to[i].to = nodes[0];
			nodes[0]->to[i].print_curr = true;
		}
		if (i != '/' && i != '*' && i != '{')
		{
			nodes[1]->to[i].to = nodes[0];
			nodes[1]->to[i].print_curr = true;
			nodes[1]->to[i].to_print = '/';
		}
		if (i != '}')
		{
			nodes[2]->to[i].to = nodes[2];
		}
		if (i != '\n')
		{
			nodes[3]->to[i].to = nodes[3];
		}
		if (i != '*')
		{
			nodes[4]->to[i].to = nodes[4];
		}
		if (i != '/' && i != '*')
		{
			nodes[5]->to[i].to = nodes[4];
		}
	}
	nodes[0]->to['/'].to = nodes[1];
	nodes[0]->to['{'].to = nodes[2];
	nodes[1]->to['/'].to = nodes[3];
	nodes[1]->to['*'].to = nodes[4];
	nodes[1]->to['{'].to = nodes[2];
	nodes[1]->to['{'].to_print = '/';
	nodes[2]->to['}'].to = nodes[0];
	nodes[3]->to['\n'].to = nodes[0];
	nodes[3]->to['\n'].to_print = '\n';
	nodes[4]->to['*'].to = nodes[5];
	nodes[5]->to['/'].to = nodes[0];
	nodes[5]->to['*'].to = nodes[5];
	char x;
	node* curr = nodes[0];
	string ans = "", a = "", line;
	in >> noskipws;
	int i = 0;
	while (in >> x)
	{
		if (curr->to[x].to_print != '&')
		{
			ans += curr->to[x].to_print;
		}
		if (curr->to[x].print_curr)
		{
			ans += x;
		}
		curr = curr->to[x].to;
		++i;
	}
	if (curr == nodes[1] || curr == nodes[3] && x == '\n')
		ans += x;
	out << ans;
	return 0;
}