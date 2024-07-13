#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, W;
ll Val[1009];
ll Weight_[1009];
ll dp[109][100009];

int main()
{
	// 入力
	cin >> N >> W;
	for(int i = 1; i <= N; i++) cin >> Val[i] >> Weight_[i];
	// ナップザックdp
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			for (int k = 1; k * Weight_[i] <= W; k++)
			{
				if (j < k * Weight_[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = max(dp[i-1][j], dp[i - 1][j - k * Weight_[i]] + k * Val[i]);
				}
			}
		}
	}
	// 出力
	ll ans = 0;
	for (int j = 0; j <= W; j++) ans = max(ans, dp[N][j]);
	cout << ans << endl;
	return 0;
}