#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	int i = 0;
	if (S[i] != '<')
	{
		cout << "No" << endl;
		return 0;
	}
	i++;
	while (i < S.size() && S[i] == '=') i++;
	if (S[i] != '>' || i != S.size() - 1)
	{
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}