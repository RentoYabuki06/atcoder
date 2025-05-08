#include <iostream>

using namespace std;

int N, K, A[100009];

bool	ft_check(long long x)
{
	long long sum = 0;
	for (int i = 1; i <= N; i++) sum += x / A[i];
	if (sum >= K) return true;
	return false;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	long long L = 1;
	long long R = 1000000000;
	while (L <= R)
	{
		long long mid = (R + L) / 2;
		if (ft_check(mid)) R = mid - 1;
		else L = mid + 1;
	}
	cout << L << endl;
	return 0;
}