#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

double dist(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
}

int main()
{
	while(true)
	{
		ll N;
		cin >> N;
		if (N == 0) return 0;
		vector<double> X(N);
		vector<double> Y(N);
		vector<double> Z(N);
		vector<double> R(N);
		vector<pair<double, ll> > EdgeList;

		for (int i = 0; i < N; i++)
		{
			cin >> X[i] >> Y[i] >> Z[i] >> R[i];
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				double d = max(0.0, dist(X[i], Y[i], Z[i], X[j], Y[j], Z[j]) - R[i] - R[j]);
				EdgeList.push_back(make_pair(d, i * N + j));
			}
		}

		sort(EdgeList.begin(), EdgeList.end());

		UnionFind UF;
		UF.init(N);
		double ans = 0;

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

		cout << fixed << setprecision(3) << ans << endl;
	}
	return 0;
}
