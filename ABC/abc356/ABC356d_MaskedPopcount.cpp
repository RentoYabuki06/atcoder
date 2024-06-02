#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

long long N, M;

int main()
{
	cin >> N >> M;
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		long long tmp = i & M;
		for (int j = 0; j < 60; j++)
		{
			if ((tmp >> j) & 1) ans++;
		}
		ans %= 998244353;
	}
	cout << ans << endl;
	return 0;
}