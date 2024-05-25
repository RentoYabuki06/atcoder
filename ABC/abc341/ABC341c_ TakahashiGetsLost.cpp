# include <iostream>
# include <string>

using namespace std;

int H, W, N;
string T;
char S[509][509];

int main()
{
    // 入力
    cin >> H >> W >> N >> T;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++) cin >> S[i][j];
    }
    int ans = 0;
    for (int start_i = 0; start_i < H; start_i++)
    {
        for (int start_j = 0; start_j < W; start_j++)
        {
            if (S[start_i][start_j] == '.')
            {
                int i = start_i, j = start_j;
                bool valid = true;
                for (int k = 0; k < T.size(); k++)
                {
                    if (T[k] == 'U' && i > 0) i--;
                    else if (T[k] == 'D' && i < H - 1) i++;
                    else if (T[k] == 'L' && j > 0) j--;
                    else if (T[k] == 'R' && j < W - 1) j++;
                    if (S[i][j] == '#')
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
