#include <iostream>

using namespace std;

int N, M;
int k[19];
int s[19][19];
int p[19];
bool on_off[19];

int main()
{
    // 入力
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) cin >> s[i][j];
    }
    for (int i = 1; i <= M; i++) cin >> p[i];

    // N個のスイッチの状態をビット全探索
    int ans = 0;
    for (int state = 0; state < (1 << N); state++)
    {
        // スイッチの状態をセット
        for (int l = 1; l <= N; l++)
        {
            on_off[l] = (state & (1 << (l - 1))) != 0;
        }
        
        // M個の電球がつくか付かないかを判定
        bool all_on = true;
        for (int i = 1; i <= M; i++)
        {
            int count_on = 0;
            for (int j = 1; j <= k[i]; j++) 
            {
                if (on_off[s[i][j]]) count_on++;
            }
            if (count_on % 2 != p[i])
            {
                all_on = false;
                break;
            }
        }
        
        if (all_on) ans++;
    }

    // 結果を出力
    cout << ans << endl;
}
