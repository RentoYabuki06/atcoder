#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int N ,M;
int A[109];
int X[109][109];
int dp[109];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> X[i][j];
			dp[j] += X[i][j];
		}
	}
	for (int j = 1; j <= M; j++)
	{
		if (dp[j] < A[j])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}