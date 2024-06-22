#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int H, W;
vector<int> Graph[2509];
int dist[2509];
bool board[2509];
queue<int> Q;

int main()
{
    // 入力
    cin >> H >> W;
    int white_grid = 0;
    for (int i = 0; i < H; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++)
        {
            if (S[j] == '.')
            {
                white_grid++;
                board[i * W + j] = true;
            }
            else board[i * W + j] = false;
        }
    }
    
    // グラフの構築
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int idx = i * W + j;
            if (board[idx])
            {
                if (i > 0 && board[idx - W]) Graph[idx].push_back(idx - W); // 上
                if (i < H - 1 && board[idx + W]) Graph[idx].push_back(idx + W); // 下
                if (j > 0 && board[idx - 1]) Graph[idx].push_back(idx - 1); // 左
                if (j < W - 1 && board[idx + 1]) Graph[idx].push_back(idx + 1); // 右
            }
        }
    }

    // 初期条件
    fill(dist, dist + H * W, -1);
    dist[0] = 1;
    Q.push(0);

    // 幅優先探索により最短経路を探索
    while (!Q.empty())
    {
        int pos = Q.front();
        Q.pop();
        for (int next_place : Graph[pos])
        {
            if (dist[next_place] == -1)
            {
                dist[next_place] = dist[pos] + 1;
                Q.push(next_place);
            }
        }
    }

    // 出力
    int goal = H * W - 1;
    if (dist[goal] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << white_grid - dist[goal] << endl;
    }
    return 0;
}
