#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> coin(M);
	for (int i= 0; i < M; i++) cin >> coin[i];
	sort(coin.begin(), coin.end());
	reverse(coin.begin(), coin.end());
	vector<vector<ll>> dp (M + 1, vector<ll>(N + 1, 1e18));
	dp[0][0] = 0;
	for (int i= 0; i < M; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (coin[i] > j) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = min(dp[i][j], dp[i][j - coin[i]] + 1);
		}
	}
	cout << dp[M - 1][N] << endl;
	return 0 ;
}