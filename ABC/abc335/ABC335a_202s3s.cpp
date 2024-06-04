#include <iostream>

using namespace std;

string S;

int main()
{
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++)
	{
		cout << S[i];
	}
	cout << "4" << endl;
	return 0;
}