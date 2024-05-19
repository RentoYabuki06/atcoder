#include <iostream>

using namespace std;

int T;
int N;
int A[200009];
int dp[100009];


int main()
{
	cin >> T;
	for (int k = 1; k <= T; k++)
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
	}
	return 0;
}