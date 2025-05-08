#include <iostream>

using namespace std;

int N;
int A[110];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (A[i] + A[j] + A[k] == 1000 && i != j && i != k && j != k)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}