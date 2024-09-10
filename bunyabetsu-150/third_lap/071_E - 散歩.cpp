#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll INF = 1000000007;

ll ft_power(ll m, ll n)
{
	ll ret = 1;
	while (n > 0)
	{
		if (n % 2 == 1) ret = (ret * m) % INF;
		m = (m * m) % INF;
		n /= 2;
	}
	return ret;
}

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> A(N);
	vector<ll> C(Q);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < Q; i++) cin >> C[i];
	// 累積和を計算
	vector<ll> cur(N, 0);
	for (int i = 1; i < N; i++) cur[i] = (cur[i - 1] + ft_power(A[i - 1], A[i])) %INF;
	ll ans = 0;
	ll cur_city = 0;
	for (int i = 0; i < Q; i++)
	{
		ll nex_city = C[i] - 1;
		ll dist = 0;
		if (nex_city > cur_city)
			dist = (cur[nex_city] - cur[cur_city] + INF) % INF;
		else 
			dist = (cur[cur_city] - cur[nex_city] + INF) % INF;
		ans = (ans + dist) % INF;
		cur_city = nex_city;
	}
	// スタート地点に帰ってくる
	ans = (ans + cur[cur_city]) % INF;
	cout << ans << endl;
	return 0;
}