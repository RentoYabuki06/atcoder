#include <iostream>

using namespace std;

int main()
{
	int N , X;
	cin >> N >> X;
	int S[10];
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		if (S[i] <= X) ans += S[i];
	}
	cout << ans << endl;
	return 0;
}