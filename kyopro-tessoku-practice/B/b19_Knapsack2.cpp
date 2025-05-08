#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, weight[109], value[109];
long long W;

int main()
{
	cin >> N >> W;
	int total_value = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i] >> value[i];
		total_value += value[i];
	}
	vector<long long> dp(total_value + 1, 1000000000000000000);
	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = total_value - value[i]; j >= 0; j--)
		{
			dp[j + value[i]] = min(dp[j + value[i]], dp[j] + weight[i]); 
		}
	}
	int ans = 0;
	for (int i = 0; i <= total_value; i++)
	{
		if (dp[i] <= W)
			ans = max(ans, i);
	}
	cout << ans << endl;
	return 0;
}
