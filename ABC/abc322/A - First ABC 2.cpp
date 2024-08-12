#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N < 3)
	{
		cout << -1 << endl;
		return 0;
	}
	string S;
	cin >> S;
	for (int i = 2; i < S.size(); i++)
	{
		if (S[i] == 'C' && S[i - 1] == 'B' && S[i - 2] == 'A')
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}