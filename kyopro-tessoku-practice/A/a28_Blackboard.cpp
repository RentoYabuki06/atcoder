#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	long long A[100009];
	char T[100009];
	for (int i = 1; i <= N; i++) cin >> T[i] >> A[i];
	long long ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (T[i] == '+') ans += A[i];
		if (T[i] == '-') ans -= A[i];
		if (T[i] == '*') ans *= A[i];
		if (ans < 10000) ans += 10000;
		ans %= 10000;
		cout << ans % 10000 << endl;
	}
	return 0;
}