#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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

ifstream in("input.txt");
ofstream out("output.txt");

struct vect
{
	int x, y, z;
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

bool is_zero(vect a)
{
	return a.x == 0 && a.y == 0 && a.z == 0;
}

double angle(vect a, vect b)
{
	if (is_zero(a) || is_zero(b))
		return M_PI / 2;
	return fabs(atan2((a * b).len(), (double)(a % b)));
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