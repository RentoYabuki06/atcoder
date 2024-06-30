#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll V, E;
ll S[10009];
ll T[10009];
ll D[10009];
ll dist_graph[109][109];
vector<pair<ll, ll>> Graph[100009];

int main()
{
    // 入力と初期化
    cin >> V >> E;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j) dist_graph[i][j] = 0;
            else dist_graph[i][j] = 1e18;
		}
    }
    for (int i = 0; i < E; i++)
    {
        cin >> S[i] >> T[i] >> D[i];
        dist_graph[S[i]][T[i]] = D[i];
    }
    // ワーシャルフロイド法
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
				dist_graph[i][j] = min(dist_graph[i][j], dist_graph[i][k] + dist_graph[k][j]);
            }
        }
    }
    // 負の閉路のチェック
    for (int i = 0; i < V; i++)
    {
        if (dist_graph[i][i] < 0)
        {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    // 出力
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist_graph[i][j] == 1e18) cout << "INF";
            else cout << dist_graph[i][j];
            if (j < V - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
