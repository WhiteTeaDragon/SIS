#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<random>
#include<stdlib.h>

using namespace std;

//ifstream in("input.txt");
//ofstream out("output.txt");

int main()
{
	int n, x;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if (x == 2)
			x = -1;
		sum += x;
	}
	if (sum == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	//system("pause");
	return 0;
}

