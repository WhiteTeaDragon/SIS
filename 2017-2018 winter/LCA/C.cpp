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

FILE* in = fopen("minonpath.in", "r");
FILE* out = fopen("minonpath.out", "w");

void dfs(int s, vector<vector<pair<int, int> > > &graph, vector<int> &t_in, vector<int> &t_out, int &time,
	vector<vector<int> > &p, vector<vector<int> > &p_min)
{
	t_in[s] = time;
	++time;
	for (pair<int, int> v : graph[s])
	{
		p[v.first][0] = s;
		p_min[v.first][0] = v.second;
		for (int i = 1; i < 17; ++i)
		{
			p[v.first][i] = p[p[v.first][i - 1]][i - 1];
			p_min[v.first][i] = min(p_min[v.first][i - 1], p_min[p[v.first][i - 1]][i - 1]);
		}
		dfs(v.first, graph, t_in, t_out, time, p, p_min);
	}
	t_out[s] = time;
	++time;
}

bool is_anc(int a, int b, vector<int> &t_in, vector<int> &t_out)
{
	return t_in[a] <= t_in[b] && t_out[b] <= t_out[a];
}

int find_min(int a, int b, vector<int> &t_in, vector<int> &t_out, vector<vector<int> > &p,
	vector<vector<int> > &p_min)
{
	int i = 16, ans = INT_MAX, a_copy = a;
	while (i >= 0)
	{
		if (!is_anc(p[a][i], b, t_in, t_out))
		{
			ans = min(ans, p_min[a][i]);
			a = p[a][i];
		}
		--i;
	}
	if (!is_anc(a, b, t_in, t_out))
		ans = min(ans, p_min[a][0]);
	a = a_copy, i = 16;
	while (i >= 0)
	{
		if (!is_anc(p[b][i], a, t_in, t_out))
		{
			ans = min(ans, p_min[b][i]);
			b = p[b][i];
		}
		--i;
	}
	if (!is_anc(b, a, t_in, t_out))
		ans = min(ans, p_min[b][0]);
	return ans;
}

int main()
{
	int n, fr, w, m, x, y, time = 0;
	fscanf(in, "%d", &n);
	vector<vector<pair<int, int> > > graph(n);
	for (int i = 1; i < n; ++i)
	{
		fscanf(in, "%d %d", &fr, &w);
		graph[fr - 1].push_back({ i, w });
	}
	vector<vector<int> > p(n, vector<int>(17));
	vector<vector<int> > p_min(n, vector<int>(17, INT_MAX));
	vector<int> t_in(n), t_out(n);
	dfs(0, graph, t_in, t_out, time, p, p_min);
	fscanf(in, "%d", &m);
	for (int i = 0; i < m; ++i)
	{
		fscanf(in, "%d %d", &x, &y);
		--x;
		--y;
		fprintf(out, "%d\n", find_min(x, y, t_in, t_out, p, p_min));
	}
	return 0;
}