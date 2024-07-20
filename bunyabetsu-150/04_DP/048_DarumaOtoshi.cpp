#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll N;
ll W[309];

int main()
{
	while (1)
	{
		// 入力
		cin >> N;
		if (N == 0) return 0;
		for (int i = 0; i < N; i++) cin >> W[i];
		vector<vector<bool>> dp(N + 1, vector<bool>(N + 1, false));
		// 動的計画法
		for (int len = 1; len <= N; len++)
		{
			if (len % 2 == 1) continue;
			for (int L = 0; L + len - 1 < N; L++)
			{
				int R = L + len - 1;
				if (len == 2)
				{
					if (abs(W[L] - W[R]) <= 1) dp[L][R] = true;
				}
				else
				{
					if (dp[L + 2][R] && abs(W[L] - W[L + 1]) <= 1)
					{
						dp[L][R] = true;
					}
					else if (dp[L][R - 2] && abs(W[R - 1] - W[R]) <= 1)
					{
						dp[L][R] = true;
					}
					else if (dp[L + 1][R - 1] && abs(W[L] - W[R]) <= 1)
					{
						dp[L][R] = true;
					}
					else
					{
						for (int i = L + 1; i < R - 1; i++)
						{
							if (dp[L][i - 1] && dp[i + 2][R] && abs(W[i] - W[i + 1]) <= 1)
							{
								dp[L][R] = true;
								break;
							}
						}
					}
				}
			}
		}
		// 出力
		ll ans = 0;
		vector<bool> used(N + 1, false);
		for (int len = N; len > 0; len--)
		{
			if (len % 2 == 1) continue;
			for (int L = 0; L + len - 1 < N; L++)
			{
				int R = L + len - 1;
				if (R >= N) continue;
				if (dp[L][R])
				{
					bool flag = false;
					int tmp = L;
					while (tmp <= R)
					{
						if (used[tmp])
						{
							flag = true;
							break;
						}
						tmp++;
					}
					if (flag) continue;
					ans += len;
					for (int i = L; i <= R; i++) used[i] = true;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}