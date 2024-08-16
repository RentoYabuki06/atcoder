#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == 'a' || S[i] == 'i' || S[i] == 'u' || S[i] == 'e' || S[i] == 'o') continue;
		else cout << S[i];
	}
	cout << endl;
	return 0;
}