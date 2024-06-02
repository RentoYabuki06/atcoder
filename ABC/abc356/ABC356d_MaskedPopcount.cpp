#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

const long long MOD = 998244353;

int popcount(long long x) {
    return __builtin_popcountll(x);
}

int main() {
    long long N, M;
    cin >> N >> M;

    long long ans = 0;

    // ビットごとに処理
    for (int bit = 0; bit < 60; bit++) {
        // 2^bit のブロックサイズ
        long long block_size = 1LL << bit;

        // 1の出現回数を計算
        long long full_blocks = (N + 1) / block_size;
        long long remainder = (N + 1) % block_size;

        long long count_ones = (full_blocks / 2) * block_size;
        if (full_blocks % 2 == 1) {
            count_ones += remainder;
        }

        if (M & (1LL << bit)) {
            ans = (ans + count_ones) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
