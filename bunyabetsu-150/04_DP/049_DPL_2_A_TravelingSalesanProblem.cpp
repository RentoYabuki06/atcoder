#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll V, E;
ll dp[34009][19];
const ll INF = 100000;
vector<pair<ll, ll>> Graph[19];

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        ll s, t, d;
        cin >> s >> t >> d;
        Graph[s].push_back(make_pair(t, d));
    }
    
    // 配列の初期化
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = INF;
        }
    }

    // 最初は都市0からスタート
    dp[1][0] = 0;

    // スタートのみから全都市制覇までbitDP
    for (int i = 1; i < (1 << V); i++)
    {
        // 最後の都市をjとする
        for (int j = 0; j < V; j++)
        {
            if (!(i & (1 << j))) continue;
            // 次に行く都市をkとする
            for (const auto& edge : Graph[j])
            {
                ll nex = edge.first;
                ll dist = edge.second;
                if (i & (1 << nex)) continue;
                dp[i | (1 << nex)][nex] = min(dp[i | (1 << nex)][nex], dp[i][j] + dist);
            }
        }
    }

    // 出力
    ll ans = INF;
    for (int k = 1; k < V; k++)
    {
        for (const auto& edge : Graph[k])
        {
            if (edge.first == 0)
            {
                ans = min(ans, dp[(1 << V) - 1][k] + edge.second);
            }
        }
    }

	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
    return 0;
}
