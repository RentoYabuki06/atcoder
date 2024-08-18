#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> cum_mod(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cum_mod[i + 1] = (cum_mod[i] + A[i]) % M;
    }
    ll L = cum_mod[N];
    ll ans = 0;
    vector<ll> cnt(M, 0);
    for (int i = 0; i < N; i++)
    {
        ans += cnt[cum_mod[i]];
        ans += cnt[(cum_mod[i] - L + M) % M];
        cnt[cum_mod[i]]++;
    }
    cout << ans << endl;
    return 0;
}
