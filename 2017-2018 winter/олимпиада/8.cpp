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

//ifstream in("input.txt");
//ofstream out("output.txt");

//FILE* in = fopen("input.txt", "r");
//FILE* out = fopen("output.txt", "w");

//FILE* in = fopen("comments.in", "r");
//FILE* out = fopen("comments.out", "w");

int main()
{
	int n, k, j = 0, maxim = -1, first = 0;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> cnt(256);
	for (int i = 0; i < s.size(); ++i)
	{
		bool flag = false;
		while (j < s.size() && !flag)
		{
			++cnt[s[j]];
			if (cnt[s[j]] > k)
				flag = true;
			++j;
		}
		if (flag)
		{
			--cnt[s[j - 1]];
			--j;
		}
		if (maxim < j - i)
		{
			maxim = j - i;
			first = i;
		}
		--cnt[s[i]];
		//cout << i << " " << j << " " << maxim << " " << first << "\n";
	}
	cout << maxim << " " << first + 1 << "\n";
	//system("pause");
	return 0;
}