#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<random>
#include<stdlib.h>

using namespace std;

//ifstream in("input.txt");
ofstream out("output.txt");

struct vect {
	int x, y;
	vect(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	int operator* (const vect &b) const
	{
		return x * b.y - y * b.x;
	}
	int operator% (const vect &b) const
	{
		return x * b.x + y * b.y;
	}
};

struct line {
	int a, b, c;
	line(int a1, int b1, int c1)
	{
		a = a1;
		b = b1;
		c = c1;
	}
	line(vect e, vect d)
	{
		a = e.y - d.y;
		b = d.x - e.x;
		c = e.x * d.y - e.y * d.x;
	}
	double dist_to(const vect &p) const
	{
		return (double)(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
	}
};

int main()
{
	int n, i = -10000, j = -10000;
	cin >> n;
	vector<pair<int, int> > ans;
	while (n >= 0)
	{
		for (int i = 0; i < 4; ++i)
		{
			ans.push_back({ i, j });
			--n;
			if (i == 0)
			{
				++i;
				--j;
			}
			if (i == 1)
			{
				--i;
				--j;
			}
			if (i == 2)
			{
				++i;
				--j;
			}
			if (n == 0)
				break;
		}
		i += 2;
		--j;
	}
	return 0;
}

