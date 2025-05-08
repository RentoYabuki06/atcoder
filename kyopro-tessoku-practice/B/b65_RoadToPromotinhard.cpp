#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N, T;
int A[100009];
int B[100009];
int dist[100009];
int dp[100009];
vector<int> Graph[100009];
queue<int> Q;
priority_queue<pair<int, int>> Queue;
bool member[100009];

int main()
{
	// 入力
	cin >> N >> T;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> B[i];
		Graph[A[i]].push_back(B[i]);
		Graph[B[i]].push_back(A[i]);
		dist[i] = -1;
		dp[i] = -1;
		member[i] = false;
	}
	// 幅優先探索でTとの距離distを求める
	Q.push(T);
	dist[T] = 0;
	Queue.push(make_pair(dist[T], T));
	while(!Q.empty())
	{
		int pos = Q.front();
		Q.pop();
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next = Graph[pos][i];
			if (dist[next] == -1)
			{
				dist[next] = dist[pos] + 1;
				Queue.push(make_pair(dist[next], next));
				Q.push(next);
			}
		}
	}
	// 動的計画法
	while (!Queue.empty())
	{
		int i = Queue.top().second;
		Queue.pop();
		dp[i] = 0;
		member[i] = true;
		for (int j = 0; j < Graph[i].size(); j++)
		{
			dp[i] = max(dp[i], dp[Graph[i][j]] + 1);
		}
	}
	// 出力
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}