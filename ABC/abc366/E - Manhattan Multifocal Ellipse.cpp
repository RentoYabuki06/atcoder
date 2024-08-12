#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

ll N, D;
const ll M = 2000000;

vector<ll> calc(vector<ll>& xs) {
    vector<ll> xsum(2 * M + 2, 0);
    sort(xs.begin(), xs.end());
    ll i = 0;
    xsum[0] = accumulate(xs.begin(), xs.end(), 0) + N * M;
    for (ll x = 1; x <= 2 * M + 1; x++) {
        while (i < N && xs[i] < x - M) {
            i++;
        }
        xsum[x] = xsum[x - 1] + 2 * i - N;
    }

    return xsum;
}

int main() {
    cin >> N >> D;
    vector<ll> x(N), y(N);
    for (ll i = 0; i < N; i++) cin >> x[i] >> y[i];
    
    vector<ll> xsum = calc(x);
    vector<ll> ysum = calc(y);
    
    sort(xsum.begin(), xsum.end());
    sort(ysum.begin(), ysum.end());
    
    ll ans = 0;
    ll j = 2 * M;

    for (ll i = 0; i <= 2 * M; i++) {
        while (j >= 0 && xsum[i] + ysum[j] > D) {
            j--;
        }
        ans += j + 1;
    }
    
    cout << ans << endl;
    
    return 0;
}
