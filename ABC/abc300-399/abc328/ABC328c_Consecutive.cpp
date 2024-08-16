#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> dp(N + 1, 0); 
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1];
        if (S[i] == S[i - 1]) {
            dp[i]++;
        }
    }
    dp[N] = dp[N - 1];
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
		// 0インデックスに変更
        l--;
        r--;
        int result = dp[r] - dp[l];
        cout << result << endl;
    }
    return 0;
}
