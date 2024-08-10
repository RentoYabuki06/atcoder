#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> dp;
    for (int i = 0; i < N; i++) cin >> A[i];
    dp.push_back(A[0]);
    for (int i = 1; i < N; i++)
    {
        int place = lower_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if (place == dp.size()) dp.push_back(A[i]);
        else dp[place] = A[i];
    }
    cout << N - dp.size() << endl;
    return 0;
}
