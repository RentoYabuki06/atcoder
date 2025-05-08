#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100009], B[100009];
long long dp[100009];

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];
	for (int i = 0; i <= N; i++) dp[i] = 100000000000;
	dp[1] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		dp[i + 1] = min(dp[i] + A[i + 1] , dp[i + 1]);
		dp[i + 2] = min(dp[i] + B[i + 2], dp[i + 2]);
	}
	cout << dp[N] << endl;
	return 0;
}