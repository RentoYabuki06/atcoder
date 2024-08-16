#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> Graph;
ll ans = 0;

pair<ll, ll> ft_dfs(ll current_node, ll cumulative_distance = 0, ll parent_node = -1)
{
    pair<ll, ll> result = make_pair(cumulative_distance, current_node);
    for (int i = 0; i < Graph[current_node].size(); i++)
    {
        ll next_node = Graph[current_node][i].first;
        ll edge_cost = Graph[current_node][i].second;
        // 親ノードに戻る場合はスキップ
        if (next_node == parent_node) continue;
        result = max(result, ft_dfs(next_node, cumulative_distance + edge_cost, current_node));
    }
    return result;
}

int main()
{
    ll N;
    cin >> N;
    Graph.resize(N);
    for (int i = 0; i < N - 1; i++)
    {
        ll A, B, C;
        cin >> A >> B >> C;
        A--; B--; // ノード番号を0から始める
        Graph[A].push_back(make_pair(B, C));
        Graph[B].push_back(make_pair(A, C));
        ans += C * 2;
    }
    // 木の片側の端を求める
    pair<ll, ll> dfs_first = ft_dfs(0);
    ll farthest_node = dfs_first.second;
    // 逆側の端までの距離を求める
    pair<ll, ll> dfs_second = ft_dfs(farthest_node);
    ll max_distance = dfs_second.first; // ここで累積距離を取得
    // 最長の片道分だけ答えから引く
    ans -= max_distance;
    cout << ans << endl;
    return 0;
}
