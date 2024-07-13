#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll N;
ll A[109];
ll dp[109][21];

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // dp 配列の初期化
    dp[1][A[1]] = 1; // 最初の数の初期化

    // dp 計算
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i][j] > 0) {
                if (j + A[i + 1] <= 20) dp[i + 1][j + A[i + 1]] += dp[i][j];
                if (j - A[i + 1] >= 0) dp[i + 1][j - A[i + 1]] += dp[i][j];
            }
        }
    }

    // 出力
    cout << dp[N - 1][A[N]] << endl;
    return 0;
}
