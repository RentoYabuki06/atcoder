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

void solve() {
    for (int len = 1; len <= N; len++) {
        for (int L = 1; L <= 2 * N; L++) {
            int R = L + len - 1;
			if (R > 2 * N) continue;
            if ((N - len) % 2 == 1) { // IOIちゃんのターン
				if (L == R) dp[L][R] = 0;
                else if (A[L] > A[R]) dp[L][R] = dp[L+1][R];
				else dp[L][R] = dp[L][R-1];
            } else { // JOIちゃんのターン
				if (L == R) dp[L][R] = A[L];
                else dp[L][R] = max(dp[L+1][R] + A[L], dp[L][R-1] + A[R]);
            }
        }
    }
}

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) A[i + N] =  A[i];

    // dp配列を初期化
    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
			dp[i][j] = 0;
        }
    }

    // 動的計画法で解く
    solve();

    // 出力
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i][i+N-1]);
    }
    cout << ans << endl;

    return 0;
}
