#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int INF = 1e9;

int N, M;
int A[100009], B[100009], C[100009];
int cur[100009];
vector<pair<int, int>> Graph[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i] >> C[i]; 
		Graph[A[i]].push_back(make_pair(B[i], C[i]));
		Graph[B[i]].push_back(make_pair(A[i], C[i]));
	}
	//　初期値の設定
	for (int i = 1; i <= N; i++) cur[i] = INF;
	// スタート
	cur[1] = 0;
	Q.push(make_pair(cur[1], 1));
	// ダイクストラ法
	while (!Q.empty())
	{
		pair<int, int> top = Q.top();
		Q.pop();
		int pos = top.second;
		if (cur[pos] == INF) continue;
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next_place = Graph[pos][i].first;
			int next_time = Graph[pos][i].second;
			if (cur[next_place] > cur[pos] + next_time)
			{
				cur[next_place] = cur[pos] + next_time;
				Q.push(make_pair(cur[next_place], next_place));
			}
		}
	}
	// 経路を記憶
	stack<int> path;
	int pos = N;
	path.push(pos);
	while (pos != 1)
	{
		for (int i = 0; i < Graph[pos].size(); i++)
		{
			int next_place = Graph[pos][i].first;
			int next_time = Graph[pos][i].second;
			if (cur[pos] == cur[next_place] + next_time)
			{
				path.push(next_place);
				pos = next_place;
				break;
			}
		}
	}
	// 出力
	cout << path.top();
	path.pop();
	while (!path.empty())
	{
		cout << " " << path.top();
		path.pop();
	}
	cout << endl;
}