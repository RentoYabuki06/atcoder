#include <iostream>

using namespace std;

int main()
{
	long long  B;
	cin >> B;
	for (int i = 1; i <= 17; i++)
	{
		long long tmp = 1;
		for (int j = 1; j <= i; j++)
		{
			tmp *= i;
		}
		if (tmp == B)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}