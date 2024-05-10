#include <iostream>

using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	int A[H][W];
	int row[H];
	int column[W];
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < H; i++)
	{
		row[i] = 0;
		for (int j = 0; j < W; j++) row[i] += A[i][j];
	}
	for (int j = 0; j < W; j++)
	{
		column[j] = 0;
		for (int i = 0; i < H; i++) column[j] += A[i][j];
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (j > 0) cout << " ";
			cout << row[i] + column[j] - A[i][j];
		}
		cout << endl;
	}
	return 0;
}