#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;
const int MAX_N = 200000;

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
    ll	unite(ll u, ll v)
    {
        ll rootU = root(u);
        ll rootV = root(v);
        if (rootU == rootV) return 0;
        
        // グループを統合
        ll siz_u = siz[rootU];
        ll siz_v = siz[rootV];
        
        if (siz_u > siz_v)
        {
            par[rootV] = rootU;
            siz[rootU] += siz_v;
        }
        else
        {
            par[rootU] = rootV;
            siz[rootV] += siz_u;
        }
        return siz_u * siz_v;
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
    
    UnionFind UF;
    UF.init(N);
    vector<pair<ll, ll>> edges(M);
    vector<ll> ans(M);
    ans[M-1] = N * (N - 1) / 2;
    
    for (int i = 0; i < M; i++) cin >> edges[i].first >> edges[i].second;
    
    // 逆順に操作を実行
    for (int i = M - 1; i > 0; i--)
    {
        ll dec = UF.unite(edges[i].first, edges[i].second);
        ans[i - 1] = ans[i] - dec;
    }
    
    // 出力
    for (int i = 0; i < M; i++) cout << ans[i] << endl;
    
    return 0;
}
