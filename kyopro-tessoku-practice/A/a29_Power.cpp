#include <iostream>

using namespace std;

long long ft_power(long long a, long long b, long long m)
{
	long long p = a;
	long long ans = 1;
	for (int i = 0; i <= 30; i++)
	{
		int wari = (1 << i);
		if ((b / wari) % 2 == 1)
		{
			ans = (ans * p) % m;
		}
		p = (p * p) % m;
	}
	return ans;
}

int main()
{
	int a, b;
	long long ans;
	cin >> a >> b;
	cout << ft_power(a, b, 1000000007) << endl;
	return 0;
}