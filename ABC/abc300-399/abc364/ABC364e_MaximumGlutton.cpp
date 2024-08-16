#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;

ll N, X, Y;
const ll INF = 1e18;

int main()
{
	// 入力
    cin >> N >> X >> Y;
	vector<ll> A(N), B(N);
	for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
	// dp[i][j][k]: 料理iまでの中で、甘さの合計がkとなるようにj個の料理を選んだときの最小のしょっぱさ
	vector<vector<vector<ll>>> dp(N + 1, vector(N + 1, vector<ll>(X + 1, INF)));
	// 初期状態
	dp[0][0][0] = 0;
	// 動的計画法スタート
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			for (int k = 0; k <= X; k++)
			{
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				// i番目の料理をえらんでも甘さがXを超えない場合
				if (k + A[i] <= X)
				{
					dp[i + 1][j + 1][k + A[i]] = min(dp[i + 1][j + 1][k + A[i]], dp[i][j][k] + B[i]);
				}
			}
		}
	}
	// 出力
	for (int i = N; i >= 0; i--)
	{
		for (int j = 0; j <= X; j++)
		{
			if (dp[N][i][j] <= Y)
			{
				cout << min((ll)i + 1, N) << endl;
				return 0;
			}
		}
	}
    return 0;
}
