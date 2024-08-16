#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll N;
ll A[89];
const ll mod = 998244353;

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    // dp[i][len][diff] : 項数len, 項差diffの等差数列がi番目の要素を終点とする部分列の数
    vector<vector<unordered_map<ll, ll>>> dp(N, vector<unordered_map<ll, ll>>(N + 1));
    // resultで各項差の等差数列の数を格納
    vector<ll> result(N, 0);
    // 全ての要素のペアに対してdiffを計算し、項数lenの等差数列の数を更新
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ll diff = A[i] - A[j];
            // 項数3以上のdpの更新
            for (int len = 3; len <= N; ++len) dp[i][len][diff] = (dp[i][len][diff] + dp[j][len - 1][diff]) % mod;
            // 項数2の要素はどの要素のペアでも1つ存在する
            dp[i][2][diff] = (dp[i][2][diff] + 1) % mod;
        }
    }
    // 結果を集計
    for (int i = 0; i < N; ++i)
    {
        for (int len = 1; len <= N; ++len)
        {
            for (auto& p : dp[i][len]) result[len - 1] = (result[len - 1] + p.second) % mod;
        }
    }
    // 長さ1の部分列は全て等差数列
    for (int i = 0; i < N; ++i) result[0] = (result[0] + 1) % mod;
    // 各長さkの等差数列の数を空白区切りで出力
    for (int k = 0; k < N; k++)
    {
        if (k > 0) cout << " ";
        cout << result[k];
    }
    cout << endl;

    return 0;
}
