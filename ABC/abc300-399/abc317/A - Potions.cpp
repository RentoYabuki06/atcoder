#include <iostream>

using namespace std;

int main()
{
	int N, H, X;
	cin >> N >> H >> X;
	int P[N];
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++)
	{
		if (P[i] + H >= X)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}