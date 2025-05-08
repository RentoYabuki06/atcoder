#include <iostream>

using namespace std;

int main()
{
	int N, X, Y;
	int A[100009];
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// Grundy数を求める
	int grundy[100009];
	for (int i = 0; i <= 100000; i++)
	{
		bool Transit[3] = {false, false, false};
		if (i >= X) Transit[grundy[i-X]] = true;
		if (i >= Y) Transit[grundy[i-Y]] = true;
		if (Transit[0] == false) grundy[i] = 0;
		else if (Transit[1] == false) grundy[i] = 1;
		else grundy[i] = 2;
	}

	int xor_sum = 0;
	for (int i = 1; i <= N; i++) xor_sum = xor_sum ^ grundy[A[i]];
	if (xor_sum == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}