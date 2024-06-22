#include <iostream>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

int H, W;
vector<vector<int>> board;
vector<vector<int>> visited;

int dx[2][6] = {
    {1, 0, -1, 0, 1, -1},
    {1, 0, -1, 0, 1, -1}
};
int dy[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {0, 1, 0, -1, 1, 1}
};

void ft_judge_outside(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 6; i++) {  // 配列インデックスを0から開始
        int nx = x + dx[x % 2][i];  // y % 2をx % 2に修正
        int ny = y + dy[x % 2][i];  // y % 2をx % 2に修正
        if (nx < 0 || nx >= H + 2 || ny < 0 || ny >= W + 2) continue;
        if (board[nx][ny]) continue;
        if (!visited[nx][ny]) ft_judge_outside(nx, ny);
    }
}

int main() {
    // 入力
    cin >> W >> H;
    board.resize(H + 2, vector<int>(W + 2, 0));
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cin >> board[i][j];
    }
    // 外周から到達できるマスを調べる
    visited.resize(H + 2, vector<int>(W + 2, false));
    ft_judge_outside(0, 0);
    // 訪問できなかったセルを建物判定に変更
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (!visited[i][j]) board[i][j] = 1;  // trueを1に修正
        }
    }
    // 壁の長さをカウント
    int ans = 0;
    for (int x = 1; x <= H; x++) {
        for (int y = 1; y <= W; y++) {
            if (!board[x][y]) continue;
            for (int i = 0; i < 6; i++) {  // 配列インデックスを0から開始
                int nx = x + dx[x % 2][i];  // y % 2をx % 2に修正
                int ny = y + dy[x % 2][i];  // y % 2をx % 2に修正
                if (nx < 0 || nx >= H + 2 || ny < 0 || ny >= W + 2) continue;
                if (!board[nx][ny]) ans++;
            }
        }
    }
    // 出力
    cout << ans << endl;
    return 0;
}
