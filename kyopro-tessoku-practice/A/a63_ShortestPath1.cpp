#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> Graph[100009];
int dist[100009];
queue<int> Q;

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i];
		Graph[A[i]].push_back(B[i]);
		Graph[B[i]].push_back(A[i]);
	}
	// 初期化
	for (int i = 1; i <= N; i++) dist[i] = -1;
	// 幅優先探索
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty())
	{
		// 先頭の要素を取得して削除
		int pos = Q.front();
		Q.pop();
		// 未確定のノードがあったら現状+1してキューに加える
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next = Graph[pos][i];
			if (dist[next] == -1)
			{
				// 今回のケースではdistが更新されることはない
				dist[next] = dist[pos] + 1;
				Q.push(next);
			}
		}
	}
	// 出力
	for (int i = 1; i <= N; i++) cout << dist[i] << endl;
	return 0;
}