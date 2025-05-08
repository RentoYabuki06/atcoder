#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int A[2009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	int dp[2009][2009];
	// 最下層の数字を埋める
	for (int j = 1; j <= N; j++) dp[N][j] = A[j];
	//上に上に埋めていく
	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++) 
		{
			if (i % 2 == 1)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
			}
			else
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
			}
		}
	}
	cout << dp[1][1] << endl;
	return 0;
}