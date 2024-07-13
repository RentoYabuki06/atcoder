#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll N, M;
ll D[1009];
ll C[1009];
ll dp[1009][1009];
const ll INF = 1e18;

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> D[i];
	for (int i = 1; i <= M; i++) cin >> C[i];
	// dp[i][j] i日目までにjに到達するための最小疲労を記録
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= N; j++) dp[i][j] = INF;
	}

	dp[0][0] = 0;
	// i日目までに到達できる場所を探索
	for (int i = 1; i <= M; i++)
	{
		// jに到達できる
		for (int j = 0; j <= N; j++)
		{
			// その日休む場合
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			// その日移動する場合
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + C[i] * D[j]);
		}
	}
	ll ans = INF;
	for (int i = 1; i <= M; i++) ans = min(ans, dp[i][N]);
	cout << ans << endl;
	return 0;
}
