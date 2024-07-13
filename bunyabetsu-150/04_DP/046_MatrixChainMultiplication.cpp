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

    // 区切り単位i, 区切り始めj
    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N - i + 1; j++) {
            int k = i + j - 1;
            dp[j][k] = INF;
            for (int l = j; l < k; l++) {
                ll tmp = dp[j][l] + dp[l + 1][k] + X[j - 1] * X[l] * X[k];
                dp[j][k] = min(dp[j][k], tmp);
            }
        }
    }
    cout << dp[1][N] << endl;

    return 0;
}
