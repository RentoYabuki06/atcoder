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

int main()
{
	unsigned long long a, b;
	cin >> a >> b;
	cout << ft_power(a, b, 1000000007) << endl;
	return 0;
}