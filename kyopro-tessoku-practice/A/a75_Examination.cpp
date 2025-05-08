#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int T[109];
int D[109];
int dp[109][1449];
vector<pair<int, int>> problems;

int main()
{
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> D[i];
		problems.push_back(make_pair(D[i], T[i]));
	}
	sort(problems.begin(), problems.end());
	for (int i = 1; i <= N; i++)
	{
		D[i] = problems[i - 1].first;
		T[i] = problems[i - 1].second;
	}
	// 配列の初期化
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 1440; j++) dp[i][j] = -1;
	}
	// 動的計画法
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 1440; j++)
		{
			if (j < T[i] || j > D[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - T[i]] + 1);
		}
	}
	// 答えを出力
	int ans = 0;
	for (int j = 0; j <= 1440; j++) ans = max(ans, dp[N][j]);
	cout << ans << endl;
	return 0;
}