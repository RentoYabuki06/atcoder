#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N, K;
	int A[309], B[309];
	int max_member[109][109];
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++) max_member[i][j] = 0;
	}
	for (int i = 1; i <= 100 - K; i++)
	{
		for (int j = 1; j <= 100 - K; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if ((i <= A[k] && A[k] <= i + K) && (j <= B[k] && B[k] <= j + K))
					max_member[i][j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 100 - K; i++)
	{
		for (int j = 1; j <= 100 - K; j++)
		{
			ans = max(ans, max_member[i][j]);
			// //検証よう
			// cout << max_member[i][j] << " ";
		}
	}
	cout << ans << endl;
	return 0;
}