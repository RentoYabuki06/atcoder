#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

ll N;
ll A[1000009];

int main()
{
	cin >> N;
	vector<pair<ll, ll>> enemy(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	ll T = 0;
	ll num = 0;
	while (num < N)
	{
		ll tmp = A[num] / 5;
		A[num] = A[num] % 5;
		T += tmp * 3;
		while (A[num] > 0)
		{
			T++;
			if (T % 3 == 0)
			{
				A[num] -= 3;
			}
			else
			{
				A[num]--;
			}
		}
		num++;
	}
	cout << T << endl;
	return 0;
	
}