#include <iostream>
#include <string>

using namespace std;

int main()
{
	string S;
	cin >> S;
	char c = S[0];
	if (S[1] != c)
	{
		if (S[2] == c)
		{
			cout << 2 << endl;
			return 0;
		}
		else
		{
			cout << 1 << endl;
			return 0;
		}
	}
	for (int i = 2; i < S.size(); i++)
	{
		if (S[i] != c)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}