#include <iostream>
#include <string>

using namespace std;
const long long MOD = 998244353;

// 繰り返し二乗法を使って (base^exp) % mod を計算する関数
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    string N_str;
    cin >> N_str;
    long long N = stoll(N_str);

    // N の桁数を計算
    int length = N_str.length();

    // 10^length を計算
    long long ten_pow_len = mod_exp(10, length, MOD);

    // (10^(length * N) - 1) を計算
    long long ten_pow_len_N = mod_exp(ten_pow_len, N, MOD);
    long long numerator = (ten_pow_len_N - 1 + MOD) % MOD;  // 負数にならないように調整

    // (10^length - 1) を計算
    long long denominator = (ten_pow_len - 1 + MOD) % MOD;  // 負数にならないように調整

    // 分母の逆元を計算
    long long denominator_inv = mod_exp(denominator, MOD - 2, MOD);

    // V_N の余りを計算
    long long result = (N % MOD * numerator % MOD) * denominator_inv % MOD;

    cout << result << endl;

    return 0;
}
