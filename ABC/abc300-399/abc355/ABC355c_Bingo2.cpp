#include <iostream>
using namespace std;

int N, T;
int A[200009];
int row_count[2009], col_count[2009];
int diag1_count = 0, diag2_count = 0;

bool BINGO() {
    for (int i = 0; i < N; i++) {
        if (row_count[i] == N || col_count[i] == N) {
            return true;
        }
    }
    if (diag1_count == N || diag2_count == N) {
        return true;
    }
    return false;
}

int main() {
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        row_count[i] = 0;
        col_count[i] = 0;
    }

    for (int i = 0; i < T; i++) {
        cin >> A[i];
        int row = (A[i] - 1) / N;
        int col = (A[i] - 1) % N;

        row_count[row]++;
        col_count[col]++;
        if (row == col) {
            diag1_count++;
        }
        if (row + col == N - 1) {
            diag2_count++;
        }

        if (i >= N - 1) {
            if (BINGO()) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}

// 下のコードだとTLEになって間に合わなかった

// #include <iostream>

// using namespace std;

// int N, T;
// int A[200009];
// bool board[2009][2009];

// bool BINGO()
// {
//     // 行のチェック
//     for (int i = 0; i < N; i++)
//     {
//         bool row_bingo = true;
//         for (int j = 0; j < N; j++)
//         {
//             if (!board[i][j])
//             {
//                 row_bingo = false;
//                 break;
//             }
//         }
//         if (row_bingo)
//             return true;
//     }

//     // 列のチェック
//     for (int j = 0; j < N; j++)
//     {
//         bool col_bingo = true;
//         for (int i = 0; i < N; i++)
//         {
//             if (!board[i][j])
//             {
//                 col_bingo = false;
//                 break;
//             }
//         }
//         if (col_bingo)
//             return true;
//     }

//     // 対角線のチェック（左上から右下）
//     bool diag1_bingo = true;
//     for (int i = 0; i < N; i++)
//     {
//         if (!board[i][i])
//         {
//             diag1_bingo = false;
//             break;
//         }
//     }
//     if (diag1_bingo)
//         return true;

//     // 対角線のチェック（右上から左下）
//     bool diag2_bingo = true;
//     for (int i = 0; i < N; i++)
//     {
//         if (!board[i][N - i - 1])
//         {
//             diag2_bingo = false;
//             break;
//         }
//     }
//     if (diag2_bingo)
//         return true;

//     return false;
// }

// int main()
// {
//     cin >> N >> T;
//     for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             board[i][j] = false;
//         }
//     }
//     for (int i = 0; i < T; i++)
//     {
//         cin >> A[i];
//         int row = (A[i] - 1) / N;
//         int col = (A[i] - 1) % N;
//         board[row][col] = true;

//         if (i >= N - 1)
//         {
//             if (BINGO())
//             {
//                 cout << i + 1 << endl;
//                 return 0;
//             }
//         }
//     }
//     cout << -1 << endl;
//     return 0;
// }
