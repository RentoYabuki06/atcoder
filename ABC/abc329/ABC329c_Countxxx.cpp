#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	// アルファベットごとに何通り存在するかカウント
	int alpha[26];
	char current_alpha = S[0];
	int current_num = 1;
	alpha[current_alpha - 'a'] = 1;
	for (int i = 1; i < N; i++)
	{
		if (current_alpha != S[i])
		{
			alpha[current_alpha - 'a'] = max(alpha[current_alpha - 'a'], current_num);
			current_num = 0;
			current_alpha = S[i];
		}
		current_num++;
		alpha[current_alpha - 'a'] = max(alpha[current_alpha - 'a'], current_num);
	}

	// 総通り数を合計して出力
	long long ans = 0;
	for (int i = 0; i < 26; i++) ans += alpha[i];
	cout << ans << endl;
	return 0;
}
