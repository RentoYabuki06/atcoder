#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll N;
vector<ll> Edge[201010];
ll NumNode_subtree[201010];
ll ret = 0;

ll ft_modpow(ll a, ll n = MOD - 2)
{
    ll result = 1;
    a %= MOD;
    while (n) {
        if (n % 2) {
            result = result * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return result;
}

ll ft_dfs(ll cur_node, ll pre_node)
{
    NumNode_subtree[cur_node] = 1;	// 現在のノード cur を根とする部分木には最低でも自分自身が含まれる
    vector<ll> B;
	// 現在のノードの子ノードを再帰的に呼び出して部分木のサイズを計算
    for (ll edge : Edge[cur_node])
	{
        if (edge != pre_node)
		{
            B.push_back(ft_dfs(edge, cur_node));
            NumNode_subtree[cur_node] += B.back();
        }
    }
	// 現在の部分木の外にあるノード数をベクター B に追加
    if (NumNode_subtree[cur_node] < N)
		B.push_back(N - NumNode_subtree[cur_node]);
    
    ll P[3] = { (MOD + 1) / 2, 0, 0 };
    for (ll b : B)
	{
        ll w = ft_modpow((MOD + 1) / 2, b);	// ノードが白く塗られる確率を b 回掛けた結果
        b = (1 + MOD - w) % MOD;			// b を黒く塗られる確率に変換します。
        ll Q[3] = {};						
        Q[0] = P[0] * w % MOD;				// [0]:ノードが白く塗られる確率を掛け合わせます。
        Q[1] = (P[1] * w + P[0] * b) % MOD;	// Q[1] は、現在のノードが白く塗られる確率と黒く塗られる確率を掛け合わせた結果を持ちます。
        Q[2] = (P[2] + P[1] * b) % MOD;		// Q[2] は、穴あき度を表す確率を持ちます。
		// Pの各要素をQで更新
        for (ll i = 0; i < 3; ++i) P[i] = Q[i];
    }
    // 最終的なP[2]の値を加算
    ret = (ret + P[2]) % MOD;
    return NumNode_subtree[cur_node];
}

int main()
{
    cin >> N;
    for (ll i = 0; i < N - 1; ++i)
	{
        ll x, y;
        cin >> x >> y;
        Edge[x - 1].push_back(y - 1);
        Edge[y - 1].push_back(x - 1);
    }
    ft_dfs(0, -1);
    cout << ret % MOD << endl;
    return 0;
}
