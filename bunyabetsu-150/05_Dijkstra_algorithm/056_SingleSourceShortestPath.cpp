#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int V, E, R;
int S[100009];
int T[100009];
int D[100009];
vector<pair<int, int>> Graph[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

int main()
{
	// 入力
	cin >> V >> E >> R;
	for (int i = 0; i < E; i++)
	{
		cin >> S[i] >> T[i] >> D[i];
		Graph[S[i]].push_back(make_pair(T[i], D[i]));
	}
	// 配列の初期化
	vector<int> cur(V, 100000000);
	vector<bool> fixed(V, false);
	// スタート地点をキューに追加
	cur[R] = 0;
	Q.push(make_pair(cur[R], R));
	// ダイクストラ法
	while (!Q.empty())
	{
		int pos = Q.top().second;
		Q.pop();
		if (fixed[pos]) continue;
		fixed[pos] = true;
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
	// 出力
    for (int i = 0; i < V; i++)
    {
        if (cur[i] == 100000000)
            cout << "INF" << endl;
        else
            cout << cur[i] << endl;
    }
	return 0;
}