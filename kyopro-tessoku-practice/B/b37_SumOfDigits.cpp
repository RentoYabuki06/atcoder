#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long power = 1;
    long long ans = 0;
    long long accu = 0;

    while (power <= N) {
        long long digit = ((N % (power * 10)) - (N % power)) / power;
        if (digit > 0) {
            ans += accu * digit;
            ans += digit * (N % power + 1);
            while (digit > 1) {
                digit--;
                ans += digit * power;
            }
        }
        accu = accu * 10 + 45 * power;
        power *= 10;
    }

    cout << ans << endl;
    return 0;
}