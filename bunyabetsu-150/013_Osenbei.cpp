#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
bool board[19][10009];
bool tmp_board[19][10009];

bool should_flip_column(int this_row)
{
    int front_count = 0;
    for (int i = 1; i <= R; i++)
    {
        if (tmp_board[i][this_row]) front_count++;
    }
    if (front_count > R / 2) return true;
    else return false;
}

int num_shippable_senzei()
{
    int count = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++) 
        {
            if (!tmp_board[i][j]) count++;
        }
    }
    return count;
}

int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++) cin >> board[i][j];
    }
    // 縦と横の操作は前後逆にしてもOK.
    // まず少ない行方向でビット全探索を行い、次に表の方が多い列を裏返す。
    int max_senbei = 0;
    for (int k = 0; k < (1 << R); k++)
    {
        // ボードの初期化
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++) tmp_board[i][j] = board[i][j];
        }
        // どの行を裏返すか
        long long tmp = k;
        for (int i = 1; i <= R; i++)
        {
            if (tmp % 2 == 1)
            {
                for (int j = 1; j <= C; j++)
                tmp_board[i][j] = !tmp_board[i][j];
            }
            tmp /= 2;
        }
        // どの列を裏返すか（表の面の方が多かったら裏返す）
        for (int j = 1; j <= C; j++)
        {
            if (should_flip_column(j))
            {
                for (int i = 1; i <= R; i++)
                {
                    tmp_board[i][j] = !tmp_board[i][j];
                }
            }
        }
        // 得点計算
        max_senbei = max(max_senbei, num_shippable_senzei());
    }
    cout << max_senbei << endl;
    return 0;
}
