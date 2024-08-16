#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
vector<ll> dist_city(120009, 0);
vector<ll> cumulative_sum(120009, 0);

ll ft_repeat_squaring(ll x, ll y, ll mod)
{
    ll ret = 1;
    while (y > 0)
    {
        if (y % 2 == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        y /= 2;
    }
    return ret;
}

ll ft_dist(ll from, ll to)
{
	if (from < to) {
        return (cumulative_sum[to] - cumulative_sum[from] + MOD) % MOD;
    } else {
        return (cumulative_sum[from] - cumulative_sum[to] + MOD) % MOD;
    }
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> C(Q);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) cin >> C[i];
    for (int i = 1; i < N; i++) {
        dist_city[i] = ft_repeat_squaring(A[i - 1], A[i], MOD);
        cumulative_sum[i] = (cumulative_sum[i - 1] + dist_city[i]) % MOD;
    }
    
    ll result = 0;
    ll cur_city = 0;
    for (int i = 0; i < Q; i++)
    {
        ll nex_city = C[i] - 1;
        result = (result + ft_dist(cur_city, nex_city)) % MOD;
        cur_city = nex_city;
    }
	result = (result + ft_dist(0, cur_city)) % MOD;
    cout << result << endl;
    return 0;
}
