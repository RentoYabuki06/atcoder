#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = N; i <= 919; i++)
	{
		int d1 = i / 100;
		int d2 = (i - 100 * d1) / 10;
		int d3 = i % 10;
		if (d1 * d2 == d3)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}