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

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

FILE* in = fopen("sweets.in", "r");
FILE* out = fopen("sweets.out", "w");

int main()
{
	int n, k, ans = INT_MAX;
	fscanf(in, "%d %d", &n, &k);
	vector<vector<bool> > a(n + 1, vector<bool> (k + 1));
	for (int i = 0; i < k + 1; ++i)
		a[0][i] = false;
	int border;
	for (int i = 1; i < n + 1; ++i)
	{
		for (int j = 0; j < k + 1; ++j)
		{
			border = min(i, min(j, k));
			a[i][j] = true;
			for (int sw_now = 1; sw_now <= border; ++sw_now)
			{
				if (i == n && j == k && !a[i - sw_now][sw_now])
					ans = min(ans, sw_now);
				a[i][j] = a[i][j] & a[i - sw_now][sw_now];
			}
			a[i][j] = !a[i][j];
		}
	}
	if (a[n][k])
		fprintf(out, "%d\n", ans);
	else
		fprintf(out, "0\n");
	return 0;
}