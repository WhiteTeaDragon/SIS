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

ifstream in("plane1.in");
ofstream out("plane1.out");

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
	vect operator+ (const vect &b)
	{
		return vect(x + b.x, y + b.y, z + b.z);
	}
	void enlarge(long long k)
	{
		x *= k;
		y *= k;
		z *= k;
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
	plane(vect x, vect y, vect z)
	{
		x.enlarge(-1);
		vect xy = y + x, xz = z + x;
		vect ort = xy * xz;
		a = ort.x, b = ort.y, c = ort.z;
		d = -a * y.x - b * y.y - c * y.z;
	}
};

istream& operator>> (istream &is, vect &v)
{
	is >> v.x >> v.y >> v.z;
	return is;
}

ostream& operator<<(ostream &os, const vect &v)
{
	os << v.x << " " << v.y << " " << v.z;
	return os;
}

ostream& operator<<(ostream &os, const plane &p)
{
	os << p.a << " " << p.b << " " << p.c << " " << p.d;
	return os;
}

int main()
{
	vect a, b, c, ab, ac, ort;
	in >> a >> b >> c;
	plane pl(a, b, c);
	out << pl << "\n";
	return 0;
}