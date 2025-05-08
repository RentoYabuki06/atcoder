#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int Q, X[10009];

int main ()
{
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> X[i];
	for (int j = 1; j <= Q; j++)
	{
		if (X[j] < 2)
		{
			cout << "No" << endl;
		}
		else
		{
			int flag = 1;
			for (int i = 2; i <= X[j] / i; i++)
			{
				if (X[j] % i == 0)
				{
					cout << "No" << endl;
					flag = -1;
					break;
				}
			}
			if (flag == 1)
				cout << "Yes" << endl;
		}
	}
	return 0;
}