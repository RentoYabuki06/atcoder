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

ll N, K;
ll R[1000009];
vector<ll> G[1000009];

bool ft_check(ll n)
{
	string s = to_string(n);
	for (int i = 0; i < N; i++)
	{
		if (s[i] > R[i]) return false;
		else if (s[i] < R[i]) return true;
	}
	return true;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> R[i];
	for (int i = pow(10, N); i < pow(10, N+1); i++)
	{
		if (ft_check(i)) cout << i << endl;
	}
	return 0;
}