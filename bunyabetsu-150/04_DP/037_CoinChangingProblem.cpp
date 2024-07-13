#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
vector<ll> coin;
vector<ll> dp;
const ll INF = 1e18;

int main()
{
    // 入力
    cin >> N >> M;
    coin.resize(M);
    for (int i = 0; i < M; i++) cin >> coin[i];
    
    // dp配列の初期化
    dp.resize(N + 1, INF);
    dp[0] = 0;

    // ナップザックdp
    for (int i = 0; i < M; i++)
    {
        for (int j = coin[i]; j <= N; j++)
        {
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
        }
    }

    // 出力
    if (dp[N] == INF) {
        cout << -1 << endl; // 解が存在しない場合
    } else {
        cout << dp[N] << endl;
    }
    return 0;
}
