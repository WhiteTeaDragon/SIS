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

ifstream in("angle3d.in");
ofstream out("angle3d.out");

const double EPS = 1e-7;

struct vect
{
	double x, y, z;
	vect operator* (const vect &b)
	{
		vect ans;
		ans.x = y * b.z - z * b.y;
		ans.y = z * b.x - x * b.z;
		ans.z = x * b.y - y * b.x;
		return ans;
	}
	double len()
	{
		return sqrt(x * x + y * y + z * z);
	}
};

bool is_zero(vect a)
{
	return fabs(a.x) < EPS && fabs(a.y) < EPS && fabs(a.z) < EPS;
}

double angle(vect a, vect b)
{
	if (is_zero(a) && is_zero(b))
		return 0.;
	if (is_zero(a) || is_zero(b))
		return M_PI / 2;
	return asin((a * b).len() / a.len() / b.len());
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