#include<climits>
#include<utility>
#include<iostream>

using namespace std;
//dfk
pair<int, int> moves[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int dfs(int a[8][8], int c, int curr_pl, int *x, int *y, int depth)
{
	if (depth == 5)
	{
		int my_score = 0, rival_score = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				my_score += (a[i][j] == c);
				rival_score += (a[i][j] == (1 - c));
			}
		}
		my_score += 5 * ((a[0][0] == c) + (a[0][7] == c) + (a[7][0] == c) + (a[7][7] == c));
		rival_score += 5 * ((a[0][0] == 1 - c) + (a[0][7] == 1 - c) + (a[7][0] == 1 - c) + (a[7][7] == 1 - c));
		for (int i = 0; i < 8; ++i)
		{
			my_score += 2 * ((a[0][i] == c) + (a[i][0] == c) + (a[i][7] == c) + (a[7][i] == c));
			rival_score += 2 * ((a[0][i] == 1 - c) + (a[i][0] == 1 - c) + (a[i][7] == 1 - c) + (a[7][i] == 1 - c));
		}
		if (a[0][0] != -1)
		{
			for (int i = 0; i < 8; ++i)
			{
				my_score += 3 * ((a[i][0] == c && a[0][0] == c) + (a[0][i] == c && a[0][0] == c));
				rival_score += 3 * ((a[i][0] == 1 - c && a[0][0] == 1 - c) + (a[0][i] == 1 - c && a[0][0] == 1 - c));
			}
		}
		if (a[0][7] != -1)
		{
			for (int i = 0; i < 8; ++i)
			{
				my_score += 3 * ((a[i][7] == c && a[0][7] == c) + (a[0][i] == c && a[0][7] == c));
				rival_score += 3 * ((a[i][7] == 1 - c && a[0][7] == 1 - c) + (a[0][i] == 1 - c && a[0][7] == 1 - c));
			}
		}
		if (a[7][0] != -1)
		{
			for (int i = 0; i < 8; ++i)
			{
				my_score += 3 * ((a[i][0] == c && a[0][0] == c) + (a[7][i] == c && a[0][0] == c));
				rival_score += 3 * ((a[i][0] == 1 - c && a[0][0] == 1 - c) + (a[0][i] == 1 - c && a[7][0] == 1 - c));
			}
		}
		if (a[7][7] != -1)
		{
			for (int i = 0; i < 8; ++i)
			{
				my_score += 3 * ((a[i][7] == c && a[0][0] == c) + (a[7][i] == c && a[0][0] == c));
				rival_score += 3 * ((a[i][7] == 1 - c && a[0][0] == 1 - c) + (a[7][i] == 1 - c && a[0][0] == 1 - c));
			}
		}
		if (a[0][0] == -1 && a[7][7] == -1)
		{
			int cnt = 0;
			int first = -1, second = -1, last = -1;
			for (int i = 0; i < 8; ++i)
			{
				if (a[i][i] != -1 && first == -1)
					first = a[i][i];
				else if (a[i][i] != -1 && second == -1 && first != -1)
					second = a[i][i];
				if (a[7 - i][7 - i] != -1 && last == -1)
					last = a[7 - i][7 - i];
				cnt += (a[i][i] != -1);
			}
			if (cnt > 2)
			{
				if (first != second && first == last)
				{
					if (second == c)
						my_score += 10;
					else
						rival_score += 10;
				}
			}
		}
		if (a[0][7] == -1 && a[7][0] == -1)
		{
			int cnt = 0;
			int first = -1, second = -1, last = -1;
			for (int i = 0; i < 8; ++i)
			{
				if (a[i][7 - i] != -1 && first == -1)
					first = a[i][7 - i];
				else if (a[i][7 - i] != -1 && second == -1 && first != -1)
					second = a[i][7 - i];
				if (a[7 - i][i] != -1 && last == -1)
					last = a[7 - i][i];
				cnt += (a[7 - i][7 - i] != -1);
			}
			if (cnt > 2)
			{
				if (first != second && first == last)
				{
					if (second == c)
						my_score += 10;
					else
						rival_score += 10;
				}
			}
		}
		return my_score - rival_score;
	}
	int ii, jj, maxim = INT_MIN, minim = INT_MAX, tmp, true_x, true_y;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			bool flag = false;
			if (a[i][j] == curr_pl)
			{
				if (i == 3 && j == 3 && depth == 0)
					flag = true;
				for (int b = 0; b < 8; ++b)
				{
					int cnt = 0;
					ii = i + moves[b].first, jj = j + moves[b].second;
					/*if (flag)
						cerr << ii << " " << jj << " " << (a[ii][jj] == (1 - curr_pl)) << "\n";*/
					while (ii >= 0 && ii < 8 && jj >= 0 && jj < 8 && a[ii][jj] == (1 - curr_pl))
					{
						ii += moves[b].first, jj += moves[b].second;
						++cnt;
					}
					if (ii >= 0 && ii < 8 && jj >= 0 && jj < 8 && cnt > 0 && a[ii][jj] == -1)
					{
						/*if (flag)
							cerr << ii << " the same " << jj << "\n";*/
						ii = i + moves[b].first, jj = j + moves[b].second;
						while (ii >= 0 && ii < 8 && jj >= 0 && jj < 8 && a[ii][jj] == (1 - curr_pl))
						{
							a[ii][jj] = curr_pl;
							ii += moves[b].first, jj += moves[b].second;
						}
						a[ii][jj] = curr_pl;
						tmp = dfs(a, c, 1 - c, x, y, depth + 1);
						int tmp_i, tmp_j, i1 = i - moves[b].first, j1 = j - moves[b].second;
						tmp_i = ii + moves[b].first, tmp_j = jj + moves[b].second;
						if ((tmp_i == 0 || tmp_j == 0 || tmp_i == 7 || tmp_j == 7) &&
							i1 >= 0 && i1 < 8 && j1 >= 0 && j1 < 8 && a[i1][j1] == 1 - curr_pl)
							tmp -= 5;
						tmp += (ii == 3 || ii == 4) + (jj == 3 || jj == 4);
						if (curr_pl == c)
						{
							if (tmp > maxim)
							{
								maxim = tmp;
								true_x = ii, true_y = jj;
							}
						}
						else
						{
							if (tmp < minim)
							{
								minim = tmp;
								true_x = ii, true_y = jj;
							}
						}
						/*if (flag)
							cerr << ii << " " << true_x << " x y " << jj << " " << true_y << " " << tmp << "\n";*/
						int iii = i + moves[b].first, jjj = j + moves[b].second;
						while (!(iii == ii && jjj == jj))
						{
							a[iii][jjj] = 1 - curr_pl;
							iii += moves[b].first, jjj += moves[b].second;
						}
						a[ii][jj] = -1;
					}
				}
			}
		}
	}
	*x = true_x, *y = true_y;
	if (c == curr_pl)
		return maxim;
	else
		return minim;
}

void move(int a[8][8], int c, int *x, int *y) {
	//c = 1 - c;
	//cerr << c << "\n";
	dfs(a, c, c, x, y, 0);
	//cerr << *x << " in move x y " << *y << "\n";
}

