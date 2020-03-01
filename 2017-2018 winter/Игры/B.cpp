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

//FILE* in = fopen("retro.in", "r");
//FILE* out = fopen("retro.out", "w");

FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");

enum states
{
	LOSE = -1,
	DRAW = 0,
	WIN = 1
};

void bfs(vector<vector<int> > &graph_trans, vector<int> &game_state, vector<int> &cnt, vector<bool> &visited,
	queue<int> &q)
{
	int x, curr;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int curr : graph_trans[x])
		{
			if (visited[curr])
				continue;
			if (game_state[x] == LOSE)
			{
				game_state[curr] = WIN;
				q.push(curr);
				visited[curr] = true;
			}
			else
			{
				--cnt[curr];
				if (cnt[curr] == 0)
				{
					game_state[curr] = LOSE;
					q.push(curr);
					visited[curr] = true;
				}
			}
		}
	}
}

void analyse_this(int n, int m)
{
	vector<vector<int> > graph_trans(n);
	vector<int> cnt(n);
	vector<int> game_state(n, DRAW);
	vector<bool> visited(n);
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		fscanf(in, "%d %d", &x, &y);
		--x;
		--y;
		graph_trans[y].push_back(x);
		++cnt[x];
	}
	queue<int> q;
	for (int i = 0; i < n; ++i)
	{
		if (cnt[i] == 0)
		{
			game_state[i] = LOSE;
			visited[i] = true;
			q.push(i);
		}
	}
	bfs(graph_trans, game_state, cnt, visited, q);
	for (int i = 0; i < n; ++i)
	{
		if (game_state[i] == LOSE)
			fprintf(out, "SECOND\n");
		else if (game_state[i] == DRAW)
			fprintf(out, "DRAW\n");
		else
			fprintf(out, "FIRST\n");
	}
}

int main()
{
	int n, m;
	while (fscanf(in, "%d %d", &n, &m) == 2)
	{
		analyse_this(n, m);
	}
	return 0;
}