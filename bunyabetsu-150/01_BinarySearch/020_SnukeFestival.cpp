#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
	// 入力
	ll N;
	cin >> N;
	vector<ll> A(N+1);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<ll> B(N+1);
	for (int i = 0; i < N; i++) cin >> B[i];
	vector<ll> C(N+1);
	for (int i = 0; i < N; i++) cin >> C[i];
	// ソート
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	// 解を求める
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		ll top_num = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
		ll bottom_num = N - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
		ans += top_num * bottom_num;
	}
	cout << ans << endl;
	return 0;
}