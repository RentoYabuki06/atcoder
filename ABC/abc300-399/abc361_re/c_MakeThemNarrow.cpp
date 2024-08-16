#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, K;

int main()
{
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
	ll remain = N - K;
	ll min_diff = A[remain - 1] - A[0];
	for (int i = 1; i <= K; i++)
	{
		ll tmp_diff = A[remain - 1 + i] - A[i];
		if (tmp_diff < min_diff) min_diff = tmp_diff;
	}
	cout << min_diff << endl;
    return 0;
}
