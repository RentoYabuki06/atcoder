#include <iostream>

using namespace std;

int N;
int A[1000009], B[1000009], C[1000009], D[1000009];
int dots[1509][1509];

int main()
{
	cin >> N;
	for (int i = 0; i <= 1505; i++)
	{
		for (int j = 0; j <= 1505; j++) dots[i][j] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		dots[A[i]][B[i]]++;
		dots[A[i]][D[i]]--;
		dots[C[i]][B[i]]--;
		dots[C[i]][D[i]]++;
	}
	for (int i = 0; i <= 1505; i++)
	{
		for (int j = 1; j <= 1505; j++) dots[i][j] += dots[i][j - 1];
	}
	for (int j = 0; j <= 1505; j++)
	{
		for (int i = 1; i <= 1505; i++) dots[i][j] += dots[i - 1][j];
	}
	int count = 0;
	for (int i = 0; i <= 1505; i++)
	{
		for (int j = 0; j <= 1505; j++)
		{
			if (dots[i][j] > 0) count++;
		}
	}
	cout << count << endl;
	return 0;
}