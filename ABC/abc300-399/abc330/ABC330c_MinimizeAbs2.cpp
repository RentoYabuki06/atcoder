#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	ll D;
	cin >> D;
	ll ans = 1e18;
	for (ll i = 0; i*i <= D; i++)
	{
		ll y_diff = D - i * i;
		ll y = sqrt(y_diff);
		for (ll j = 0; j <= 1; j++)
		{
			ll y_tmp = y + j;
			ll diff = abs(y_diff - y_tmp * y_tmp);
			ans = min(ans, diff);
		}
	}
	cout << ans << endl;
	return 0;
}