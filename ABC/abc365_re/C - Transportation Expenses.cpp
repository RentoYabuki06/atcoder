#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ll N, M;
	cin >> N >> M;
	vector<ll> A(N);
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	if (sum <= M)
	{
		cout << "infinite" << endl;
		return 0;
	}
	sort(A.begin(), A.end());
	ll total = A[0] * N;
	ll max_x = A[0];
	if (total >= M)
	{
		while (total > M)
		{
			total -= N;
			max_x--;
		}
		cout << max_x << endl;
		return 0;
	}
	for (int i = 1; i < N; i++)
	{
		total += (A[i] - A[i - 1]) * (N - i);
		max_x = A[i];
		// cout << "this loop is" << i << "time : " << total << endl;
		if (total >= M)
		{
			while (total > M)
			{
				total -= (N - i);
				max_x--;
			}
			cout << max_x << endl;
			return 0;
		}
	}
	return 0;
}