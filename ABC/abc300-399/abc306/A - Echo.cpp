#include <iostream>

using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cout << S[i] << S[i];
	}
	cout << endl;
	return 0;
}