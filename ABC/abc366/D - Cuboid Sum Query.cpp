#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll N, Q;
ll A[109][109][109];
ll S[110][110][110]; // 累積和を保持する配列

int main()
{
    // 入力の読み込み
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                cin >> A[i][j][k];
            }
        }
    }

    // 累積和の計算
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                S[i][j][k] = A[i][j][k]
                            + S[i-1][j][k]
                            + S[i][j-1][k]
                            + S[i][j][k-1]
                            - S[i-1][j-1][k]
                            - S[i-1][j][k-1]
                            - S[i][j-1][k-1]
                            + S[i-1][j-1][k-1];
            }
        }
    }

    // クエリ処理
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;

        ll result = S[Rx][Ry][Rz]
                  - S[Lx-1][Ry][Rz]
                  - S[Rx][Ly-1][Rz]
                  - S[Rx][Ry][Lz-1]
                  + S[Lx-1][Ly-1][Rz]
                  + S[Lx-1][Ry][Lz-1]
                  + S[Rx][Ly-1][Lz-1]
                  - S[Lx-1][Ly-1][Lz-1];

        cout << result << endl;
    }

    return 0;
}
