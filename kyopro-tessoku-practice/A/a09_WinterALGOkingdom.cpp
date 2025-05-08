#include <iostream>

using namespace std;

int H, W, N;
int A[1000009], B[1000009], C[1000009], D[1000009];
int dots[1509][1509];

int main()
{
	cin >> H >> W >> N;
	for (int i = 0; i <= 1505; i++)
	{
		for (int j = 0; j <= 1505; j++) dots[i][j] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
		dots[A[i]][B[i]]++;
		dots[A[i]][D[i] + 1]--;
		dots[C[i] + 1][B[i]]--;
		dots[C[i] + 1][D[i] + 1]++;
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++) dots[i][j] += dots[i][j - 1];
	}
	for (int j = 1; j <= W; j++)
	{
		for (int i = 1; i <= H; i++) dots[i][j] += dots[i - 1][j];
	}
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (j > 1) cout << " ";
			cout << dots[i][j];
		}
		cout << endl;
	}
	return 0;
}