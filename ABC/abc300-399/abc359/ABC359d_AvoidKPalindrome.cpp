#include <algorithm>
#include <atcoder/modint>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

int main() {
    using namespace std;
    using modint = atcoder::static_modint<998244353>;

    unsigned N, K;
    cin >> N >> K;

    // 長さ K の 0/1 文字列のうち、回文でないもの
    // を二進法で表された整数として解釈したもの
    vector<unsigned> not_palindrome;
    for (unsigned i = 0; i < 1U << K; ++i) {
        bool is_palindrome = true;
        for (unsigned j = 0, k = K - 1; j < k; ++j, --k) {
            // 上から見たときと下から見たときで違うビットがあれば
            if ((1 & i >> j) != (1 & i >> k)) {
                // 回文ではない
                is_palindrome = false;
                break;
            }
        }
        // 回文でなければ追加
        if (!is_palindrome)
            not_palindrome.emplace_back(i);
    }

    string S;
    cin >> S;

    vector<modint> dp(1U << K - 1), prev(1U << K - 1);
    { // 先頭 K - 1 文字としてありえるものをすべて列挙する
        // a_mask = 'A' の場所だけ 1 になっているビットマスク
        // q_mask = '?' の場所だけ 0 になっているビットマスク
        unsigned a_mask{}, q_mask{};
        for (const auto c : S | views::take(K - 1)) {
            (a_mask *= 2) += c == 'A';
            (q_mask *= 2) += c != '?';
        }

        // q_mask のビットは常に確定させて、'?' の部分を全探索
        for (unsigned i{q_mask}; i < 1U << K - 1; ++i |= q_mask)
            dp[i ^ a_mask] = 1;
    }

    const unsigned mask{(1U << K - 1) - 1};
    for (const auto c : S | views::drop(K - 1)) {
        swap(dp, prev);
        ranges::fill(dp, modint{});

        // 'A' を追加する場合
        if (c != 'B')
            // 回文でなく、末尾が 'A'(0) であるような場合について遷移する
            for (const auto i : not_palindrome | views::filter([](auto i) { return ~i & 1; }))
                dp[i & mask] += prev[i / 2];

        // 'B' を追加する場合
        if (c != 'A')
            // 回文でなく、末尾が 'B'(1) であるような場合について遷移する
            for (const auto i : not_palindrome | views::filter([](auto i) { return i & 1; }))
                dp[i & mask] += prev[i / 2];
    }

    // すべての接尾辞に対する合計が答え
    cout << reduce(begin(dp), end(dp)).val() << endl;
    return 0;
}


// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <climits>
// #include <set>
// using namespace std;
// typedef long long ll;

// ll N, K;
// ll cur[1009];
// vector<ll> free_place;
// vector<ll> hash_palindol;
// const ll INF = 998244353;

// string S;
// string tmp_S;
// string S_rev;

// // ハッシュ値を計算するための変数 
// long long mod = 1000000007;	// なるべく大きな素数
// long long T[200009];		// 文字列を数に変換するための箱
// long long T_rev[200009];	// 文字列を数に変換するための箱
// long long H[200009];
// long long H_rev[200009];
// long long Power100[200009];

// // S[l,r]のハッシュ値を返す関数
// // あまりの計算に注意！
// long long ft_hash(int l, int r)
// {
// 	long long val = H[r] - (H[l - 1] * Power100[r - l + 1] % mod);
// 	if (val < 0) val += mod;
// 	return val;
// }

// // 逆から読んだ時のハッシュ計算
// long long ft_hash_rev(int l, int r)
// {
// 	long long val = H_rev[r] - (H_rev[l - 1] * Power100[r - l + 1] % mod);
// 	if (val < 0) val += mod;
// 	return val;
// }

// bool ft_pallindol(int start, int end)
// {
// 	// 部分文字列の長さを計算
// 	int length = end - start + 1;
	
// 	// tmp_Sの部分文字列を生成
// 	string sub_S = tmp_S.substr(start - 1, length);
// 	string sub_S_rev = sub_S;
// 	reverse(sub_S_rev.begin(), sub_S_rev.end());

// 	// 文字を数値に変換
// 	for (int i = 1; i <= length; i++) T[i] = (sub_S[i - 1] - 'a') + 1;
// 	for (int i = 1; i <= length; i++) T_rev[i] = (sub_S_rev[i - 1] - 'a') + 1;

// 	// H[1],...,H[length]を計算する
// 	H[0] = 0;
// 	for (int i = 1; i <= length; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;
// 	// 反転版も計算しておく
// 	H_rev[0] = 0;
// 	for (int i = 1; i <= length; i++) H_rev[i] = (100LL * H_rev[i - 1] + T_rev[i]) % mod;
	
// 	// ハッシュ値を比較
// 	long long hash1 = ft_hash(1, length);
// 	long long hash2 = ft_hash_rev(1, length);
// 	return hash1 == hash2;
// }

// int main()
// {
// 	cin >> N >> K >> S;
// 	// 入力しながら、ビットの個数を累積和とる
// 	cur[0] = 0;
// 	for (int i = 0; i < N; i++)
// 	{
// 		if (i > 0) cur[i] = cur[i - 1];
// 		if (S[i] == '?')
// 		{
// 			free_place.push_back(i);
// 			cur[i]++;
// 		}
// 	}
// 	// 100のn乗を前計算しておく
// 	Power100[0] = 1;
// 	for (int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i - 1] % mod;
// 	// ビット全探索
// 	ll ans = 0;
// 	for (int k = 0; k <= N - K; k++)
// 	{
// 		bool tmp = true;
// 		// k ~ k + K の範囲の中に?がいくつあるか
// 		ll num_hatena = cur[k + K - 1];
// 		if (k != 0) num_hatena -= cur[k - 1];
// 		for (int i = 0; i < (1 << num_hatena); i++)
// 		{
// 			tmp_S = S;
// 			ll front_hatena = 0;
			
// 			if (k > 0) front_hatena = cur[k - 1];
// 			for (int j = 0; j < num_hatena; j++)
// 			{
// 				if (i >> j & 1) tmp_S[free_place[front_hatena + j]] = 'A';
// 				else tmp_S[free_place[front_hatena + j]] = 'B';
// 				if (ft_pallindol(k + 1, k + K)) tmp = false;
// 			}
// 		}
// 		if (tmp)
// 		{
// 			ans++;
// 			ans %= INF;
// 		}
// 	}
// 	cout << ans << endl;
// 	return 0;
// }
