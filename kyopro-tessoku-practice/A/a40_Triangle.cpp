#include <iostream>

using namespace std;

long long ft_choose(long long n)
{
	return  (n * (n - 1) * (n - 2)) / 6;
}

int main()
{
	long long N, A[109];
	cin >> N;
	for (int i = 1; i <= 100; i++) A[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		A[tmp]++;
	}
	long long ans = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (A[i] >= 3)
			ans += ft_choose(A[i]);
	}
	cout << ans << endl;
	return 0;
}