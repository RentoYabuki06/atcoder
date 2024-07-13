#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll N, M;
vector<ll> C;
vector<ll> X;
const ll INF = 1e18;

ll ft_round255(ll num) {
    if (num > 255) num = 255;
    if (num < 0) num = 0;
    return num;
}

void ft_solve(ll N, ll M, const vector<ll>& C, const vector<ll>& X) {
    vector<vector<ll>> dp(N + 1, vector<ll>(256, INF)); // i番目の入力信号まででの最小二乗和、jはその時のyiの値
    dp[0][128] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 256; j++) {
            for (int k = 0; k < M; k++) {
                ll nex = ft_round255(j + C[k]);
                dp[i][nex] = min(dp[i][nex], dp[i - 1][j] + (ll)pow(nex - X[i - 1], 2));
            }
        }
    }
    ll ans = INF;
    for (int j = 0; j < 256; j++) ans = min(ans, dp[N][j]);
    cout << ans << endl;
}

int main() {
    // 入力
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        C.resize(M);
        X.resize(N);
        for (int i = 0; i < M; i++) cin >> C[i];
        for (int i = 0; i < N; i++) cin >> X[i];

        ft_solve(N, M, C, X);
    }
    return 0;
}
