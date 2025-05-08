#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[100009];
int B[100009];
int C[100009];
int par[100009];
int size_root[100009];
vector<pair<int, int>> sides;

void	ft_init()
{
	for (int i = 1; i <= N; i++) par[i] = -1;
	for (int i = 1; i <= N; i++) size_root[i] = 1;
}

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
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
		sides.push_back(make_pair(C[i], i));
	}
	// 辺が長い順番にソート
	sort(sides.begin(), sides.end(), greater<pair<int, int>>());
	// Union-find
	int total_len = 0;
	ft_init();
	for (int i = 0; i < sides.size(); i++)
	{
		int side = sides[i].second;
		if (ft_root(A[side]) != ft_root(B[side]))
		{
			ft_unite(A[side], B[side]);
			total_len += C[side];
		}
	}
	cout << total_len << endl;
	return 0;
}