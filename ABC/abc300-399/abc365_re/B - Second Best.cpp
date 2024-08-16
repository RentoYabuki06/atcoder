#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	cin >> N;
	vector<pair<ll, ll>> A;
	for (int i = 0; i < N; i++)
	{
		ll a;
		cin >> a;
		A.push_back({a, i});
	}
	sort(A.begin(), A.end());
	cout << A[N - 2].second + 1 << endl;
	return 0;
}