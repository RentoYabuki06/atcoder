#include <iostream>

using namespace std;

int main()
{
	int N, A, B;
	cin >> N >> A >> B;

	bool dp[100009];
	for (int i = 1; i <= N; i++)
	{
		if (i > A && dp[i - A] == false) dp[i] = true;
		else if (i > B && dp[i - B] == false) dp[i] = true;
		else dp[i] = false;
	}
	// 結果の出力
	if (dp[N] == true) cout << "First" << endl;
	else cout << "Second" << endl;
	return 0;
}