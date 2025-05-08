#include <iostream>

using namespace std;

int main()
{
	int N, L;
	int A;
	char B;
	int ans = 0;
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		cin >> A >> B;
		if (B == 'W') ans = max(ans, A);
		else ans = max(ans, L - A);
	}
	cout << ans << endl;
	return 0;
}