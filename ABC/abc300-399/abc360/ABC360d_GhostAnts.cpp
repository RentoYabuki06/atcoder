#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, T;
string S;
ll X[200009];
vector<ll> left_ants, right_ants;

int main()
{
    // 入力
    cin >> N >> T >> S;
    for (int i = 0; i < N ; i++)
    {
        cin >> X[i];
        if (S[i] == '0') left_ants.push_back(X[i]);
        else right_ants.push_back(X[i]);
    }
    
    // ソート
    sort(left_ants.begin(), left_ants.end());
    sort(right_ants.begin(), right_ants.end());

    // 答えを求める
    ll ans = 0;
    for (ll x : right_ants)
    {
        // 左向きの蟻とのすれ違いをカウント
        ans += lower_bound(left_ants.begin(), left_ants.end(), x + 2 * T + 0.1) - lower_bound(left_ants.begin(), left_ants.end(), x);
    }

    cout << ans << endl;
    return 0;
}
