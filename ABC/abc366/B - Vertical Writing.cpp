#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N;
string S[109];
string S_ans[109];

int main()
{
	cin >> N;
	ll M = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
		M = max(M, (ll)S[i].size());
	}

	for (int i = 0; i < M; i++)
	{
		S_ans[i] = "";  // 初期化
		for (int j = 0; j < N; j++)
		{
			if (i >= S[N - j - 1].size()) S_ans[i] += "*";
			else S_ans[i] += S[N - j - 1][i];
		}
		// 末尾のアスタリスクを削除
		while (!S_ans[i].empty() && S_ans[i].back() == '*') {
			S_ans[i].pop_back();
		}
	}

	for (int i = 0; i < M; i++)
	{
		cout << S_ans[i] << endl;
	}
	return 0;
}
