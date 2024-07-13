#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	ll N;
	cin >> N;
	vector<ll> dp(N+1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[N] << endl;
	return 0;
}