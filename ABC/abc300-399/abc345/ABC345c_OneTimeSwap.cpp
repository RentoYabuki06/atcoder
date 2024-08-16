#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	long long alphabet[26];
	for (int i = 0; i < 26; i++) alphabet[i] = 0;
	// 全て異なるアルファベットだった場合の組み合わせ数
	long long ans = S.size() * S.size();
	// アルファベットの出現回数を数える
	for (int i = 0; i < S.size(); i++) alphabet[S[i] - 'a']++;
	bool flg = false;
	for (int i = 0; i < 26; i++)
	{
		ans -= alphabet[i] * alphabet[i];
		if (alphabet[i] >= 2) flg = true;
	}
	ans /= 2;
	if (flg) ans += 1;
	cout << ans << endl;
	return 0;
}