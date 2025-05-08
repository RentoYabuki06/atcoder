#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int a[109];
	for (int i = 1; i <= K; i++) cin >> a[i];

	bool dp[100009];
	dp[0] == false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (i >= a[j] && dp[i - a[j]] == false)
			{
				dp[i] = true;
				break ;
			}
			dp[i] = false;
		}
	}
	// 結果の出力
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}