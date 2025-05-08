#include <iostream>

using namespace std;

int N, K;
int dp[32][300009];		// 制約が10^9なので2^10=1024より、2^30あれば十分

int main()
{
	// 入力
	cin >> N >> K;

	// 前もって計算しておく
	// 1回目の操作で、一番近い9の倍数に合流する。9*nという形で表現する？
	for (int i = 1; i <= N; i++) dp[0][i] = ;
	for (int d = 1; d <= 30; d++)
	{
		for (int i = 1; i <= N; i++) dp[d][i] = dp[d - 1][dp[d - 1][i]];
	}

	// クエリの処理
	for (int i = 1; i <= Q; i++)
	{
		int pos = X[i];
		for (int d = 30; d >= 0; d--)
		{
			if ((Y[i] >> d) & 1) pos = dp[d][pos];
		}
		cout << pos << endl;
	}
	return 0;
}