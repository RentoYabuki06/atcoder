#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W, K;
char tile[19][109];
char tile_test[19][109];

int	ft_score()
{
	int score = 0;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (tile_test[i][j] == '#') score++;
		}
	}
	return score;
}

void ft_paint_column(int remainig_steps)
{
	vector<pair<int, int>> columns;
	for (int j = 1; j <= W; j++)
	{
		int count = 0;
		for (int i = 1; i <= H; i++)
		{
			if (tile_test[i][j] == '.') count++;
		}
		columns.push_back(make_pair(count, j));
	}
	sort(columns.begin(), columns.end());
	reverse(columns.begin(), columns.end());
	// 余っている回数分、白が多い列から塗っていく
	for (int k = 0; k < remainig_steps && k < W; k++)
	{
		for (int i = 1; i <= H; i++) tile_test[i][columns[k].second] = '#';
	}
}

int main()
{
	// 入力
	cin >> H >> W >> K;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++) cin >> tile[i][j];
	}
	// 列の全探索
	int ans = 0;
	for (int i = 0; i < (1 << H); i++)
	{
		int remainig_steps = K;
		for (int i = 1; i <= H; i++)
		{
			for (int j = 1; j <= W; j++) tile_test[i][j] = tile[i][j];
		}
		for (int k = 0; k < H; k++)
		{
			if (remainig_steps < 1) break;
			if ((i >> k) & 1)
			{
				remainig_steps--;
				for (int j = 1; j <= W; j++) tile_test[k + 1][j] = '#';
			}
		}
		if(remainig_steps > 0) ft_paint_column(remainig_steps);
		ans = max(ans, ft_score());
	}
	cout << ans << endl;
	return 0;
}