#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long Q[19];
long long A[19];
long long B[19];

int main()
{
    // 入力
    cin >> N;
    long long max_Q = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> Q[i];
        max_Q = max(max_Q, Q[i]);
    }
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    
    // Aをx個作る時、Bは最大いくら作れるか
    long long ans = 0;
    for (int i = 0; i <= max_Q; i++)
    {
        long long max_y = 1e18;
        for (int j = 1; j <= N; j++)
        {
            if (Q[j] < A[j] * i)
            {
                max_y = -1e18;
            }
            else if (B[j] > 0)
            {
                long long tmp = (Q[j] - A[j] * i) / B[j];
                max_y = min(max_y, tmp);
            }
        }
		ans = max(ans, i + max_y);
    }
    cout << ans << endl;
    return 0;
}
