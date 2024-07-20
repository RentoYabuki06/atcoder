// 連鎖行列積問題を詳しく解説してるqiita
// https://qiita.com/ikamirin/items/5ddbe04cb4d4ce6ed6af#%E8%A7%A3%E3%81%8D%E6%96%B9

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll N;
ll R[109];
ll C[109];
vector<ll> X;
const ll INF = 1e18;

int main() {
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i];
        if (i == 0) X.push_back(R[i]);
        X.push_back(C[i]);
    }

    // 区切り単位len, (L, R)
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    
    for (int len = 2; len <= N; len++) {
        for (int L = 1; L <= N - len + 1; L++) {
            int R = len + L - 1;
            dp[L][R] = INF;
            // 分割する場所をL~R-1までで選択
            for (int l = L; l < R; l++) {
                // (AB)(C)の計算量＝(AB)の計算量＋(C)の計算量＋(AB)の行数×(AB)の列数×(C)の列数
                ll tmp = dp[L][l] + dp[l + 1][R] + X[L - 1] * X[l] * X[R];
                dp[L][R] = min(dp[L][R], tmp);
            }
        }
    }
    cout << dp[1][N] << endl;

    return 0;
}
