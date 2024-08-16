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

ll N, M;
vector<vector<ll>> dp;

int main()
{
	cin >> N >> M;
	vector<ll> A(N);
	ll total = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		total += A[i];
	}
	sort(A.begin(), A.end());
	total += A[0];
	int i = 0;
	while (i < N - 1)
	{
		if (total >= M) break;
		total += (A[i + 1] - A[i]) * (i + 1);
		i++;
	}
	if (i == N - 1 && total < M)
	{
		cout << "infinite" << endl;
		return 0;
	}
	if (i != 0) i--;
	ll ans = A[i+1];
	while (total < M)
	{
		total -= i + 1;
		ans -=	1;
	}
	cout << ans << endl;
	return 0;
}