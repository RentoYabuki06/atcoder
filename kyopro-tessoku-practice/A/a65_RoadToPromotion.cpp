#include <iostream>
#include <vector>

using namespace std;

int N;
int A[100009];
int dp[100009];
vector<int> Graph[100009];

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++)
	{
		cin >> A[i];
		Graph[A[i]].push_back(i);
	}
	for (int i = N; i > 0; i--)
	{
		dp[i] = 0;
		for (int j = 0; j < Graph[i].size(); j++) dp[i] += (dp[Graph[i][j]] + 1);
	}
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		cout << dp[i];
	}
	cout << endl;
	return 0;
}