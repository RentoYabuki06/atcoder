#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, K;

int main()
{
    cin >> N >> K;
    deque<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; i < K; i++)
    {
        // AのサイズがN - iであることに注意して範囲を確認する
        if (A[1] - A[0] > A[A.size() - 1] - A[A.size() - 2])
            A.pop_front();
        else
            A.pop_back();
    }

    // K個の要素を削除した後のサイズを考慮して、残りの要素を扱う
    cout << A.back() - A.front() << endl;
    return 0;
}
