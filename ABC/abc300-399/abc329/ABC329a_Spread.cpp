#include <iostream>

using namespace std;

int main()
{
	string S;
	cin >> S;
	for (int i = 0; i< S.size(); i++)
	{
		if (i > 0) cout << " ";
		cout << S[i];
	}
	cout << endl;
	return 0;
}