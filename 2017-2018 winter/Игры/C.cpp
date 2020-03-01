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

FILE* in = fopen("cruel.in", "r");
FILE* out = fopen("cruel.out", "w");

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

int main()
{
	int n, curr, left, right;
	fscanf(in, "%d", &n);
	vector<int> g(n + 1);
	vector<bool> used(n + 1);
	vector<int> ans;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			curr = g[j] ^ g[i - j - 1];
			if (curr < n + 1)
				used[curr] = true;
			if (i == n && curr == 0)
				ans.push_back(j + 1);
		}
		for (int j = 0; j < n + 1; ++j)
		{
			if (!used[j])
			{
				g[i] = j;
				break;
			}
		}
		for (int b = 0; b < n + 1; ++b)
			used[b] = false;
	}
	if (g[n] == 0)
	{
		fprintf(out, "Mueller\n");
	}
	else
	{
		fprintf(out, "Schtirlitz\n");
		for (int i = 0; i < ans.size(); ++i)
			fprintf(out, "%d\n", ans[i]);
	}
	return 0;
}