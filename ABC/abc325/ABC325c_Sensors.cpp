#include <iostream>
#include <vector>

using namespace std;

int H, W;
bool board[1009][1009];

void ft_check(int x, int y)
{
    board[x][y] = false;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny])
            {
                ft_check(nx, ny);
            }
        }
    }
}

int main()
{
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    // 盤面の整理
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#') board[i][j] = true;
            else board[i][j] = false;
        }
    }
    // センサの単位がいくつあるかチェック
    int ans = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (board[i][j])
            {
                ans++;
                ft_check(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
