#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string S;

int main()
{
	cin >> S;
	if (!isupper(S[0]))
	{
		cout << "No" << endl;
		return 0;
	}
	for (int i = 1; i < S.size(); i++)
	{
		if (!islower(S[i]))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}