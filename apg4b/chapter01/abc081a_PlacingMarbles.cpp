#include <iostream>

using namespace std;

int main()
{
	int s;
	int count = 0;
	cin >> s;
	if (s / 100 == 1)
	{
		count++;
		s %= 100;
	}
	if (s / 10 == 1)
		count++;
	if (s % 10 == 1)
		count++;
	cout << count << endl;
	return 0;
}