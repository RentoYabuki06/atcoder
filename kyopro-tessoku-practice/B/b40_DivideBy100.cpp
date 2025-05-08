#include <iostream>

using namespace std;

long long ft_choose(long long n)
{
	return  (n * (n - 1)) / 2;
}

long long ft_combi(long long a, long long b)
{
	return a * b;
}

int main()
{
	int N;
	long long A[109];
	cin >> N;
	for (int i = 0; i < 100; i++) A[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		long long tmp;
		cin >> tmp;
		A[tmp % 100]++;
	}
	long long ans = 0;
	if (A[0] > 1)
		ans += ft_choose(A[0]);
	if (A[50] > 1)
		ans += ft_choose(A[50]);
	for (int i = 1; i < 50; i++)
	{
		ans += ft_combi(A[i], A[100 - i]);
	}
	cout << ans << endl;
	return 0;
}