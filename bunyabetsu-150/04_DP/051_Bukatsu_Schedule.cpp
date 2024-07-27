#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
string S;
// i 日目に j 状態だった時の累積通り数
ll dp[1009][9];
const ll MOD = 10007;

int main()
{
    cin >> N >> S;
    // 初期値
    for (int j = 0; j < 8; j++)
    {
        dp[0][j] = 0;
    }
    dp[0][1] = 1; // 最初の日はJが必須

    // bitDP
    for (int i = 1; i <= N; i++)
    {
        ll tantou = 0;
        if (S[i-1] == 'J') tantou = 0;
        else if (S[i-1] == 'O') tantou = 1;
        else if (S[i-1] == 'I') tantou = 2;
        
        for (int j = 0; j < 8; j++) // 当日の参加状況
        {
            // 必須参加者がいなければcontinue
            if (!(j & (1 << tantou))) continue;
            for (int k = 0; k < 8; k++) // 前日の参加状況
            {
                // 前日に参加したメンバーが1人もいなければcontinue
                if (!(k & j)) continue;
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    // 出力
    ll ans = 0;
    for (int j = 0; j < 8; j++)
    {
        ans = (ans + dp[N][j]) % MOD;
    }
    cout << ans << endl;
    return 0;
}
