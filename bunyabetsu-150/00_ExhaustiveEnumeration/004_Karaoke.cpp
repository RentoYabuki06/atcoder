#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[109][109];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++) cin >> A[i][j];
	}
	long long top_score = 0;
	for (int k = 1; k <= M - 1; k++)
	{
		for (int l = k + 1; l <= M; l++)
		{
			long long total = 0;
			for (int i = 1; i <= N; i++) total += max(A[i][k], A[i][l]);
			top_score = max(top_score, total);
		}
	}
	cout << top_score << endl;
	return 0;
}