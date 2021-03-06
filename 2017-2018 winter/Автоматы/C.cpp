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
#include<unordered_set>

using namespace std;

ifstream in("hawfinch.in");
ofstream out("hawfinch.out");

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

//FILE* in = fopen("hawfinch.in", "r");
//FILE* out = fopen("hawfinch.out", "w");

struct node
{
	bool is_term;
	vector<node*> to[256];
};

int main()
{
	string s;
	in >> s;
	int n, m, k, x;
	in >> n >> m >> k;
	vector<node*> nodes(n + 1);
	for (int i = 0; i < n + 1; ++i)
	{
		nodes[i] = new node;
		for (int j = 0; j < 256; ++j)
			(nodes[i]->to[j]).push_back(nodes[0]);
		nodes[i]->is_term = false;
	}
	for (int i = 0; i < k; ++i)
	{
		in >> x;
		nodes[x]->is_term = true;
	}
	int from, to;
	char by;
	for (int i = 0; i < m; ++i)
	{
		in >> from >> to >> by;
		if ((nodes[from]->to[by]).back() == nodes[0])
			(nodes[from]->to[by]).pop_back();
		(nodes[from]->to[(int)by]).push_back(nodes[to]);
	}
	vector<unordered_set<node*> > curr_states(2);
	node* curr = nodes[1];
	curr_states[0].insert(curr);
	int i1, i2;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		i1 = i % 2, i2 = (i + 1) % 2;
		curr_states[i2].clear();
		for (node* j : curr_states[i1])
		{
			for (int b = 0; b < ((j->to[s[i]]).size()); ++b)
			{
				curr_states[i2].insert(j->to[s[i]][b]);
			}
		}
	}
	bool flag = false;
	for (auto i : curr_states[i2])
	{
		if (i->is_term)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		out << "Accepts\n";
	else
		out << "Rejects\n";
	for (int i = 0; i < n + 1; ++i)
	{
		delete(nodes[i]);
	}
	return 0;
}