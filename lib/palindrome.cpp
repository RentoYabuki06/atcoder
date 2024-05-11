#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

long long N, Q;
string S;
string S_rev;
long long L[200009];
long long R[200009];

// ハッシュ値を計算するための変数 
long long mod = 1000000007;	// なるべく大きな素数
long long T[200009];		// 文字列を数に変換するための箱
long long T_rev[200009];		// 文字列を数に変換するための箱
long long H[200009];
long long H_rev[200009];
long long Power100[200009];

// S[l,r]のハッシュ値を返す関数
// あまりの計算に注意！
long long ft_hash(int l, int r)
{
	long long val = H[r] -(H[l - 1] * Power100[r - l + 1] % mod);
	if (val < 0) val += mod;
	return val;
}

// 逆から読んだ時のハッシュ計算
long long ft_hash_rev(int l, int r)
{
	long long val = H_rev[r] -(H_rev[l - 1] * Power100[r - l + 1] % mod);
	if (val < 0) val += mod;
	return val;
}

int main()
{
	// 入力
	cin >> N >> Q >> S;
	for (int i = 1; i <= Q; i++) cin >> L[i] >> R[i];
	
	S_rev = S;
	reverse(S_rev.begin(), S_rev.end());

	// 文字を数値に変換
	for (int i = 1; i <= N; i++) T[i] = (S[i - 1] - 'a') + 1;
	for (int i = 1; i <= N; i++) T_rev[i] = (S_rev[i - 1] - 'a') + 1;


	// 100のn乗を前計算しておく
	Power100[0] = 1;
	for (int i = 1; i <= N; i++) Power100[i] = 100LL * Power100[i - 1] % mod;

	// H[1],...,H[N]を計算する
	H[0] = 0;
	for (int i = 1; i <= N; i++) H[i] = (100LL * H[i - 1] + T[i]) % mod;
	// 反転版も計算しておく
	H_rev[0] = 0;
	for (int i = 1; i <= N; i++) H_rev[i] = (100LL * H_rev[i - 1] + T_rev[i]) % mod;
	

	// クエリに答える
	for (int i = 1; i <= Q; i++) {
		long long hash1 = ft_hash(L[i], R[i]);
		long long hash2 = ft_hash_rev(N - R[i] + 1, N - L[i] + 1);
		if (hash1 == hash2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
