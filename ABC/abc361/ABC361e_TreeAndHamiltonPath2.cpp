#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> Graph;
ll ans = 0;

// 返り値は（距離, 現在のノード）
pair<ll, ll> ft_dfs(ll c_node, ll cum_dist = 0, ll parent_node = -1)
{
	pair<ll, ll> tmp = make_pair(cum_dist, c_node);
	for (int i = 0; i < Graph[c_node].size(); i++)
	{
		ll nex = Graph[c_node][i].first;
		ll cost = Graph[c_node][i].second;
		// 親まで来たら終了
		if (nex == parent_node) continue;
		tmp = max(tmp, ft_dfs(nex, cum_dist + cost, c_node));
	}
	return tmp;
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
		Graph[A].push_back(make_pair(B,C));
		Graph[B].push_back(make_pair(A,C));
		ans += C * 2;
	}
	// 木の片側の端を求める
	pair<ll, ll> dfs_first = ft_dfs(0);
	ll edge = dfs_first.second;
	// 逆側の端までの距離を求める
	pair<ll, ll> dfs_second = ft_dfs(edge);
	ll max_dist = dfs_second.second;
	// 最長の片道分だけ答えから引く
	ans -= max_dist;
	cout << ans << endl;
	return 0;
}