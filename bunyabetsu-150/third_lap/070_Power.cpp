#include <iostream>

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
	ll m, n;
	cin >> m >> n;
	cout << ft_power(m, n) << endl;
	return 0;
}