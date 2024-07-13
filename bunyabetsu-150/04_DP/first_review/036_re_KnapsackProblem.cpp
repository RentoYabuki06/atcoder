#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ll N, W;
	cin >> N >> W;
	vector<ll> val(N);
	vector<ll> wei(N);
	for (int i = 0; i < N; i++) cin >> val[i] >> wei[i];
	vector<vector<ll>> dp (N + 1, vector<ll>(W+1, 0));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			for (int k = 0; k * wei[i] <= W; k++)
			{
				if (k * wei[i] > j) dp[i+1][j] = dp[i][j];
				else dp[i+1][j] = max(dp[i][j], dp[i][j - wei[i] * k] + val[i] * k);
				
			}
		}
	}
	// 出力
	ll ans = 0;
	for (int j = 0; j <= W; j++) ans = max(ans, dp[N][j]);
	cout << ans << endl;
	return 0;
}