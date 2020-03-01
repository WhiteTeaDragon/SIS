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

FILE* in = fopen("comments.in", "r");
FILE* out = fopen("comments.out", "w");

int main()
{
	char prev_x = 0, x;
	int state = 0;
	string ans;
	while (fscanf(in, "%c", &x) == 1)
	{
		if (prev_x == 0)
		{
			prev_x = x;
			continue;
		}
		if (state == 0)
		{
			if (prev_x == '/' && x == '/')
				state = 1;
			else if (prev_x == '{')
				state = 2;
			else if (prev_x == '/' && x == '*')
				state = 3;
			else
				ans += prev_x;
		}
		else if (state == 1)
		{
			if (prev_x == '\n')
			{
				state = 0;
				ans += prev_x;
			}
		}
		else if (state == 2)
		{
			if (prev_x == '}')
				state = 0;
		}
		else if (state == 3)
		{
			if (prev_x == '*' && x == '/')
			{
				state = 0;
				prev_x = x = 0;
			}
		}
		prev_x = x;
	}
	if (prev_x != 0 && (state == 0 || prev_x == '\n'))
		ans += prev_x;
	else if (prev_x == 0 && x != 0)
		ans += x;
	fprintf(out, "%s", ans.c_str());
	return 0;
}