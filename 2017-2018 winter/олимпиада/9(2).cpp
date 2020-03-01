#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<random>
#include<stdlib.h>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

vector<int> pow2(7);

void fill(int n, int x, int y, int &k, int i, int j, vector<vector<int> > &a)
{
	if (n == 1)
	{
		//cout << k << " " << i << " " << j << " " << x << " " << y << "\n";
		if (x == i && y == j)
		{
			a[j][i + 1] = a[j - 1][i + 1] = a[j - 1][i] = k;
		}
		else if (x == i + 1 && y == j)
		{
			a[j][i] = a[j - 1][i] = a[j - 1][i + 1] = k;
		}
		else if (x == i && y == j - 1)
		{
			//cout << k << " " << i << " " << j << " " << x << " " << y << "\n";
			a[j][i] = a[j][i + 1] = a[j - 1][i + 1] = k;
		}
		else if (x == i + 1 && y == j - 1)
			a[j][i] = a[j - 1][i] = a[j][i + 1] = k;
		++k;
		return;
	}
	if (x >= i + pow2[n - 1])
	{
		if (y > j - pow2[n - 1])
		{
			fill(n - 1, x, y, k, i + pow2[n - 1], j, a);
			a[j - pow2[n - 1] + 1][i + pow2[n - 1] - 1] = k;
			a[j - pow2[n - 1]][i + pow2[n - 1] - 1] = k;
			a[j - pow2[n - 1]][i + pow2[n - 1]] = k;
			++k;
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1] + 1, k, i, j, a);
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1], k, i, j - pow2[n - 1], a);
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1], k, i + pow2[n - 1], j - pow2[n - 1], a);
		}
		else
		{
			fill(n - 1, x, y, k, i + pow2[n - 1], j - pow2[n - 1], a);
			a[j - pow2[n - 1] + 1][i + pow2[n - 1] - 1] = k;
			a[j - pow2[n - 1]][i + pow2[n - 1] - 1] = k;
			a[j - pow2[n - 1] + 1][i + pow2[n - 1]] = k;
			++k;
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1] + 1, k, i, j, a);
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1], k, i, j - pow2[n - 1], a);
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1] + 1, k, i + pow2[n - 1], j, a);
		}
	}
	else
	{
		if (y > j - pow2[n - 1])
		{
			fill(n - 1, x, y, k, i, j, a);
			a[j - pow2[n - 1]][i + pow2[n - 1] - 1] = k;
			a[j - pow2[n - 1]][i + pow2[n - 1]] = k;
			a[j - pow2[n - 1] + 1][i + pow2[n - 1]] = k;
	//		cout << j - pow2[n - 1] << " " << i + pow2[n - 1] - 1 << " \n";
	//		cout << j - pow2[n - 1] << " " << i + pow2[n - 1] << "\n";
			++k;
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1], k, i, j - pow2[n - 1], a);
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1], k, i + pow2[n - 1], j - pow2[n - 1], a);
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1] + 1, k, i + pow2[n - 1], j, a);
		}
		else
		{
			fill(n - 1, x, y, k, i, j - pow2[n - 1], a);
			a[j - pow2[n - 1]][i + pow2[n - 1]] = k;
			a[j - pow2[n - 1] + 1][i + pow2[n - 1]] = k;
			a[j - pow2[n - 1] + 1][i + pow2[n - 1] - 1] = k;
			++k;
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1], k, i + pow2[n - 1], j - pow2[n - 1], a);
			fill(n - 1, i + pow2[n - 1], j - pow2[n - 1] + 1, k, i + pow2[n - 1], j, a);
			fill(n - 1, i + pow2[n - 1] - 1, j - pow2[n - 1] + 1, k, i, j, a);
		}
	}
}

int main()
{
	int n, x, y, k = 1;
	cin >> n >> x >> y;
	--x, --y;
	pow2[0] = 1;
	for (int i = 1; i < n + 1; ++i)
	{
		pow2[i] = 2 * pow2[i - 1];
	}
	vector<vector<int> > a(pow2[n], vector<int>(pow2[n]));
	fill(n, x, y, k, 0, pow2[n] - 1, a);
	for (int i = 0; i < pow2[n]; ++i)
	{
		for (int j = 0; j < pow2[n]; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	//system("pause");
	return 0;
}

