#include <iostream>

using namespace std;

unsigned long long ft_power(unsigned long long a, unsigned long long b, unsigned long long m)
{
	unsigned long long ans = 1;
	a %= m;
	while (b > 0)
	{
		if (b & 1)
			ans = (ans * a) % m;
		b >>= 1;
		a = (a * a) % m;
	}
	return ans ;
}

unsigned long long ft_division(unsigned long long a, unsigned long long b, unsigned long long m)
{
	return (a * ft_power(b , m - 2, m)) % m;
}


int main()
{
	unsigned long long m = 1000000007;
	unsigned long long n;
	unsigned long long r;
	cin >> n >> r;

	unsigned long long ans = 1;
	for (int i = 1; i <= r; i++)
	{
		ans = (ans * ft_division(n - i + 1, r - i + 1, m)) % m;
	}
	
	cout << ans << endl;
	return 0;
}