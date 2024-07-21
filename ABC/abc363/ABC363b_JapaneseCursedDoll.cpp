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

ll N, T, P;
ll L[1000009];
string S;
vector<vector<ll>> dp;

int main()
{
	cin >> N >> T >> P;
	vector<ll> tmp;
	for (int i = 1; i <= N; i++)
	{
		cin >> L[i];
		tmp.push_back(L[i]);
	}
	sort(tmp.begin(), tmp.end());
	if (T - tmp[N - P] < 0) cout << 0 << endl;
	else cout << T - tmp[N - P] << endl;
	return 0;
}