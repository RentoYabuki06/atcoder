#include <iostream>
#include <vector>

using namespace std;

int N, M;
int A[200009], B[200009];
vector<vector<int>> dp(200009);

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> A[i] >> B[i];
		dp[A[i]].push_back(B[i]);
	}
}