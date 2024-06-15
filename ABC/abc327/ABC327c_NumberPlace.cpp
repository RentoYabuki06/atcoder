#include <iostream>

using namespace std;

int main()
{
	int A[10][10];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) cin >> A[i][j];
	}
	// 重複チェック
	bool check_row[10][10];
	bool check_column[10][10];
	bool check_box[10][10];
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			check_column[i][j] = false;
			check_row[i][j] = false;
			check_box[i][j] = false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int num = A[i][j];
			int k = (i / 3) * 3 + (j / 3);
			if (check_column[i][num] || check_row[j][num] || check_box[k][num])
			{
				cout << "No" << endl;
				return 0;
			}
			check_column[i][num]= true;
			check_row[j][num] = true;
			check_box[k][num] = true;
		}
	}
	cout << "Yes" << endl;
	return 0;
}