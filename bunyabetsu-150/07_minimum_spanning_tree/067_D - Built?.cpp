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
	ll N;
	cin >> N;
	vector<ll> X(N);
	vector<ll> Y(N);
	vector<pair<ll, ll> > sortedX;
	vector<pair<ll, ll> > sortedY;
	vector<pair<ll, ll> > EdgeList;

	for (int i = 0; i < N; i++)
	{
		cin >> X[i] >> Y[i];
		sortedX.push_back(make_pair(X[i], i));
		sortedY.push_back(make_pair(Y[i], i));
	}
	sort(sortedX.begin(), sortedX.end());
	sort(sortedY.begin(), sortedY.end());

	for (int i = 0; i < N - 1; i++)
	{
		EdgeList.push_back(make_pair(sortedX[i + 1].first - sortedX[i].first, sortedX[i].second * N + sortedX[i + 1].second));
		EdgeList.push_back(make_pair(sortedY[i + 1].first - sortedY[i].first, sortedY[i].second * N + sortedY[i + 1].second));
	}
	sort(EdgeList.begin(), EdgeList.end());

	UnionFind UF;
	UF.init(N);
	ll ans = 0;

	for (int i = 0; i < EdgeList.size(); i++)
	{
		ll idx = EdgeList[i].second;
		ll from = idx / N;
		ll to = idx % N;
		if (!UF.same(from, to))
		{
			UF.unite(from, to);
			ans += EdgeList[i].first;
		}
	}

	cout << ans << endl;
	return 0;
}
