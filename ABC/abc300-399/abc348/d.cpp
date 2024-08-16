#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int H, W, N;
int start_col, start_row, goal_col, goal_row;
vector<vector<int>> num_board;
vector<vector<bool>> visited;

bool isValid(int row, int col) {
    return row >= 0 && row < H && col >= 0 && col < W && num_board[row][col] != -1 && !visited[row][col];
}

bool canReachGoal() {
    queue<pair<int, int>> q;
    q.push({start_row, start_col});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == goal_row && c == goal_col) return true; // ゴール地点に到達できた

        visited[r][c] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];

            if (isValid(new_r, new_c)) {
                if (num_board[new_r][new_c] > num_board[r][c]) {
                    // より高いエネルギーを持つ場合には薬を使う
                    num_board[new_r][new_c] = num_board[r][c];
                }
                q.push({new_r, new_c});
            }
        }
    }

    return false; // ゴール地点に到達できなかった
}

int main() {
    cin >> H >> W;

    vector<string> board(H);
    for (int i = 0; i < H; ++i) {
        cin >> board.at(i);
    }

    num_board.resize(H, vector<int>(W, 0));
    visited.resize(H, vector<bool>(W, false));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (board[i][j] == '.') {
                num_board[i][j] = 1;
            } else if (board[i][j] == '#') {
                num_board[i][j] = -1;
            } else if (board[i][j] == 'S') {
                start_col = j;
                start_row = i;
            } else if (board[i][j] == 'T') {
                goal_col = j;
                goal_row = i;
            }
        }
    }

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y, point;
        cin >> x >> y >> point;
        num_board[y][x] = point;
    }
    if (num_board[start_col][start_row] < 1)
    {
      cout << "No" << endl;
      return 0;
    }

    if (!canReachGoal()) {
        cout << "No" << endl;
        return 0;
    }

    visited.assign(H, vector<bool>(W, false)); // visitedをリセット

    if (canReachGoal()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
