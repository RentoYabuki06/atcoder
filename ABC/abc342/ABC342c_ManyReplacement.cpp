#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, Q;
string S;
char C[109];
char D[109];
char Alpha[26];

int main()
{
	// 入力
	cin >> N >> S >> Q;
	// 初期化
	for (int i = 0; i < 26; i++) Alpha[i] = i + 'a';
	// どの文字がどの文字に置き換わるかを記録
	for (int i = 1; i <= Q; i++)
	{
		cin >> C[i] >> D[i];
		for (int j = 0; j < 26; j++)
		{
			if (Alpha[j] == C[i])
			{
				Alpha[j] = D[i];
			}
		}
	}
	// 出力
	for (int i = 0; i < N; i++)
	{
		cout << Alpha[S[i] - 'a'];
	}
	cout << endl;
	return 0;
}