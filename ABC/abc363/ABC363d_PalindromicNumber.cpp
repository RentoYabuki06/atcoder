#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
typedef long long ll;

ll N;
ll power10[19]; // 配列名を変更

void initialize_power10() {
    power10[0] = 1;
    for (int i = 1; i < 19; ++i) {
        power10[i] = power10[i - 1] * 10;
    }
}

string generate_palindrome(ll num, bool is_odd_length) {
    string half = to_string(num);
    string palindrome = half;
    if (is_odd_length) half.pop_back();
    reverse(half.begin(), half.end());
    palindrome += half;
    return palindrome;
}

int main() {
    cin >> N;
    initialize_power10();

    ll count = 10; // 1桁の回文数は9個 (0, 1, 2, ..., 9)
    if (N <= count) {
        cout << N - 1 << endl;
        return 0;
    }

    // N番目の回文数を探す
    for (int length = 2; ; length++) {
        ll half_length = (length + 1) / 2;
        ll start = power10[half_length - 1];
        ll end = power10[half_length];
        ll range_size = end - start;

        if (N <= count + range_size) {
            ll num = start + (N - count - 1);
            cout << generate_palindrome(num, length % 2 == 1) << endl;
            return 0;
        }

        count += range_size;
    }

    return 0;
}
