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
#include<queue>

using namespace std;

int gcd(int a, int b)
{
	while (b > 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return a;
}

//FILE* in = fopen("inv.in", "r");
//FILE* out = fopen("inv.out", "w");

FILE* in = fopen("input.txt", "r");
FILE* out = fopen("output.txt", "w");

int main()
{
	long long n, m;
	fscanf(in, "%lld %lld", &n, &m);
	return 0;
}