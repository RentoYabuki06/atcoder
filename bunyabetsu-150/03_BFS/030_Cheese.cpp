#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

int H, W, N;
int dist[1000009];
bool board[1000009];
int cheese_place[19];
vector<int> Graph[1000009];

// n番目の工場からn-1番目の工場に向かう距離を求める
int ft_bfs(int start_place, int goal_place)
{
    // 初期化
    for (int i = 0; i < H * W; i++) dist[i] = -1;
	queue<int> Q;
    // 幅優先探索
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
                    return dist[next_place];
                }
            }
        }
    }
    return -1; // ゴールに到達できなかった場合
}

int main()
{
    // 入力
    cin >> H >> W >> N;
    // ゼロインデックスで盤面を作る
    for (int i = 0; i < H; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < W; j++)
        {
            int current_place = i * W + j;
            board[current_place] = true;
            if (isdigit(S[j])) cheese_place[S[j] - '0'] = current_place;
            if (S[j] == 'S') cheese_place[0] = current_place;
            if (S[j] == 'X') board[current_place] = false;
        }
    }
    // グラフの構築
    for (int i = 0; i < H * W; i++)
    {
        if (board[i])
        {
            if (i >= W && board[i - W]) Graph[i].push_back(i - W); // 上
            if (i < (H - 1) * W && board[i + W]) Graph[i].push_back(i + W); // 下
            if (i % W != 0 && board[i - 1]) Graph[i].push_back(i - 1); // 左
            if (i % W != W - 1 && board[i + 1]) Graph[i].push_back(i + 1); // 右
        }
    }
    // 探索
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += ft_bfs(cheese_place[i - 1], cheese_place[i]);
    }
    // 出力
    cout << ans << endl;
    return 0;
}
