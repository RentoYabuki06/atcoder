#include <iostream>
#include <algorithm>

using namespace std;

int N, P[2009], A[2009], dp[2009][2009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> P[i] >> A[i];
	
	//dpスタート位置は一番端から端まで生き残っているところ
	dp[1][N] = 0;
	for (int len = N - 2; len >= 0; len--)
	{
		for (int l = 1; l <= N - len; l++)
		{
			int r = l + len;
			int score_left = 0;
			int score_right = 0;
			if (P[l - 1] <= r && P[l - 1] >= l) score_left = A[l - 1];
			if (P[r + 1] <= r && P[r + 1] >= l) score_right = A[r + 1];
			if (l == 1)
			{
				dp[l][r] = dp[l][r + 1] + score_right;
			}
			else if (r == N)
			{
				dp[l][r] = dp[l - 1][r] + score_left;
			}
			else
			{
				dp[l][r] = max(dp[l][r + 1] + score_right, dp[l - 1][r] + score_left);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, dp[i][i]);
	cout << ans << endl;
	return 0;
}