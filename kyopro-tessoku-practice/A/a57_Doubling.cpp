#include <iostream>

using namespace std;

int N, Q;
int A[100009];
int X[100009];
int Y[100009];
int dp[32][100009];		// 制約が10^9なので2^10=1024より、2^30あれば十分

int main()
{
	// 入力
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= Q; i++) cin >> X[i] >> Y[i];
	// 前もって計算しておく
	for (int i = 1; i <= N; i++) dp[0][i] = A[i];
	for (int d = 1; d <= 30; d++)
	{
		for (int i = 1; i <= N; i++) dp[d][i] = dp[d - 1][dp[d - 1][i]];
	}
	// クエリの処理
	for (int i = 1; i <= Q; i++)
	{
		int pos = X[i];
		for (int d = 30; d >= 0; d--)
		{
			if ((Y[i] >> d) & 1) pos = dp[d][pos];
		}
		cout << pos << endl;
	}
	return 0;
}