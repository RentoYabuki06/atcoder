#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 100009;

bool 	ft_judge_prime(int N)
{
	if (N == 1) return false;
	if (N == 2) return true;
	if (N % 2 == 0) return false;
	int tmp = N;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (tmp % i == 0) return false;
	}
	return true;
}

int main()
{
	int Q;
	cin >> Q;
	int cur[INF];
	cur[0] = 0;
	for (int i = 1; i < INF; i++)
	{
		cur[i] = cur[i - 1];
		if (i % 2 == 0) continue;
		if (ft_judge_prime(i) && ft_judge_prime((i + 1) / 2)) cur[i]++;
	}
	for (int i = 1; i <= Q; i++)
	{
		int l, r;
		cin >> l >> r;
		cout << cur[r] - cur[l-1] << endl;
	}
	return 0;
}
