#include <iostream>

using namespace std;

int main()
{
	int N, L;
	cin >> N >> L;
	int A[109];
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (A[i] >= L) ans++;
	}
	cout << ans << endl;
	return 0;
}