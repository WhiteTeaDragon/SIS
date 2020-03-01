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

//ifstream in("input.txt");
//ofstream out("output.txt");

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

FILE* in = fopen("bulbul.in", "r");
FILE* out = fopen("bulbul.out", "w");

struct node
{
	bool is_term;
	node* to[256];
};

int main()
{
	string s;
	char tmp[100000];
	fscanf(in, "%s", tmp);
	s = tmp;
	int n, m, k, x;
	fscanf(in, "%d %d %d", &n, &m, &k);
	vector<node*> nodes(n + 1);
	for (int i = 0; i < n + 1; ++i)
	{
		nodes[i] = new node;
		for (int j = 0; j < 256; ++j)
			nodes[i]->to[j] = nodes[0];
		nodes[i]->is_term = false;
	}
	for (int i = 0; i < k; ++i)
	{
		fscanf(in, "%d", &x);
		nodes[x]->is_term = true;
	}
	int from, to;
	char by;
	for (int i = 0; i < m; ++i)
	{
		fscanf(in, "%d %d %c", &from, &to, &by);
		nodes[from]->to[(int)by] = nodes[to];
	}
	node* curr = nodes[1];
	for (int i = 0; i < (int)s.size(); ++i)
		curr = curr->to[(int)s[i]];
	if (curr->is_term)
		fprintf(out, "Accepts\n");
	else
		fprintf(out, "Rejects\n");
	return 0;
}