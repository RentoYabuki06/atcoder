#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll H, W;
ll C[209][209];
ll A[209][209];
ll count_num[19];
ll majical_power[19][19];

int main()
{
    // 入力と初期化
    cin >> H >> W;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> C[i][j];
			// 必要な魔力を初期化
            majical_power[i][j] = C[i][j];
        }
    }
	// それぞれの数字が何回出てくるかカウント
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
            if (A[i][j] != -1)
            {
                count_num[A[i][j]]++;
            }
        }
    }
    // それぞれの数字から1に到達する労力をワーシャルフロイド法で求める
    for (int k = 0; k < 10; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                majical_power[i][j] = min(majical_power[i][j], majical_power[i][k] + majical_power[k][j]);
            }
        }
    }
    // 必要な魔力を計算して出力
    ll ans = 0;
    for (int k = 0; k < 10; k++) ans += count_num[k] * majical_power[k][1];
    cout << ans << endl;
    return 0;
}
