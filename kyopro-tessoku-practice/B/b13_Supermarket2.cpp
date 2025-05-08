#include <iostream>

using namespace std;

int N, K, A[100009], cum[100009], R[100009];
long long ans = 0;

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cum[1] = A[1];
	for (int i = 2; i <= N; i++) cum[i] = cum[i - 1] + A[i];
	for (int i = 1; i <= N - 1; i++)
	{
		if (i == 1) R[i] = 0;
		else R[i] = R[i - 1];
		while (R[i] < N && cum[R[i] + 1] - cum[i - 1] <= K) R[i]++;
		ans += R[i] - i + 1;
	}
	if (A[N] <= K) ans++;
	cout << ans << endl;
	return 0;
}