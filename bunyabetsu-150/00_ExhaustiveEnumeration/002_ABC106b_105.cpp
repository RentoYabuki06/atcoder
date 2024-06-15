#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i += 2)
	{
		int divisors = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0) divisors++;
		}
		if (divisors == 8) count++;
	}
	cout << count << endl;
	return 0;
}