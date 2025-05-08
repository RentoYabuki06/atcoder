#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	long long A[10000009];
	A[1] = 1;
	A[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		A[i] = A[i - 1] + A[i - 2];
		A[i] %= 1000000007;
	}
	cout << A[N] % 1000000007 << endl;
	return 0;
}