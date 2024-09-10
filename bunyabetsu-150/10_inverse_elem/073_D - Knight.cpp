#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

// モジュロMODにおける逆元を計算する関数（拡張ユークリッド法）
ll ft_modinv(ll a, ll mod = MOD) {
    ll b = mod;
    ll ans = 1;
    ll tmp = 0;
    while(b) {
        ll t = a / b;
        a -= t * b; swap(a,b);
        ans -= t * tmp; swap(ans, tmp);
    }
    ans = (ans + mod) % mod;
    return ans;
}

// n! / (n-k)! を計算する関数
ll ft_factorial(ll num, ll time, ll mod = MOD) {
    ll ret = 1;
    for (ll i = 0; i < time; ++i) {
        ret = (ret * (num - i)) % mod;
    }
    return ret;
}

// コンビネーション (nCk) を計算する関数
ll ft_combination(ll n, ll k, ll mod = MOD) {
    if (n - k < k) k = n - k;
    ll numerator = ft_factorial(n, k, mod);
    ll denominator = ft_factorial(k, k, mod);
    return numerator * ft_modinv(denominator, mod) % mod;
}

int main() {
    ll W, H;
    cin >> W >> H;
	ll num_x = 0;
	ll num_y = 0;
	while (W > 0 && H > 0)
	{
		if (W > H)
		{
			num_x++;
			W -= 2;
			H -= 1;
		}
		else
		{
			num_y++;
			W -= 1;
			H -= 2;
		}
	}
	if (W == 0 && H == 0)
	{
		if (num_x > 0 && num_y > 0) cout << ft_combination(num_x + num_y, num_x)  << endl;
		else cout << 1 << endl;
	}
	else cout << 0 << endl;
    return 0;
}
