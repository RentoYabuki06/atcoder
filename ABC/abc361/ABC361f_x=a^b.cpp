#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

// nまでの整数で、x^b乗の形で記述できるものの数を求める
ll calc(int b, ll n) {
    ll ac = 0;      // ac：ac^b <= nを満たす最大の整数
    ll wa = n + 1;  // wa：wa^b > nを満たす最小の整数
    // acとwaが隣接するまで2分探索を回す
    while (ac + 1 < wa) {
        ll mid = (ac + wa) / 2;
        bool judge = true;  // judge：mid^b <= n を判定するためのフラグ
        ll x = 1;
        for (int i = 0; i < b; ++i) {
            // オーバーフロー対策
            if (n / x < mid) {
                judge = false;
                break;
            }
            x *= mid;
        }
        if (judge && x <= n) {
            ac = mid;
        } else {
            wa = mid;
        }
    }
    // 今回1乗はカウントしないので1引く
    return ac - 1;
}

int main() {
    ll n;
    cin >> n;

    const int M = 60;
    vector<ll> f(M, 0);
    ll ans = 1;
    // 60乗までを全探索
    for (int b = M - 1; b >= 2; b--) {
        f[b] = calc(b, n);
        // 重複削除：上位の累乗で求められた数を引く
        for (int i = b * 2; i < M; i += b) {
            f[b] -= f[i];
        }
        ans += f[b];
    }
    
    cout << ans << endl;
    return 0;
}
