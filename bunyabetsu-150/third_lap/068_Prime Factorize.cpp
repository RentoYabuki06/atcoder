#include <iostream>
#include <cmath>

using namespace std;

void ft_prime_factorize(int N)
{
	int tmp = N;
	for (int i = 2; i < sqrt(N); i++)
	{
		if (tmp % i == 0)
		{
			cout << " " << i;
			tmp /= i;
			i--;
		}
	}
	cout << endl;
	return ;
}

int main()
{
	int N;
	cin >> N;
	cout << N << " ";
	ft_prime_factorize(N);
	return 0;
}