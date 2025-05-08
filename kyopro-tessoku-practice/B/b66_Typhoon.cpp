#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, Q;
int A[100009], B[100009];
int Query[100009], U[100009], V[100009];
int par[100009];
int size_root[100009];
bool del_station[100009];
stack<bool> ans;

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
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i];
	for (int i = 1; i <= N; i++) del_station[i] = false;
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		cin >> Query[i] >> U[i];
		if (Query[i] == 2) cin >> V[i];
		if (Query[i] == 1) del_station[U[i]] = true;
	}
	// 初期化
	for (int i = 1; i <= N; i++)
	{
		par[i] = -1;
		size_root[i] = 1;
	}
	// 削除されない路線を追加
	for (int i = 1; i <= M; i++)
	{
		if (del_station[i] ==  false) ft_unite(A[i], B[i]);
	}
	// クエリの処理
	for (int i = Q; i > 0; i--)
	{
		if (Query[i] == 1)
		{
			ft_unite(A[U[i]], B[U[i]]);
		}
		if (Query[i] == 2)
		{
			if (ft_root(U[i]) == ft_root(V[i])) ans.push(true);
			else ans.push(false);
		}
	}
	while (!ans.empty())
	{
		if (ans.top() == true) cout << "Yes" << endl;
		else cout << "No" << endl;
		ans.pop();
	}
	return 0;
}