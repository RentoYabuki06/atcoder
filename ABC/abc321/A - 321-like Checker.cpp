#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N / 10 < 1)
	{
		cout << "Yes" << endl;
		return 0;
	}
	string S = to_string(N);
	for (int i = 1; i < S.size(); i++)
	{
		if (S[i] >= S[i - 1])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}