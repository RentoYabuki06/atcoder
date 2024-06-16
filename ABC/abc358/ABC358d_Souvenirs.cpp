#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>  // multisetを使用するために追加
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    multiset<int> A_set(A.begin(), A.end());
    long long ans = 0;
    for (int i = 0; i < M; i++)
    {
        // B[i]以上の最小の要素を探す
        auto it = A_set.lower_bound(B[i]);
        if (it == A_set.end())
        {
            cout << -1 << endl;
            return 0;
        }
        ans += *it;
        A_set.erase(it);
    }
    cout << ans << endl;
    return 0;
}
