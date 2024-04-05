#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x < K - x)
		{
			sum += x * 2;
		}
		else{
			sum += (K - x) * 2;
		}
	}
	cout << sum << endl;
	return 0;
}