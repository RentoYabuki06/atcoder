#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char S;
		cin >> S;
		if (S == 'Y')
		{
			cout << "Four" << endl;
			return 0;
		}
	}
	cout << "Three" << endl;
	return 0;
}