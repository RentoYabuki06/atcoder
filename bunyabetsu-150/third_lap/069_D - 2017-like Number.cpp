#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 100009;

bool ft_prime_check(int N)
{
	if (N == 1) return false;
	if (N == 2) return true;
	int tmp = N;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (tmp % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	vector<int> cur(INF, 0);
	cur[0] = 0;
	for (int i = 1; i < INF; i++)
	{
		cur[i] = cur[i - 1];
		if (i % 2 == 0) continue;
		if (ft_prime_check(i) && ft_prime_check((i + 1) / 2)) cur[i]++;
	}
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << cur[r] - cur[l - 1] << endl;
	}
	return 0;
}