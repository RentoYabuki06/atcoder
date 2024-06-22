#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int dist[109];
vector<int> Graph[109];
queue<int> Q;

int main()
{
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int u, k, v;
        cin >> u >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> v;
            Graph[u].push_back(v);
        }
        // 初期化
        dist[i] = -1;
    }
    // 初期条件
    dist[1] = 0;
    Q.push(1);
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
    // 出力
    for (int i = 1; i <= N; i++) cout << i << " " << dist[i] << endl;
    return 0;
}
