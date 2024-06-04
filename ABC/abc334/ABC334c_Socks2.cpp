#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K;
int A[200009];
long long pre_cum_sum[200009];
long long suf_cum_sum[200009];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= K; i++) cin >> A[i];
    vector<int> socks;
    for (int i = 1; i <= K; i++) socks.push_back(A[i]);
    sort(socks.begin(), socks.end());
    for (int i = 0; i < K; i++) A[i] = socks[i];

    // 前から累積和
    pre_cum_sum[0] = 0;
    for (int i = 1; i <= K; i++) {
        pre_cum_sum[i] = pre_cum_sum[i - 1];
        if (i % 2 == 0) pre_cum_sum[i] += A[i - 1] - A[i - 2];
    }

	// 後ろから累積和
    suf_cum_sum[K] = 0;
    for (int i = K - 1; i >= 0; i--) {
        suf_cum_sum[i] = suf_cum_sum[i + 1];
        if ((K - i) % 2 == 0) suf_cum_sum[i] += A[i + 1] - A[i];
    }

    long long ans = 1e9;
    for (int i = 0; i <= K; i += 2) {
        ans = min(ans, pre_cum_sum[i] + suf_cum_sum[i]);
    }
    cout << ans << endl;
    return 0;
}
