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

ifstream in("volume.in");
ofstream out("volume.out");

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
	long long operator% (const vect &b)
	{
		return x * b.x + y * b.y + z * b.z;
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

int main()
{
	vect a, b, c, d;
	in >> a >> b >> c >> d;
	d.enlarge(-1);
	a = a + d;
	b = b + d;
	c = c + d;
	double v = fabs((a % (b * c))) / 6.;
	out.precision(16);
	out << v << "\n";
	return 0;
}