#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;
ll dp[1 << 16][16];
ll cnt[1 << 16][16];
const ll INF = 1e18;

struct Edge
{
    ll to;
    ll dist;
    ll time;
    Edge (ll to, ll dist, ll time) : to(to), dist(dist), time(time) {}
};

int main()
{
    cin >> N >> M;
    vector<Edge> Graph[16];
    for (int i = 0; i < M; i++)
    {
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        --s;
        --t;
        Graph[s].emplace_back(t, d, time);
        Graph[t].emplace_back(s, d, time);
    }

    // 配列の初期化
    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j] = INF;
            cnt[i][j] = 0;
        }
    }

    // 最初は都市0からスタート
    dp[1][0] = 0;
    cnt[1][0] = 1;

    // スタートのみから全都市制覇までbitDP
    for (int i = 1; i < (1 << N); i++)
    {
        // 最後の都市をjとする
        for (int j = 0; j < N; j++)
        {
            if (!(i & (1 << j))) continue;
            // 次に行く都市をkとする
            for (const auto& city : Graph[j])
            {
                ll nex = city.to;
                ll dist = city.dist;
                ll time = city.time;
                if (i & (1 << nex)) continue;
                if (dp[i][j] + dist > time) continue;
                if (dp[i | (1 << nex)][nex] > dp[i][j] + dist)
                {
                    dp[i | (1 << nex)][nex] = dp[i][j] + dist;
                    cnt[i | (1 << nex)][nex] = cnt[i][j];
                }
                // もし最短経路が複数ある場合は追加
                else if (dp[i | (1 << nex)][nex] == dp[i][j] + dist)
                {
                    cnt[i | (1 << nex)][nex] += cnt[i][j];
                }
            }
        }
    }

    // 出力
    ll ans = INF;
    ll count = 0;
    for (const auto& city : Graph[0])
    {
        ll k = city.to;
        ll dist = city.dist;
        if (dp[(1 << N) - 1][k] + dist <= city.time)
        {
            if (ans > dp[(1 << N) - 1][k] + dist)
            {
                ans = dp[(1 << N) - 1][k] + dist;
                count = cnt[(1 << N) - 1][k];
            }
            else if (ans == dp[(1 << N) - 1][k] + dist)
            {
                count += cnt[(1 << N) - 1][k];
            }
        }
    }

    if (ans == INF) cout << "IMPOSSIBLE" << endl;
    else cout << ans << " " << count << endl;
    return 0;
}
