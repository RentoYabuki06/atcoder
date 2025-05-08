#include <iostream>

using namespace std;

int main()
{
	int N, Q;
	int A[509][509];
	int row[509];
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) cin >> A[i][j];
		row[i] = i;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		int q, x, y;
		cin >> q >> x >> y;
		if (q == 1)
		{
			swap(row[x], row[y]);
		}
		if (q == 2)
		{
			cout << A[row[x]][y] << endl;
		}
	}
	return 0;
}