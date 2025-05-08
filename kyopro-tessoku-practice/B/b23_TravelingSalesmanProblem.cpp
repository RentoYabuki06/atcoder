#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, X[20], Y[20];
float dp[32768][20];

float ft_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
	//入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	
	//配列の初期化
	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 0; j <= N; j++) dp[i][j] = 100000000;
	}
	//初期値の代入
	dp[1][1] = 0;
	//動的計画法
	//1の都市からスタート、すべての都市を巡る直前まで探索
	for (int i = 1; i <= (1 << N) - 1; i++)
	{
		//今いる都市をj、次に移動する都市をkと置いて
		for (int j = 1; j <= N; j++)
		{
			if (!(i & (1 << (j - 1)))) continue;//未到達の都市はスキップ
			//次に移動する都市をkとおく
			for(int k = 2; k <= N; k++)
			{
				if (i & (1 << (k - 1))) continue;//すでに到達している都市はスキップ
				dp[i | (1 << (k - 1))][k] = min(dp[i | (1 << (k - 1))][k], dp[i][j] + ft_distance(X[j], Y[j], X[k], Y[k]));
			}
		}
	}
	float ans = 100000000;
	for (int i = 1; i <= N; i++)
	{
		ans = min(ans, dp[(1 << N) - 1][i] + ft_distance(X[i], Y[i], X[1], Y[1]));
	}

	cout << ans << endl;
	return 0;
}
