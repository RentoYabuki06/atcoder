#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	for (int x = A; x <= B; x++)
	{
		if (100 % x == 0)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}