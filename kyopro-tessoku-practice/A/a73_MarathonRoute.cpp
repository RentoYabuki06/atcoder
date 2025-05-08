#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[100009];
int B[100009];
int C[100009];
int D[100009];
vector<pair<int, int>> Graph[8009];

long long cur[8009];
bool kakutei[8009];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		if (D[i] == 1)
		{
			Graph[A[i]].push_back(make_pair(B[i], C[i] * 1e5 - 1));
			Graph[B[i]].push_back(make_pair(A[i], C[i] * 1e5 - 1));
		}
		else
		{
			Graph[A[i]].push_back(make_pair(B[i], C[i] * 1e5));
			Graph[B[i]].push_back(make_pair(A[i], C[i] * 1e5));
		}
	}
	// 配列の初期化
	for (int i = 1; i <= N; i++) kakutei[i] = false;
	for (int i = 1; i <= N; i++) cur[i] = (1LL << 60);
	// スタート地点にキューを追加
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));
	// ダイクストラ法
	while (!Q.empty())
	{
		int pos = Q.top().second;
		Q.pop();
		// もし確定済みだったらスキップ
		if (kakutei[pos]) continue;
		// cur[nex]の値を更新
		kakutei[pos] = true;
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int nex = Graph[pos][i].first;
			int cost = Graph[pos][i].second;
			if (cur[nex] > cur[pos] + cost)
			{
				cur[nex] = cur[pos] + cost;
				Q.push(make_pair(cur[nex], nex));
			}
		}
	}

	// 答えを出力
	long long distance = (cur[N] + 9999) / 1e5;
	long long num_tree = distance * 1e5 - cur[N];
	cout << distance << " " << num_tree << endl;
	return 0;
}