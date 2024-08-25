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
vector<ll> A(1000009);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll count = 0;
	while (1)
	{
		sort(A.begin(), A.begin() + N);
		reverse(A.begin(), A.begin() + N);
		if (A[1] == 0) break;
		A[0]--;
		A[1]--;
		count++;
	}
	cout << count << endl;
	return 0;
}