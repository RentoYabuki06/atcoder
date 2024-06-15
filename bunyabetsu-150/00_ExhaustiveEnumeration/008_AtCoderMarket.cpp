#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int N;
int A[39];
int B[39];

int main()
{
    cin >> N;

    // データの入力
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
        if (A[i] > B[i])
        {
            int tmp = A[i];
            A[i] = B[i];
            B[i] = tmp;
        }
    }

    // AとBをソート
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1);

    // 中央値の計算
    int A_place = A[N / 2 + 1];
    int B_place = B[N / 2 + 1];

    // 最小移動回数の計算
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans += abs(A[i] - A_place) + abs(B[i] - B_place) + abs(A[i] - B[i]);
    }

    cout << ans << endl;
    return 0;
}
