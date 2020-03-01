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

ifstream in("planes.in");
ofstream out("planes.out");

long long gcd(long long a, long long b)
{
	long long tmp;
	while (b > 0)
	{
		tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

struct vect
{
	long long x, y, z;
	vect(long long a, long long b, long long c)
	{
		x = a, y = b, z = c;
	}
	vect()
	{
		x = y = z = 0;
	}
	vect operator* (const vect &b)
	{
		vect ans;
		ans.x = y * b.z - z * b.y;
		ans.y = z * b.x - x * b.z;
		ans.z = x * b.y - y * b.x;
		return ans;
	}
};

struct plane
{
	long long a, b, c, d;
	vect n;
	plane()
	{
		a = 0, b = 0, c = 0, d = 0;
	}
	void normalize()
	{
		long long x = gcd(abs(a), gcd(abs(b), gcd(abs(c), abs(d))));
		a /= x;
		b /= x;
		c /= x;
		d /= x;
		if (a < 0)
		{
			a *= (-1LL);
			b *= (-1LL);
			c *= (-1LL);
			d *= (-1LL);
		}
		else if (a == 0)
		{
			if (b < 0)
			{
				b *= (-1LL);
				c *= (-1LL);
				d *= (-1LL);
			}
			else if (b == 0)
			{
				if (c < 0)
				{
					c *= (-1LL);
					d *= (-1LL);
				}
			}
		}
	}
};

istream& operator>> (istream &is, plane &p)
{
	is >> p.a >> p.b >> p.c >> p.d;
	return is;
}

bool are_the_same(const plane &a, const plane &b)
{
	return (a.a == b.a && a.b == b.b && a.c == b.c && a.d == b.d);
}

bool is_zero(vect a)
{
	return a.x == 0 && a.y == 0 && a.z == 0;
}

int main()
{
	const double EPS = 1e-7;
	plane p1, p2;
	in >> p1 >> p2;
	p1.n = vect(p1.a, p1.b, p1.c);
	p2.n = vect(p2.a, p2.b, p2.c);
	p1.normalize();
	p2.normalize();
	if (is_zero(p1.n * p2.n))
	{
		if (are_the_same(p1, p2))
			out << 2 << '\n';
		else
			out << 0 << '\n';
	}
	else
		out << 1 << '\n';
	return 0;
}