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

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int x = max(a, max(b, c));
	vector<int> g(x + 1);
	vector<bool> used(x + 1);
	g[1] = 0;
	int ans_a = -1, ans_b = -1, ans_c = -1;
	for (int i = 2; i < x + 1; ++i)
	{
		for (int j = (i + 1) / 2; j < i; ++j)
		{
			used[g[j]] = true;
		}
		for (int j = 0; j < x + 1; ++j)
		{
			if (!used[j])
			{
				g[i] = j;
				break;
			}
		}
		for (int b = 0; b < x + 1; ++b)
			used[b] = false;
	}
	if (((g[a] ^ g[b]) ^ g[c]) == 0)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = (a + 1) / 2; i < a; ++i)
		{
			if (((g[i] ^ g[b]) ^ g[c]) == 0)
			{
				ans_a = i, ans_b = b, ans_c = c;
			}
		}
		for (int i = (b + 1) / 2; i < b; ++i)
		{
			if (((g[i] ^ g[a]) ^ g[c]) == 0)
			{
				ans_a = a, ans_b = i, ans_c = c;
			}
		}
		for (int i = (c + 1) / 2; i < c; ++i)
		{
			if (((g[i] ^ g[a]) ^ g[b]) == 0)
			{
				ans_a = a, ans_b = b, ans_c = i;
			}
		}
		cout << ans_a << " " << ans_b << " " << ans_c << "\n";
	}
	system("pause");
	return 0;
}