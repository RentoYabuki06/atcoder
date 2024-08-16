#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		if (i % 2 == 1 && i < 16 && S[i] == '1')
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}