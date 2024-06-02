#include <iostream>
using namespace std;

long long N, M, K;
long long C[1009];
char R[1009];
bool R_key[1009];
long long A[109][109];
bool key[109];

int main()
{
    cin >> N >> M >> K;
    for (long long i = 1; i <= M; i++)
    {
        cin >> C[i];
        for (long long j = 1; j <= C[i]; j++) cin >> A[i][j];
        cin >> R[i];
        if (R[i] == 'o') R_key[i] = true;
        else R_key[i] = false;
    }
    long long ans = 0;
    // ビット全探索
    for (long long i = 0; i < (1LL << N); i++)
    {
        long long tmp = i;
        long long count = 0;
        for (long long j = 1; j <= N; j++)
        {
            if (tmp >> (j - 1) & 1)
            {
                key[j] = true;
                count++;
            }
            else key[j] = false;
        }
        if (count < K) continue;
        bool valid = true;
        for (long long i = 1; i <= M; i++)
        {
            long long num_true = 0;
            for (long long j = 1; j <= C[i]; j++)
            {
                if (key[A[i][j]])
                {
                    num_true++;
                }
            }
            if (num_true >= K && !R_key[i])
            {
                valid = false;
                break;
            }
            if (num_true < K && R_key[i])
            {
                valid = false;
                break;
            }
        }
        if (valid) ans++;
    }
    cout << ans << endl;
    return 0;
}
