#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100009], B[100009];

long long dp[100009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N - 1; i++) cin >> A[i];
	for (int i = 1; i <= N - 1; i++) cin >> B[i];
	for (int i = 2; i <= N; i++) dp[i] = -1000000000;
	dp[1] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		dp[A[i]] = max(dp[i] + 100, dp[A[i]]);
		dp[B[i]] = max(dp[i] + 150, dp[B[i]]);
	}
	cout << dp[N] << endl;
	return 0;
}