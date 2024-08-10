#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);  // Vectorを使用して動的にサイズを決定
    vector<ll> dp;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    dp.push_back(A[0]);  // A[0] を事前に dp に追加

    for (int i = 1; i < N; i++)  // ループは i = 1 から開始
    {
        int place = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if (place == dp.size()) dp.push_back(A[i]);
        else dp[place] = A[i];
    }
    cout << dp.size() << endl;
    return 0;
}
