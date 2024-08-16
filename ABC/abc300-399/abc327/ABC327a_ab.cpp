#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = 1; i < N; i++)
	{
		if (S[i] == 'a' && S[i - 1] == 'b')
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (S[i] == 'b' && S[i - 1] == 'a')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}