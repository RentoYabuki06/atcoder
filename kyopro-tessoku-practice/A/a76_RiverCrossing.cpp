#include <iostream>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

long long N, W, L, R;
long long X[150009];
long long dp[150009];
long long sum[150009];

int main()
{
	// 入力
	cin >> N >> W >> L >> R;
	for (int i = 1; i <= N; i++) cin >> X[i];
	X[0] = 0;
	X[N + 1] = W;
	for (int i = 0; i <= N + 1; i++)
	{
		sum[i] = 0;
		dp[i] = 0;
	}
	// 動的計画法
	dp[0] = 1;
	sum[0] = 1;
	for (int i = 1; i <= N + 1; i++)
	{
		int posL = lower_bound(X, X + N + 2, X[i] - R) - X;
		int posR = lower_bound(X, X + N + 2, X[i] - L + 1) - X;
		posR--;
		// 累積和でdp[i]を計算
		if (posR == -1) dp[i] = 0;
		else dp[i] = sum[posR];
		if (posL >= 1) dp[i] -= sum[posL - 1];
		dp[i] = (dp[i] + mod) % mod; // 引き算のあまりに注意！
		// 累積和 sum[i] を更新
		sum[i] = sum[i - 1] + dp[i];
		sum[i] %= mod;
	}
	// 出力
	cout << dp[N + 1] << endl;
	return 0;
}