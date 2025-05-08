#include <iostream>

using namespace std;

int main()
{
	int N, X, Y;
	long long  A;
	cin >> N >> X >> Y;
	int xor_sum = 0;
	int grundy[5] = {0,0,1,1,2};
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		xor_sum = xor_sum ^ grundy[A % 5];
	}

	if (xor_sum == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}