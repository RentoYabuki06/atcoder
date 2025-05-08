#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int S_len, T_len, dp[2009][2009];
string S, T;

int main()
{
	cin >> S >> T;
	S_len = S.size();
	T_len = T.size();

	dp[0][0] = 0;
	for (int i = 0; i <= S_len; i++)
	{
		for (int j = 0; j <= T_len; j++)
		{
			if (i > 0 && j > 0 && S[i - 1] == T[j - 1])
			{
				dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + 1});
			}
			else if (i > 0 && j > 0)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			else if (i > 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (j > 0)
			{
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	cout << dp[S_len][T_len] << endl;
	return 0;
}