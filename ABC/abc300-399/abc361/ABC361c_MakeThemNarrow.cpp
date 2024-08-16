#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll N, K;

int main()
{
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    // K要素を削除した後のサイズ
    ll remaining = N - K;

    ll min_diff = A[remaining - 1] - A[0];
    for (int i = 1; i + remaining - 1 < N; i++) {
        ll diff = A[i + remaining - 1] - A[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    cout << min_diff << endl;
    return 0;
}
