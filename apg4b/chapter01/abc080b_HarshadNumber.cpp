#include <iostream>

using namespace std;

int main()
{
	int N, n;
	cin >> N;
	n = N;
	int sum = 0;
	while (1)
	{
		sum += N % 10;
		N /= 10;
		if (N == 0)
			break;
	}
	if (n % sum == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}