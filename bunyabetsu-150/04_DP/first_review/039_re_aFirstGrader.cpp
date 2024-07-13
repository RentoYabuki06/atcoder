#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> num (N);
    for (int i = 0; i < N; i++) cin >> num[i];
    vector<vector<ll>> dp(N, vector<ll> (21, 0));  // dp配列の範囲を修正
    dp[0][num[0]] = 1;  // 初期化条件を変更

    for (int i = 1; i < N - 1; i++) // N-1 までループ
    {
        for (int j = 0; j <= 20; j++) // 範囲を 0 から 20 に変更
        {
            if (j - num[i] >= 0) dp[i][j] += dp[i - 1][j - num[i]]; // += に変更
            if (j + num[i] <= 20) dp[i][j] += dp[i - 1][j + num[i]]; // += に変更
        }
    }
    cout << dp[N - 2][num[N - 1]] << endl; // インデックス修正
    return 0;
}
