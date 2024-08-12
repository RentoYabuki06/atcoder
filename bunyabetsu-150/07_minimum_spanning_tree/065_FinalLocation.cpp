#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

class UnionFind
{
	public:
	vector<ll> par;
	vector<ll> siz;

	// N頂点のUnion-Findを作成
	void init(ll N)
	{
		par.assign(N, -1);
		siz.assign(N, 1);
	}

	// 頂点の根を返す（パス圧縮付き）
	ll root(ll x)
	{
		if (par[x] == -1) return x;
		else return par[x] = root(par[x]);
	}

	// 要素uとvを結合する
	void unite(ll u, ll v)
	{
		ll rootU = root(u);
		ll rootV = root(v);
		if (rootU == rootV) return;
		if (siz[rootU] > siz[rootV])
		{
			par[rootV] = rootU;
			siz[rootU] += siz[rootV];
		}
		else
		{
			par[rootU] = rootV;
			siz[rootV] += siz[rootU];
		}
	}

	// uとvが同じグループかを判定する
	bool same(ll u, ll v)
	{
		return root(u) == root(v);
	}
};

int main()
{
	ll V, E, K;
	cin >> V >> E >> K;
	vector<ll> s(E), t(E), w(E);
	vector<pair<ll, ll> > EdgeList;
	if (V == K)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < E; i++)
	{
		cin >> s[i] >> t[i] >> w[i];
		s[i]--; t[i]--;
		EdgeList.push_back(make_pair(w[i], i));
	}

	// 通行料金が安い順にソート
	sort(EdgeList.begin(), EdgeList.end());

	UnionFind UF;
	UF.init(V);
	ll ans = 0;
	ll groups = V;

	for (int i = 0; i < EdgeList.size(); i++)
	{
		ll idx = EdgeList[i].second;
		if (!UF.same(s[idx], t[idx]))
		{
			UF.unite(s[idx], t[idx]);
			ans += w[idx];
			groups--;
		}
		// K個の都市に分かれた時点で終了
		if (groups == K) break;
	}

	cout << ans << endl;
	return 0;
}
