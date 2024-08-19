#include <iostream>

using namespace std;

int main()
{
	int S[8];
	for (int i = 0; i < 8; i++) cin >> S[i];
	for (int i = 0; i < 8; i++)
	{
		if (!(S[i] % 25 == 0))
		{
			cout << "No" << endl;
			return 0;
		}
		if (i == 0) continue;
		if (S[i] < S[i - 1])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	if (S[0] < 100 || S[7] > 675)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}