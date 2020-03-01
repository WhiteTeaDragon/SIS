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

ifstream in("angle3d.in");
ofstream out("angle3d.out");

struct vect
{
	long long x, y, z;
	vect operator* (const vect &b)
	{
		vect ans;
		ans.x = y * b.z - z * b.y;
		ans.y = z * b.x - x * b.z;
		ans.z = x * b.y - y * b.x;
		return ans;
	}
	int operator% (const vect &b)
	{
		return x * b.x + y * b.y + z * b.z;
	}
	double len()
	{
		return sqrt((double)(x * x) + (double)(y * y) + (double)(z * z));
	}
};

double angle(vect &a, vect &b)
{
	return atan2((a * b).len(), (double)(a % b));
}

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
	vect a, b;
	in >> a >> b;
	out.precision(16);
	out << angle(a, b) << "\n";
	return 0;
}