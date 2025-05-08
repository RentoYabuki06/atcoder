#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((K - (i + j + 2)) > 0 && (K - (i + j + 2)) <= N)
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}