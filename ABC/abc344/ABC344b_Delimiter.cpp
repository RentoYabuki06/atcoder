#include <iostream>

using namespace std;

int A[109];

int main()
{
	int i = 0;
	while (true)
	{
		cin >> A[i];
		if (A[i] == 0)
			break;
		i++;
	}
	while (i >= 0)
	{
		cout << A[i] << endl;
		i--;
	}
}