#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int total = 0;
	for (int i = 1; i <= 7 * N; i++)
	{
		int tmp;
		cin >> tmp;
		if (i % 7 == 0)
		{
			total += tmp;
			if (!(i == 7)) cout << " ";
			cout << total << endl;
			total = 0;
		}
		else total += tmp;
	}
	return 0;
}