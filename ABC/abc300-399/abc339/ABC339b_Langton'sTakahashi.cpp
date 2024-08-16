#include <iostream>
#include <vector>

using namespace std;

int H, W, N;

vector<string> board;

int main()
{
    // 入力と盤面の初期化
    cin >> H >> W >> N;
    board.resize(H * W + 1, ".");
    int direction = 1; // 1: 上, 2 : 右, 3 : 下, 4 : 左
    int Cplace = 1; // 現在の場所
    // N回の操作
    for (int i = 0; i < N; i++)
    {
        if (board[Cplace] == ".")
        {
            board[Cplace] = "#";
            direction = (direction % 4) + 1;
        }
        else
        {
            board[Cplace] = ".";
            direction = (direction + 2) % 4 + 1;
        }

        if (direction == 2) // 右
        {
            if (Cplace % W != 0) Cplace++;
            else Cplace -= (W - 1);
        }
        else if (direction == 4) // 左
        {
            if ((Cplace - 1) % W != 0) Cplace--;
            else Cplace += (W - 1);
        }
        else if (direction == 3) // 下
        {
            if (Cplace <= (H - 1) * W) Cplace += W;
            else Cplace -= (H - 1) * W;
        }
        else if (direction == 1) // 上
        {
            if (Cplace > W) Cplace -= W;
            else Cplace += (H - 1) * W;
        }
    }
    // 出力
    for (int i = 1; i <= H * W; i++)
    {
        cout << board[i];
        if (i % W == 0) cout << endl;
    }
    return 0;
}
