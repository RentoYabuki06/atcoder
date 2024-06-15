#include <iostream>
#include <vector>

using namespace std;

int W, H;
int board[2509][2509];
bool visited[2509][2509];
vector<int> Graph[2509];
int count_island;

void ft_dfs(int x, int y)
{
    visited[x][y] = true;
    int dx[] = {1, -1, 0, 0, 1, 1, -1, -1}; // 横と斜めの方向
    int dy[] = {0, 0, 1, -1, 1, -1, 1, -1}; // 横と斜めの方向

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && board[nx][ny] == 1) {
            ft_dfs(nx, ny);
        }
    }
}

int main()
{
    // 入力
    while (true)
    {
        cin >> W >> H;
        if (W == 0 && H == 0) return 0;

        // 入力と初期化
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> board[i][j];
                visited[i][j] = false;
            }
        }

        // 深さ優先探索
        count_island = 0;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (!visited[i][j] && board[i][j] == 1)
                {
                    count_island++;
                    ft_dfs(i, j);
                }
            }
        }
        cout << count_island << endl;
    }
}
