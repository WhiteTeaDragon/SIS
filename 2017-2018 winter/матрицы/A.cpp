#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

FILE* in = fopen("mmul.in", "r");
FILE* out = fopen("mmul.out", "w");

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
					ans.t[i][j] += t[i][k] * a.t[k][j];
				}
			}
		}
		return ans;
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
	int p, q, r;
	fscanf(in, "%d %d %d", &p, &q, &r);
	table a(p, q), b(q, r);
	read(a), read(b);
	table c = a * b;
	print(c);
	fclose(in);
	fclose(out);
	//system("pause");
	return 0;
}