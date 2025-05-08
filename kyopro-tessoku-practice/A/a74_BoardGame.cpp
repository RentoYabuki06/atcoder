#include <iostream>

using namespace std;

int N;
int P[109][109];
int row[109];
int column[109];

int main()
{
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> P[i][j];
			if (P[i][j] != 0)
			{
				row[i] = P[i][j];
				column[j] = P[i][j];
			}
		}
	}
	// バブルソートの必要回数をカウント
	int count_sort = 0;
	// rowの並び替え
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (row[j] > row[j + 1])
			{
				count_sort++;
				int tmp = row[j];
				row[j] = row[j + 1];
				row[j + 1] = tmp;
			}
		}
	}
	// columnの並び替え
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (column[j] > column[j + 1])
			{
				count_sort++;
				int tmp = column[j];
				column[j] = column[j + 1];
				column[j + 1] = tmp;
			}
		}
	}
	cout << count_sort << endl;
	return 0;
}