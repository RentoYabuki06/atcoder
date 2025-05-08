#include <iostream>
#include <algorithm>

using namespace std;

int  N, K, A[1009], B[1009], C[1009], D[1009], AB[1000009], CD[1000009];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1; i <= N; i++) cin >> C[i];
	for (int i = 1; i <= N; i++) cin >> D[i];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			AB[(i - 1) * N + j] = A[i] + B[j];
			CD[(i - 1) * N + j] = C[i] + D[j];
		}	
	}
	sort(CD + 1, CD + N * N + 1);
	for (int i = 1; i <= N * N; i++)
	{
		int pos = lower_bound(CD + 1, CD + N * N + 1, K - AB[i]) - CD;
		if (pos <= N * N && CD[pos] == K - AB[i])
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}