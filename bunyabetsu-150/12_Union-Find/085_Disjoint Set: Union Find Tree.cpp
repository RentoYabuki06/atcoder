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
		if (rootU == rootV) return ;
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
	ll N, Q;
	cin >> N >> Q;
	UnionFind UF;
	UF.init(N);
	for (int i = 0; i < Q; i++)
	{
		ll p, a, b;
		cin >> p >> a >> b;
		if (p == 0) UF.unite(a, b);
		else cout << UF.same(a, b) << endl;
	}
	return 0;
}
