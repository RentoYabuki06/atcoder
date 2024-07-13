#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll N, K;
ll A[109];
ll B[109];
ll dp[109][9][9];
unordered_map<ll, ll> pasta;
const ll mod = 10000;

int main()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A[i] >> B[i];
		pasta[A[i]] = B[i];
	} 
	// dp[i日目][パスタの種類j][前日に同じパスタか？k]
	if (pasta.find(1) != pasta.end()) dp[1][pasta[1]][0] = 1;
	else
	{
		for(int j = 1; j <= 3; j++) dp[1][j][0] = 1;
	}
	// 動的計画法スタート
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 3; j++)	//	今日食べるパスタ3種類の候補
		{
			// 前日と同じ場合
			dp[i][j][1] = dp[i - 1][j][0] % mod;
			// 前日と違う場合
			dp[i][j][0] = 0;
			for(int l = 1; l <= 3; l++)	//	前日のパスタ
			{
				if (l != j) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][l][0] + dp[i - 1][l][1]) % mod;
			}
		}
		// i日目の予定がすでに決まっていた場合
		if (pasta.find(i) != pasta.end())
		{
			for(int j = 1; j <= 3; j++)
			{
				if (j != pasta[i])
				{
					dp[i][j][0] = 0;
					dp[i][j][1] = 0;
				}
			}
		}
	}
	// 出力
	ll ans = 0;
	for (int i = 1; i <= 3; i++) ans = (ans + dp[N][i][0] + dp[N][i][1]) % mod;
	cout << ans << endl;
    return 0;
}