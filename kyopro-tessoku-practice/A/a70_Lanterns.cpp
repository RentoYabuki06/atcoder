#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int A[19];
int X[109];
int Y[109];
int Z[109];
int dist[1029];
vector<int> Graph[1029];

int	ft_get_next(int pos, int idx)
{
	int lanterns[19];
	// 10進数からランタンの情報を取得
	for (int i = 1; i <= N; i++) lanterns[i] = (pos >> (i - 1)) & 1;
	// ３つのランタンの状態を反転
	lanterns[X[idx]] = 1 - lanterns[X[idx]];
	lanterns[Y[idx]] = 1 - lanterns[Y[idx]];
	lanterns[Z[idx]] = 1 - lanterns[Z[idx]];
	// ランタンの情報を10進数に戻す
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		if (lanterns[i] == 1) ret += (1 << (i - 1));
	}
	return ret;
}

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> X[i] >> Y[i] >> Z[i];
	
	// グラフに辺を追加
	// max(i << N)個の状態、M個の状態変更の選択肢
	for (int i = 0; i < (1 << N); i++)
	{
		for (int j = 1; j <= M; j++) Graph[i].push_back(ft_get_next(i ,j));
	}

	// スタート地点とゴール地点を決める
	int start = 0;
	// 初期状態のセット
	for (int i = 1; i <= N; i++)
	{
		if (A[i] == 1) start += (1 << (i - 1));
	}
	int goal = (1 << N) - 1;

	// 配列の初期化・スタート地点をキューに入れる
	queue<int> Q;
	for (int i = 0; i < (1 << N); i++) dist[i] = -1;
	dist[start] = 0;
	Q.push(start);

	// 幅優先探索
	while (!Q.empty())
	{
		int pos = Q.front();
		Q.pop();
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next_place = Graph[pos][i];
			if (dist[next_place] == -1)
			{
				dist[next_place] = dist[pos] + 1;
				Q.push(next_place);
			}
		}
	}

	//出力
	cout << dist[goal] << endl;
	return 0;
}