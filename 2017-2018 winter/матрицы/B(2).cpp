#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

FILE* in = fopen("input2.txt", "r");
FILE* out = fopen("output.txt", "w");
int p;

struct table
{
	int n, m;
	vector<vector<long long> > t;
	table(int a, int b)
	{
		n = a, m = b;
		t.resize(n, vector<long long>(m));
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
					ans.t[i][j] = (ans.t[i][j] + (t[i][k] * a.t[k][j]) % p) % p;
				}
			}
		}
		return ans;
	}
};

table pow(table &a, long long k)
{
	cerr << k << "\n";
	if (k == 0)
	{
		table ans(a.n, a.n);
		for (int i = 0; i < a.n; ++i)
			ans.t[i][i] = 1;
		return ans;
	}
	if (k % 2 != 0)
	{
		cerr << k << "\n";
		return a * pow(a, k - 1);
	}
	else
	{
		table y = pow(a, k / 2);
		cerr << k << '\n';
		return y * y;
	}
}

void read(table &a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			fscanf(in, "%lld", &a.t[i][j]);
		}
	}
}

void print(table &a)
{
	for (int i = 0; i < a.n; ++i)
	{
		for (int j = 0; j < a.m; ++j)
		{
			fprintf(out, "%lld ", a.t[i][j]);
		}
		fprintf(out, "\n");
	}
}

int main()
{
	int n;
	long long m;
	fscanf(in, "%d %lld %d", &n, &m, &p);
	table a(n, n);
	read(a);
	a = pow(a, m);
	print(a);
	fclose(in);
	fclose(out);
	//system("pause");
	return 0;
}