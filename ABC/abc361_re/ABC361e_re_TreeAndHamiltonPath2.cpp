#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> Graph;

// 端までの距離と端のノードを調べる関数
pair<ll, ll> ft_dist_to_edge(ll c_node, ll cum_dist = 0, ll parent_node = -1)
{
    pair<ll, ll> tmp = make_pair(cum_dist, c_node);
    for (int i = 0; i < Graph[c_node].size(); i++)
    {
        ll nex = Graph[c_node][i].first;
        ll cost = Graph[c_node][i].second;
        if (nex == parent_node) continue;
        tmp = max(tmp, ft_dist_to_edge(nex, cum_dist + cost, c_node));
    }
    return tmp;
}

int main()
{
    ll N;
    cin >> N;
    Graph.resize(N + 1); // ノード数に合わせてグラフのサイズを調整

    ll ans = 0;
    for (int i = 0; i < N - 1; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        Graph[a].push_back(make_pair(b, c));
        Graph[b].push_back(make_pair(a, c)); // 修正点
        ans += 2 * c;
    }

    pair<ll, ll> first_dfs = ft_dist_to_edge(1); // 根のノードを1に設定
    ll edge = first_dfs.second;
    pair<ll, ll> second_dfs = ft_dist_to_edge(edge);
    ans -= second_dfs.first;
    cout << ans << endl;

    return 0;
}
