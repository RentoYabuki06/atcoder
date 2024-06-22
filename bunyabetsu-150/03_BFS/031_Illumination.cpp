#include <iostream>
#include <vector>

using namespace std;

// グリッドの幅と高さ
int W, H;
// グリッドを表す2次元ベクトル
vector<vector<int>> fi;
// 訪問済みセルを管理する2次元ベクトル
vector<vector<bool>> seen;

// x の偶奇による方向
int dx[2][6] = {
    {1, 0, -1, 0, 1, -1},
    {1, 0, -1, 0, 1, -1}
};
int dy[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {0, 1, 0, -1, 1, 1}
};

// 深さ優先探索 (DFS) を行う関数
void dfs(int x, int y) {
    seen[x][y] = true;  // 現在のセルを訪問済みとする
    for (int dir = 0; dir < 6; ++dir) {  // 6方向を探索
        int nx = x + dx[x % 2][dir];  // 新しい x 座標
        int ny = y + dy[x % 2][dir];  // 新しい y 座標
        // 範囲外チェック
        if (nx < 0 || nx >= H + 2 || ny < 0 || ny >= W + 2) continue;
        // 障害物チェック
        if (fi[nx][ny] == 1) continue;
        // 未訪問なら再帰的に探索
        if (!seen[nx][ny]) dfs(nx, ny);
    }
}

int main() {
    // グリッドの幅と高さを入力
    cin >> W >> H;
    // グリッドを初期化 (周囲に余白を持たせる)
    fi.resize(H + 2, vector<int>(W + 2, 0));
    seen.resize(H + 2, vector<bool>(W + 2, false));
    // 入力の読み込み
    for (int x = 1; x <= H; ++x) {
        for (int y = 1; y <= W; ++y) {
            cin >> fi[x][y];
        }
    }
    // 外周からのDFS開始
    dfs(0, 0);
    // 見えていないセルを 1 に変更
    for (int x = 1; x <= H; ++x) {
        for (int y = 1; y <= W; ++y) {
            if (!seen[x][y]) fi[x][y] = 1;
        }
    }
    int res = 0;  // 境界の長さをカウントする変数
    // グリッド内のセルを全てチェック
    for (int x = 1; x <= H; ++x) {
        for (int y = 1; y <= W; ++y) {
            if (fi[x][y] == 0) continue;  // 空白セルはスキップ
            // 6方向をチェック
            for (int dir = 0; dir < 6; ++dir) {
                int nx = x + dx[x % 2][dir];
                int ny = y + dy[x % 2][dir];
                if (fi[nx][ny] == 0) ++res;  // 隣接する空白セルがあれば境界
            }
        }
    }
    // 境界の長さを出力
    cout << res << endl;
    return 0;
}
