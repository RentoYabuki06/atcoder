#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int R, C, sy, sx, gy, gx;
char board[2509];
int dist[2509];
vector<int> Graph[2509];
queue<int> Q;

int main()
{
	// 入力
	cin >> R >> C >> sy >> sx >> gy >> gx;
	for (int i = 1; i <= C * R; i++) cin >> board[i];
	// 初期化
	for (int i = 1; i <= C * R; i++) dist[i] = -1;
	for (int i = 1; i <= C * R; i++)
	{
		if (board[i] == '.')
		{
			dist[i] = -1;
			if (i % C != 1)
			{
				if (board[i - 1] == '.') Graph[i].push_back(i - 1);
			}
			if (i % C != 0)
			{
				if (board[i + 1] == '.') Graph[i].push_back(i + 1);
			}
			if (i > C)
			{
				if (board[i - C] == '.') Graph[i].push_back(i - C);
			}
			if (i < C * (R - 1))
			{
				if (board[i + C] == '.') Graph[i].push_back(i + C);
			}
		}
	}
	// 幅優先探索
	int start = (sy - 1) * C + sx;
	Q.push(start);
	dist[start] = 0;
	while (!Q.empty())
	{
		// 先頭の要素を取得して削除
		int pos = Q.front();
		Q.pop();
		// 未確定のノードがあったら現状+1してキューに加える
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next = Graph[pos][i];
			if (dist[next] == -1 || dist[next] > dist[pos] + 1)
			{
				// 今回のケースではdistが更新されることはない
				dist[next] = dist[pos] + 1;
				Q.push(next);
			}
		}
	}
	cout << dist[(gy - 1) * C + gx] << endl;
	return 0;
}