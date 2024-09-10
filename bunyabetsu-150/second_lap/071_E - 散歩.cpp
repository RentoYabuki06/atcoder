#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll INF = 1000000007;

ll ft_power(ll m, ll n, ll mod = INF)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n % 2 == 1) ret = (ret * m) % mod;
        m = (m * m) % mod;
        n /= 2;
    }
    return ret;
}

int main()
{
    ll N, Q;
    cin >> N >> Q;  // NとQをまず読み込む

    vector<ll> A(N);
    vector<ll> C(Q);

    for (ll i = 0; i < N; i++) cin >> A[i];  // Aベクターを読み込む
    for (ll i = 0; i < Q; i++) cin >> C[i];  // Cベクターを読み込む

    vector<ll> cur(N);
    cur[0] = 0;
    for (ll i = 1; i < N; i++) cur[i] = (cur[i - 1] + ft_power(A[i - 1], A[i])) % INF;

    ll ans = 0;
	ll cur_city = 0;
    for (ll i = 0; i < Q; i++)
    {
		ll nex_city = C[i] - 1;
        if (cur[nex_city] > cur[cur_city]) ans = (ans + cur[nex_city] - cur[cur_city] + INF) % INF;
        else ans = (ans + cur[cur_city] - cur[nex_city] + INF) % INF;
		cur_city = nex_city;
    }
    ans = (ans + ft_power(0, cur_city)) % INF;
    cout << ans << endl;

    return 0;
}
