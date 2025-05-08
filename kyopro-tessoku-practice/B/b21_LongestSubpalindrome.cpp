#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    string S;
    
    cin >> N >> S;

    // dpテーブルの定義と初期化
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 1文字からなる回文は必ず作れる
    for (int i = 0; i < N; i++) 
        dp[i][i] = 1;

    // DPテーブルの更新
    for (int len = 2; len <= N; len++) //文字数が2文字からmaxのN文字まで増やす
    {
        for (int l = 0; l + len - 1 <= N - 1; l++) //左の文字を一つずつずらしていく
        {
            int r = l + len - 1;
            // もし左右の端の文字が一致した場合
            if (S[r] == S[l])
            {
                if (len == 2)
                {
					//文字列が2文字の時は必ず2文字の回文
                    dp[l][r] = 2;
                }
                else 
                {
					//dp[l][r]の方がdp[l + 1][r - 1]よりもに文字多い→必ず先に計算している
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                }
            }
            // 一致しなかった場合は、どちらかの文字を取り除く
            else
            {
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }
    // 最大の回文長は一番文字が長い時
    cout << dp[0][N - 1] << endl;
    return 0;
}
