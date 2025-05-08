#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int to;		// 行き先
	int cap;	// 容量
	int rev;	// 逆辺の位置
};

class MaximumFlow{
public:
	int size_ = 0;
	bool used[409];
	vector<Edge> Graph[409];

	// 頂点N個の残余グラフの作成
	// clear()ですべての要素を削除（初期化）
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
		Graph[a].push_back(Edge{b, c, Current_size_b});	// 向かいの辺の位置は現状の辺の格納数に依存する
		Graph[b].push_back(Edge{a, 0, Current_size_a});	// 逆方向には流量0で設定
	}

	// 深さ優先探索（deep first search）、再帰関数でもある
	// 返り値は流したフローの値（流せない場合は0）
	int dfs(int pos, int goal, int F)	// Fはスタートからposに達するまでの「残余グラフの辺の容量」の最大値
	{	
		if (pos == goal) return F;	// ゴールに到達：フローを流せる！
		used[pos] = true;
		for (int i = 0; i < Graph[pos].size(); i++)	// 現在位置(pos)から出ている辺の数だけ探索
		{
			if (Graph[pos][i].cap == 0) continue;								// 容量0の辺は使えない
			if (used[Graph[pos][i].to] == true) continue;						// すでに訪問した頂点に行っても意味がない
			int flow = dfs(Graph[pos][i].to, goal, min(F, Graph[pos][i].cap));	// 目的地までのパスを探す（次の行き先、ゴール、最小容量の更新）
			if (flow >= 1)														// フローを流せる場合、残余グラフの容量をFlowだけ増減させる
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
			for (int i = 0; i <= size_; i++) used[i] = false;	// すべての場所を未訪問にする
			int F = dfs(s, t, 1000000000);
			// フローを流せなくなったら操作終了
			if (F == 0) break;
			total_flow += F;
		}
		return total_flow;
	}
};

int		N;
char	C[159][159];
MaximumFlow Z;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) cin >> C[i][j];
	}
	// 頂点を準備
	Z.ft_init(N * 2 + 2);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (C[i][j] == '#') Z.ft_add_edge(i, N + j, 1);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		Z.ft_add_edge(N * 2 + 1, i, 1);
		Z.ft_add_edge(N + i, N * 2 + 2, 1);
	}
	// 出力
	cout << Z.max_flow(N * 2 + 1, N * 2 + 2) << endl;
	return 0;
}