#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll N;
ll A[4009];
ll dp[4009][4009];
const ll INF = 1e18;

ll ft_solve(ll L, ll R , ll turn)
{
	// IOIちゃんのターン
	if(turn % 2 == 0)
	{

	}
	// JOIちゃんのターン
	else 
	{

	}
}

int main() {
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) A[N+i] = A[i];
	// 最初の一つはN種類の中から選ぶ
	ll ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, ft_solve(i, N - 1 + i, 1));
	cout << ans << endl;
    return 0;
}