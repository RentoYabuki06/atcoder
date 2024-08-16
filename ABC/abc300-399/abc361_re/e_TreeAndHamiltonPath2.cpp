#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

vector<vector<pair<ll, ll>>> Graph;

pair<ll, ll> ft_search_edge(ll c_node, ll cum_cost = 0, ll parent_node = -1)
{
	pair<ll, ll> tmp = make_pair(cum_cost, c_node);
	for (int i = 0; i < Graph[c_node].size(); i++)
	{
		ll nex = Graph[c_node][i].first;
		ll cost = Graph[c_node][i].second;
		if (nex == parent_node) continue;
		tmp = max(tmp, ft_search_edge(nex, cum_cost + cost, c_node));
	}
	return tmp;
}

int main()
{
	ll N;
	cin >> N;
	Graph.resize(N+1);
	ll ans = 0;
	for (int i = 0; i < N - 1; i++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		Graph[a].push_back(make_pair(b,c));
		Graph[b].push_back(make_pair(a,c));
		ans += c * 2;
	}
	pair<ll, ll> first_search = ft_search_edge(1);
	pair<ll, ll> second_search = ft_search_edge(first_search.second);
	cout << ans - second_search.first << endl;
	return 0;
}