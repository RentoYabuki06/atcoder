#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= N; k++)
			{
				if (i + j + k > N) continue;
				cout << i << " " << j << " " << k << endl;
			}
		}
	}
	return 0;
}