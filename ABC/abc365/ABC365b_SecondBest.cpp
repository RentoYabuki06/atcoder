#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

ll N;
ll A[1000009];
vector<pair<ll, ll>> dp;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		dp.push_back({A[i], i});
	}
	sort(dp.begin(), dp.end());
	cout << dp[N - 2].second + 1 << endl;
	return 0;
}