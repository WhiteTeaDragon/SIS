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

ifstream in("orthogonal.in");
ofstream out("orthogonal.out");

struct vect
{
	int x, y, z;
	vect(int a, int b, int c)
	{
		x = a, y = b, z = c;
	}
	vect()
	{
		x = y = z = 0;
	}
};

vect rotate_90(vect a)
{
	if (a.y == 0 && a.z == 0)
		return vect(0, a.x, 0);
	return vect(0, -a.z, a.y);
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
	vect a, ort_a;
	in >> a;
	ort_a = rotate_90(a);
	out << ort_a << '\n';
	return 0;
}