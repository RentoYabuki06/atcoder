#include <iostream>
#include <cmath>

using namespace std;

void ft_prime_factorize(int n)
{
	int n_tmp = n;
	for (int i = 2; i <= n / i; i++)
	{
		if (n_tmp % i == 0)
		{
			cout << " " << i;
			n_tmp /= i;
			i--;
		}
	}
	if (n_tmp > 1) cout << " " << n_tmp;
	return ;
}

int main()
{
	int N;
	cin >> N;
	cout << N << ":";
	ft_prime_factorize(N);
	cout << endl;
	return 0;
}