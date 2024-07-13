#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll N;
string S[9];
const ll INF = 1e18;

int main()
{
	// 入力
	cin >> N;
	vector<vector<char>> S(5, vector<char>(N+1));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < N; j++) cin >> S[i][j];
	}
	// それぞれの列でどの色が何回出てくるかをカウント
	vector<vector<ll>> S_count(4, vector<ll>(N+1,0));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (S[i][j] == 'R') S_count[0][j]++;
			if (S[i][j] == 'B') S_count[1][j]++;
			if (S[i][j] == 'W') S_count[2][j]++;
			if (S[i][j] == '#') S_count[3][j]++;
		}
	}
	// それぞれの列を指定した際に塗り替えるマス目の数
	vector<vector<ll>> S_repaint(3, vector<ll>(N+1,0));
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			S_repaint[k][j] = 5 - S_count[k][j];
		}
	}
	// 動的計画法
	vector<vector<ll>> dp(3, vector<ll>(N+1,INF));
	dp[0][0] = S_repaint[0][0];
	dp[1][0] = S_repaint[1][0];;
	dp[2][0] = S_repaint[2][0];;
	for (int j = 1; j < N; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 3; l++)	//一つ前の色
			{
				if (k == l) continue;
				dp[k][j] = min(dp[k][j], dp[l][j - 1] + S_repaint[k][j]);
			}
		}
	}
	// 出力
	ll ans = INF;
	ans = min(ans, dp[0][N-1]);
	ans = min(ans, dp[1][N-1]);
	ans = min(ans, dp[2][N-1]);
	cout << ans << endl;
	return 0;
}
