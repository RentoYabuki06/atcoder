#include <iostream>
#include <vector>

using namespace std;

int N, Q;
int Query[100009], U[100009], V[100009];
int par[100009];
int size_root[100009];

int ft_root(int a)
{
	while(true)
	{
		if (par[a] == -1) break;
		a = par[a];
	}
	return a;
}

void	ft_unite(int u, int v)
{
	int u_root = ft_root(u);
	int v_root = ft_root(v);
	if (u_root == v_root) return;
	if (size_root[u_root] < size_root[v_root])
	{
		par[u_root] = v_root;
		size_root[v_root] += size_root[u_root];
	}
	else
	{
		par[v_root] = u_root;
		size_root[u_root] += size_root[v_root];
	}
}

int main()
{
	// 入力
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) cin >> Query[i] >> U[i] >> V[i];
	// 初期化
	for (int i = 1; i <= N; i++)
	{
		par[i] = -1;
		size_root[i] = 1;
	}
	// クエリの処理
	for (int i = 1; i <= Q; i++)
	{
		if (Query[i] == 1)
		{
			ft_unite(U[i], V[i]);
		}
		if (Query[i] == 2)
		{
			if (ft_root(U[i]) == ft_root(V[i])) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}