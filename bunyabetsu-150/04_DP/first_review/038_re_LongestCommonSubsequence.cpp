#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

void	ft_lcs(string a, string b)
{
	ll len_a = a.size();
	ll len_b = b.size();
	vector<vector<ll>> dp(len_a +1, vector<ll>(len_b + 1, 0));
	for(int i = 0; i <= len_a; i++)
	{
		for(int j = 0; j <= len_b; j++)
		{
			if (i > 0 && j > 0 && a[i - 1] == b[j - 1])
				dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
			else if (i > 0 && j > 0)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			else if (i > 0)
				dp[i][j] = dp[i - 1][j];
			else if (j > 0)
				dp[i][j] = dp[i][j - 1];
		}
	}
	cout << dp[len_a][len_b] << endl;
}

int main()
{
	ll N;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a >> b;
		ft_lcs(a,b);
	}
	return 0;
}