#include <iostream>

using namespace std;

const int INF = 1000000007;

int ft_power(int m, int n, int mod = INF)
{
	int ret = 1;
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
	int m, n;
	cin >> m >> n;
	cout << ft_power(m, n) << endl;
	return 0;
}