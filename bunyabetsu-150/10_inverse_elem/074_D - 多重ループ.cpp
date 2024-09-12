#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll const MOD = 1000000007;
vector<ll> fact, inv_fact;

ll ft_modinv(ll a, ll mod = MOD)
{
	ll b = mod, u = 1, v = 0;
	while (b) {
		ll t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	return (u + mod) % mod;
}

void ft_precompute_factorials(int n, ll mod = MOD)
{
	fact.resize(n + 1);
	inv_fact.resize(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i-1] * i % mod;
	}
	inv_fact[n] = ft_modinv(fact[n], mod);
	for (int i = n - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
	}
}

ll ft_combination(ll n, ll k, ll mod = MOD)
{
	if (n < k) return 0;
	return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

int main()
{
	ll n, k;
	cin >> n >> k;
	ft_precompute_factorials(n + k - 1, MOD);

	ll ans = ft_combination(n + k - 1, k, MOD);
	cout << ans << endl;
	return 0;
}
