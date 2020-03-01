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
	const double EPS = 1e-7;
	int n = 2000;
	vector<vect> ans;
	vect n_p(0, 0);
	cout.precision(16);
	for (int i = 0; i < n; ++i)
	{
		if (ans.size() < 2)
		{
			ans.push_back(vect(-10000 + (rand() * (int)20000 / RAND_MAX), -10000 + (rand() * (int)20000 / RAND_MAX)));
			continue;
		}
		while (true)
		{
			bool flag = true;
			n_p = vect(-10000 + (rand() * (int)20000 / RAND_MAX), -10000 + (rand() * (int)20000 / RAND_MAX));
			for (int j = 0; j < ans.size(); ++j)
			{
				for (int k = j + 1; k < ans.size(); ++k)
				{
					line a(ans[j], ans[k]);
					if (a.dist_to(n_p) < EPS)
					{
						flag = false;
						break;
					}
					//cout << j << " " << k << " " << flag << " " << ans.size() << " " << a.dist_to(n_p) << "\n";
				}
				if (!flag)
					break;
			}
			if (flag)
				break;
			//cout << n_p.x << " " << flag << " " << n_p.y << "\n";
		}
		ans.push_back(n_p);
		cout << i << "\n";
	}
	for (int i = 0; i < n; ++i)
	{
		out << '{' << ans[i].x << ", " << ans[i].y << "}, ";
	}
	return 0;
}

