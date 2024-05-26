# include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	if (A == B) cout << -1 << endl;
	else
	{
		if (A == 1 || B == 1)
		{
			if (A == 2 || B == 2) cout << 3 << endl;
			else cout << 2 << endl;
		}
		else cout << 1 << endl;
	}
	return 0;
}