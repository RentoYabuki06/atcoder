#include <iostream>

using namespace std;

int N, Q;
int X[1000009], Y[1000009], a[1000009], b[1000009], c[1000009], d[1000009];
int dots[1509][1509];

int main()
{
	cin >> N;
	for (int i = 0; i <= 1505; i++)
	{
		for (int j = 1; j <= 1505; j++) dots[i][j] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> X[i] >> Y[i];
		dots[X[i]][Y[i]]++;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
	for (int i = 1; i <= 1505; i++)
	{
		for (int j = 1; j <= 1505; j++)
		{
			dots[i][j] += dots[i][j - 1];
		}
	}
	for (int j = 1; j <= 1505; j++)
	{
		for (int i = 1; i <= 1505; i++)
		{
			dots[i][j] += dots[i - 1][j];
		}
	}
	for (int i = 1; i <= Q; i++)
	{
		int sum = dots[c[i]][d[i]] - dots[c[i]][b[i] - 1] - dots[a[i] - 1][d[i]] + dots[a[i] - 1][b[i] - 1];
		cout << sum << endl;
	} 
	return 0;
}