#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

FILE* in = fopen("sqroot.in", "r");
FILE* out = fopen("sqroot.out", "w");
int p = 2;

struct table
{
	int n, m;
	vector<vector<int> > t;
	table(int a, int b)
	{
		n = a, m = b;
		t.resize(n, vector<int>(m));
	}
	table operator* (const table &a)
	{
		table ans(n, a.m);
		for (int i = 0; i < ans.n; ++i)
		{
			for (int j = 0; j < ans.m; ++j)
			{
				for (int k = 0; k < m; ++k)
				{
					ans.t[i][j] = (ans.t[i][j] + (t[i][k] * a.t[k][j]) % 2) % 2;
				}
			}
		}
		return ans;
	}
	bool operator== (const table &a)
	{
		if (n != a.n || m != a.m)
			return false;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (t[i][j] != a.t[i][j])
					return false;
			}
		}
		return true;
	}
};

void read(table &a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			fscanf(in, "%d", &a.t[i][j]);
		}
	}
}

void print(table &a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			fprintf(out, "%d ", a.t[i][j]);
		}
		fprintf(out, "\n");
	}
}

int main()
{
	int tmp, ind = 0, jnd = 0;
	table a(4, 4);
	read(a);
	for (int i = 0; i < (1 << 16); ++i)
	{
		ind = 0, jnd = 0;
		tmp = i;
		table curr(4, 4);
		while (ind < 4 && jnd < 4 && tmp > 0)
		{
			curr.t[ind][jnd] = tmp & 1;
			tmp = tmp >> 1;
			if (ind + 1 > 3)
			{
				ind = 0;
				++jnd;
			}
			else
				++ind;
		}
		if ((curr * curr) == a)
		{
			print(curr);
			return 0;
		}
	}
	fprintf(out, "NO SOLUTION\n");
	return 0;
}