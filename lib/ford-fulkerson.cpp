#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int to;
	int cap;
	int rev;
};

class MaximumFlow{
public:
	int size_ = 0;
	bool used[409];
	vector<Edge> Graph[409];

	// 頂点N個の残余グラフの作成o
	void	ft_init(int N)
	{
		size_ = N;
		for (int i = 0; i <= size_; i++) Graph[i].clear();
	}

	// 頂点aからbに向かう、上限c L/sの辺を追加
	void	ft_add_edge(int a, int b, int c)
	{
		int Current_size_a = Graph[a].size();
		int Current_size_b = Graph[b].size();
		Graph[a].push_back(Edge{b, c, Current_size_b});
		Graph[b].push_back(Edge{a, 0, Current_size_a});
	}

	// 深さ優先探索
	// Fはスタートからposに達するまでの残余グラフの辺の要領の最大値
	// 返り値は流したフローの値（流せない場合は0）
	int dfs(int pos, int goal, int F)
	{
		// ゴールに到達：フローを流せる！
		if (pos == goal) return F;
		used[pos] = true;
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			// 容量0の辺は使えない
			if (Graph[pos][i].cap == 0) continue;
			// すでに訪問した頂点に行っても意味がない
			if (used[Graph[pos][i].to] == true) continue;
			// 目的地までのパスを探す
			int flow = dfs(Graph[pos][i].to, goal, min(F, Graph[pos][i].cap));
			// フローを流せる場合、残余グラフの容量をFlowだけ増減させる
			if (flow >= 1)
			{
				Graph[pos][i].cap -= flow;
				Graph[Graph[pos][i].to][Graph[pos][i].rev].cap += flow;
				return flow;
			}
		}
		// 全ての辺を探索しても見つからなかった場合
		return 0;
	}

	// 頂点sから頂点tまでの最大フローの総流量を流す
	int max_flow(int s, int t)
	{
		int total_flow = 0;
		while (true)
		{
			for (int i = 0; i <= size_; i++) used[i] = false;
			int F = dfs(s, t, 1000000000);

			// フローを流せなくなったら操作終了
			if (F == 0) break;
			total_flow += F;
		}
		return total_flow;
	}
};

int N, M;
int A[409];
int B[409];
int C[409];
MaximumFlow Z;

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];

	// 辺を追加
	Z.ft_init(N);

	for (int i = 1; i <= M; i++) Z.ft_add_edge(A[i], B[i], C[i]);

	// 出力
	cout << Z.max_flow(1, N) << endl;
	return 0;
}