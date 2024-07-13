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

int main() {
    // 入力
    cin >> N >> K;
    for (int i = 0; i < K; i++)
	{
		cin >> A[i] >> B[i];
		pasta[A[i]] = B[i];
	}
	// 初期条件の設定
	if (pasta.find(1) != pasta.end()) dp[1][pasta[1]][0] = 1;	// すでに初日のパスタが決まっている場合
	else
	{
		for (int i = 1; i <= 3; i++) dp[1][i][0] = 1;
	}
	// 動的計画法
	for (int k = 2; k <= N; k++)
	{
		for (int i = 1; i <= 3; i++)
		{
			// 前日と同じ場合
			dp[k][i][1] = dp[k-1][i][0] % mod;
			// 前日と違う場合
			dp[k][i][0] = 0;
			for (int l = 1; l <= 3; l++)
			{
				if (l != i) dp[k][i][0] = (dp[k][i][0] + dp[k - 1][l][0] + dp[k - 1][l][1]) % mod;
			}
		}
		// k日目の予定がすでに決まっていた場合
		if (pasta.find(k) != pasta.end())
		{
			for (int i = 1; i <= 3; i++)
			{
				if (i != pasta[k])
				{
					dp[k][i][0] = 0;
					dp[k][i][1] = 0;
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
