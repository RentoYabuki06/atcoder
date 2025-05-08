#include <iostream>
#include <algorithm>

using namespace std;

long long N, W, w[109], v[109];

long long dp[109][100009];

int main()
{
	cin >> N >> W;
	for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
	for (int i = 0; i <= N; i++)
	{
		for (int i = 0; i <= W; i++) dp[N][W] = -1000000000000LL;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]]  + v[i]);
		}
	}
	long long ans = 0;
	for (int i = 0; i <= W; i++)
	{
		ans = max(ans, dp[N][i]);
	}
	cout << ans << endl;
	return 0;
}