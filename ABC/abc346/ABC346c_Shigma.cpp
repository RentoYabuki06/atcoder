#include <iostream>
#include <set>

using namespace std;

long long N, K;

int main()
{
	cin >> N >> K;
	set<int> A;
	for (int i = 1; i <= N; i++)
	{
		long long tmp;
		cin >> tmp;
		if (tmp <= K)
			A.insert(tmp);
	}
	long long ans = K * (K + 1) / 2;
	for(int i: A) ans -= i;
	cout << ans << endl;
	return 0;
}
