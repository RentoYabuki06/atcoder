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
		par.assign(N + 1, -1);
		siz.assign(N + 1, 1);
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
	ll N, M;
	cin >> N >> M;
	vector<pair<ll, ll>> edges(M);
	for (int i = 0; i < M; i++)
	{
		cin >> edges[i].first >> edges[i].second;
	}

	ll ans = 0;
	for (int j = 0; j < M; j++)
	{
		UnionFind UF;
		UF.init(N);
		for (int i = 0; i < M; i++)
		{
			if (i != j) UF.unite(edges[i].first, edges[i].second);
		}

		// 全ての頂点が連結されているかを確認
		bool isConnected = true;
		for (int i = 1; i < N; i++)
		{
			if (!UF.same(i, i + 1))
			{
				isConnected = false;
				break;
			}
		}

		if (!isConnected) ans++;
	}

	cout << ans << endl;
	return 0;
}
