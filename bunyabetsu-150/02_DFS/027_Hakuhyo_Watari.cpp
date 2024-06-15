#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memsetを使うために追加

using namespace std;

int M, N, ans;
bool board[10009];
bool visited[10009];
vector<int> Graph[10009];

void ft_dfs(int place, int d)
{
    if (!board[place]) return;
    visited[place] = true;
    ans = max(ans, d);
    for (int i = 0; i < Graph[place].size(); i++)
    {
        int next_place = Graph[place][i];
        if (!visited[next_place]) ft_dfs(next_place, d + 1);
    }
    visited[place] = false;
}

int main()
{
    // 入力
    cin >> M >> N;
    for (int i = 0; i < N * M; i++) cin >> board[i];
    for (int i = 0; i < N * M; i++)
    {
        if (!board[i]) continue;
        int x = i % M;
        int y = i / M;
        if (x < M - 1 && board[i + 1]) Graph[i].push_back(i + 1); // 右隣
        if (x > 0 && board[i - 1]) Graph[i].push_back(i - 1); // 左隣
        if (y < N - 1 && board[i + M]) Graph[i].push_back(i + M); // 下隣
        if (y > 0 && board[i - M]) Graph[i].push_back(i - M); // 上隣
    }
    // 深さ優先探索
    ans = 0;
    for (int i = 0; i < N * M; i++)
    {
        if (!board[i]) continue;
		// 毎回全ての地点を未到達に初期化
        memset(visited, false, sizeof(visited));
        ft_dfs(i, 1);
    }
    cout << ans << endl;
    return 0;
}
