#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

ll N, D;
const ll M = 1000000;

// コメントはx座標で記述しているが、y座標についても処理は同じ
vector<ll> calc(vector<ll>& xs)
{
    sort(xs.begin(), xs.end());
    vector<ll> xsum(2 * M + 2, 0);
    ll i = 0;
    // 一番左の点を選んだ場合の合計距離を計算
    xsum[0] = accumulate(xs.begin(), xs.end(), 0) + N * M;
    // 1座標ずつ右にずらしながら合計距離を計算
    for (ll x = 1; x <= 2 * M + 1; x++)
    {
        // 現在のx座標(x-M)より左側にある点の数iを数える
        while (i < N && xs[i] < x - M) i++;
        // x座標がxの時はx-1の時の合計の距離に2i-Nを足す
        // i個の要素は離れていき＜+i＞、N-i個は近づく＜-(N-i)＞ため
        xsum[x] = xsum[x - 1] + 2 * i - N;
    }
    return xsum;
}

int main()
{
    // 入力
    cin >> N >> D;
    vector<ll> x(N), y(N);
    for (ll i = 0; i < N; i++) cin >> x[i] >> y[i];
    // x, y軸それぞれについて処理を実行
    vector<ll> xsum = calc(x);
    vector<ll> ysum = calc(y);
    
    sort(xsum.begin(), xsum.end());
    sort(ysum.begin(), ysum.end());
    
    ll ans = 0;
    ll j = 2 * M;
    for (ll i = 0; i <= 2 * M; i++)
    {
        // xは小さい方、yは大きい方から足し合わせ（そのために上でソートしている）
        while (j >= 0 && xsum[i] + ysum[j] > D) j--;
        ans += j + 1;
    }
    cout << ans << endl;
    return 0;
}
