#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll ft_repeat_squring(ll x, ll y, ll mod)
{
	ll ret = 1;
	while (y > 0)
	{
		if (y % 2 == 1) ret = (ret * x) % mod;
		x = (x * x) % mod;
		y /=  2;
	}
	return ret;
}

int main()
{
	ll M, N;
	cin >> M >> N;
	ll result = ft_repeat_squring(M, N, MOD);
	cout << result << endl;
	return 0;
}