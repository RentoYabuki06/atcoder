#include <iostream>
#include <algorithm>

using namespace std;

int N, M, A[109][19];
int dp[109][1024];

int main()
{
	cin >> N >> M;
	//入力
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++) cin >> A[i][j];
	}
	//配列の初期化
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= (1 << N); j++) dp[i][j] = 1000000000;
	}
	//動的計画法
	dp[0][0] = 0;
	//クーポン1枚目からM枚目まで探索
	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j <= (1 << N); j++)
		{
			//すでに無料になっているかどうか調べる
			int already[19];
			for (int k = 1; k <= N; k++)
			{
				if ((j / (1 << (k - 1)) % 2) == 0) already[k] = 0;
				else already[k] = 1;
			}
			//クーポン券のカウント
			int coupon = 0;
			for (int k = 1; k <= N; k++)
			{
				if (A[i][k] == 1 || already[k] == 1)
				{
					coupon += (1 << (k - 1));
				}
			}
			//遷移
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][coupon] = min(dp[i][coupon], dp[i - 1][j] + 1);
		}
	}
	if (dp[M][(1 << N) - 1] == 1000000000) cout << "-1" << endl;
	else cout << dp[M][(1 << N) - 1] << endl;
	return 0;
}