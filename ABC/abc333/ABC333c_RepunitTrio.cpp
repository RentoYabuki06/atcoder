#include <iostream>

using namespace std;

int N;
long long dp[19];

int main()
{
	cin >> N;
	dp[1] = 1;
	for (int i = 2; i < 18; i++) dp[i] = 10 * dp[i - 1] + 1;
	int i = 1;
	int j = 1;
	int k = 1;
	for (int l = 2; l <= N; l++)
	{
		if (i == j && j == k)
		{
			i = 1;
			j = 1;
			k++;
		}
		else if (i < j) i++;
		else
		{
			j++;
			i = 1;
		}
	}
	long long ans = dp[i] + dp[j] + dp[k];
	cout << ans << endl;
	return 0;
}