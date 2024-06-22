#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, sy, sx, gy, gx;
int dist[2509];
bool board[2509];
vector<int> Graph[2509];
queue<int> Q;

int main()
{
    // 入力と初期化
    cin >> R >> C >> sy >> sx >> gy >> gx;
    for (int i = 1; i <= R * C; i++)
    {
        char c;
        cin >> c;
        if (c == '.') board[i] = true;
        else board[i] = false;
        dist[i] = -1; // 修正
    }

    // グラフの構築
    for (int i = 1; i <= R * C; i++)
    {
        if (i > C && board[i - C]) Graph[i].push_back(i - C); // 上
        if (i <= (R - 1) * C && board[i + C]) Graph[i].push_back(i + C); // 下
        if (i % C != 1 && board[i - 1]) Graph[i].push_back(i - 1); // 左
        if (i % C != 0 && board[i + 1]) Graph[i].push_back(i + 1); // 右
    }

    // 初期条件
    int start_place = (sy - 1) * C + sx; // 1ベースの場合
    int goal_place = (gy - 1) * C + gx; // 1ベースの場合
    dist[start_place] = 0;
    Q.push(start_place);

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
                // ゴールが来たら出力
                if (next_place == goal_place)
                {
                    cout << dist[next_place] << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl; // ゴールに到達できない場合
    return 0;
}
