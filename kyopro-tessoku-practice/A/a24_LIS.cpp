#include <iostream>

using namespace std;

int N, A[100009];
int dp[100009];


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int top = 1;
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			dp[1] = A[1];
		}
		else
		{
			if (dp[top] < A[i])
			{
				dp[top + 1] = A[i];
				top += 1;
			}
			else
			{
				int l = 1, r = top;
				while (l < r)
				{
					int mid = (l + r) / 2;
					if (dp[mid] < A[i])
					{
						l = mid + 1;
					}
					else
					{
						r = mid;
					}
				}
				dp[l] = A[i];
			}
		}
	}
	cout << top << endl;
	return 0;
}

// //何も考えずに動的計画法したら間に合わなかった
// int main()
// {
// 	cin >> N;
// 	for (int i = 1; i <= N; i++) cin >> A[i];
// 	for (int i = 1; i <= N; i++)
// 	{
// 		dp[i] = 1;
// 		for (int j = 1; j < i; j++)
// 		{
// 			if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
// 		}
// 	}
// 	int ans = 1;
// 	for (int i = 1; i <= N; i++) ans = max(ans, dp[i]);
// 	cout << ans << endl;
// 	return 0;
// }
