#include <iostream>
#include <vector>

using namespace std;

int N;
int A[19];
int B[19];
bool dp[1 << 18];

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    // 動的計画法
    for (int k = 0; k < (1 << N); k++)
    {
        bool now = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (!((k >> i) & 1)) continue;
                if (!((k >> j) & 1)) continue;
                if (A[i] == A[j] || B[i] == B[j])
                {
                    int pre = (k & ~(1 << i) & ~(1 << j));
                    if (dp[pre] == false) now = true;
                }
            }
        }
        dp[k] = now;
    }
    // 出力
    if (dp[(1 << N) - 1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}