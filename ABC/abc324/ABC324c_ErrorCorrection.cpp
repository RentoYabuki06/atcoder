#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	string T;
	cin >> N >> T;
	vector<string> S(N);
	for (int i = 0; i < N; i++) cin >> S[i];
	for (int i = 0; i < N; i++)
	{
		if (S[i] == T || )
		{
			if (i > 0) cout << " ";
			cout << i;
		}
	}
	cout << "Yes" << endl;
	return 0;
}