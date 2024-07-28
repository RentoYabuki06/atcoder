#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, Q;
vector<ll> A;

bool    ft_check_binary_search(ll b, ll k, ll x)
{
    ll R_num = lower_bound(A.begin(), A.end(), b + x + 1) - A.begin();
    ll L_num = lower_bound(A.begin(), A.end(), b - x) - A.begin();
    return (R_num - L_num >= k);
}

int main()
{
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    // クエリの実行
    while (Q--)
    {
        ll b, k;
        cin >> b >> k;
        // -1だと絶対に存在しない、10^8だと絶対にk個以上存在する
        ll low = -1;
        ll high = 2e8;
        while (high - low > 1)
        {
            ll mid = low + (high - low) / 2;
            if (ft_check_binary_search(b, k, mid)) high = mid;
            else low = mid;
        }
        cout << high << endl;
    }
    return 0;
}
