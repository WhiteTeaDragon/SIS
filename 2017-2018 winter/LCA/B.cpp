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

FILE* in = fopen("lca2.in", "r");
FILE* out = fopen("lca2.out", "w");

void dfs(int s, vector<vector<int> > &graph, vector<pair<int, int> > &way, vector<int> &pos_in, int dpth)
{
	way.push_back({ dpth, s });
	pos_in[s] = way.size() - 1;
	for (int v : graph[s])
	{
		dfs(v, graph, way, pos_in, dpth + 1);
		way.push_back({ dpth, s });
	}
}

int main()
{
	long long v;
	int m;
	long long a1, a2, x, y, z;
	fscanf(in, "%lld %d", &v, &m);
	vector<vector<int> > graph(v);
	for (int i = 1; i < v; ++i)
	{
		fscanf(in, "%d", &x);
		graph[x].push_back(i);
	}
	fscanf(in, "%lld %lld %lld %lld %lld", &a1, &a2, &x, &y, &z);
	vector<pair<int, int> > way;
	vector<int> pos_in(v);
	dfs(0, graph, way, pos_in, 0);
	int n = way.size();
	vector<int> logs(n + 1, -1);
	logs[1] = 0;
	for (int i = 2; i < n + 1; ++i)
	{
		logs[i] = 1 + logs[i / 2];
	}
	vector<vector<pair<int, int> > > sparse_table(logs[n] + 2, vector<pair<int, int> >(n, { INT_MAX, INT_MAX }));
	sparse_table[0] = way;
	int pow;
	for (int i = 1; i < sparse_table.size(); ++i)
	{
		pow = (1 << (i - 1));
		for (int j = 0; j + pow < n; ++j)
		{
			sparse_table[i][j] = min(sparse_table[i - 1][j], sparse_table[i - 1][j + pow]);
		}
	}
	int first, second, len, len_log;
	long long a, b;
	pair<int, int> ans = { 0, 0 };
	long long sum = 0;
	for (int i = 0; i < m; ++i)
	{
		first = pos_in[(a1 + (long long)ans.second) % v], second = pos_in[a2];
		if (second < first)
			swap(second, first);
		len = second - first + 1;
		len_log = logs[len];
		ans = min(sparse_table[len_log][first], sparse_table[len_log][second - (1 << len_log) + 1]);
		sum += (long long)ans.second;
		a = a1, b = a2;
		a1 = ((x * a) % v + (y * b) % v + z) % v;
		a2 = ((x * b) % v + (y * a1) % v + z) % v;
	}
	fprintf(out, "%lld\n", sum);
	fclose(in);
	fclose(out);
	return 0;
}