#include <iostream>

using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	bool flag_a = false;
	bool flag_b = false;
	bool flag_c = false;
	for (int i = 0; i < N; i++)
	{
		if (S[i] == 'A') flag_a = true;
		else if (S[i] == 'B') flag_b = true;
		else if (S[i] == 'C') flag_c = true;
		if (flag_a && flag_b && flag_c)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}