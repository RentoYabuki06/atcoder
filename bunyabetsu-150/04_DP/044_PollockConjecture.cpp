#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

const ll INF = 1e18;

ll ft_cal(ll num)
{
	return num * (num + 1) * (num + 2) / 6;
}

void	ft_solve(ll num)
{
	// ポロック数
	vector<ll> pollock;
	vector<ll> pollock_odd;
	for (int i = 1; i < 200; i++)
	{
		ll tmp = ft_cal(i);
		pollock.push_back(tmp);
		if (tmp % 2 != 0) pollock_odd.push_back(tmp);
	}
	// 動的計画法
	vector<ll> dp(num + 1, INF);
	vector<ll> dp_odd(num + 1, INF);
	dp[0] = 0;
	dp_odd[0] = 0;
	for (int i = 0; i < pollock.size(); i++)
	{
		for (int j = pollock[i]; j <= num; j++)
		{
			dp[j] = min(dp[j], dp[j - pollock[i]] + 1);
		}
	}
	for (int i = 0; i < pollock_odd.size(); i++)
	{
		for (int j = pollock_odd[i]; j <= num; j++)
		{
			dp_odd[j] = min(dp_odd[j], dp_odd[j - pollock_odd[i]] + 1);
		}
	}
	cout << dp[num] << " " << dp_odd[num] << endl;
}

int main()
{
	while (1)
	{
		ll num;
		cin >> num;
		if (num == 0) break;
		ft_solve(num);
	}
	return 0;
}
