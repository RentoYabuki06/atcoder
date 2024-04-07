#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	H, W, N, x,y, point, tmp, tmp_point;
// vector<vector<int>> point_place;
int start_col, start_row, goal_col, goal_row;
vector<vector<int>> num_board; 

bool	isValid(int row, int col)
{
	if (row >= 0 && row < H && col >= 0 && col < W)
	{
		if (num_board[row][col] > 0 && point > 0)
		{
			return true;
		}
	}
	return false;
}

bool	search(int row, int col)
{
	if (row == goal_row && col == goal_col)
		return true;
	for (int i = 0; i < 4; i++)
	{
		tmp = num_board[row][col];
		tmp_point = point;
		if (point < num_board[row][col])
			point = num_board[row][col];
		num_board[row][col] = 0;
		point--;
		if (i == 0)
			row += 1;
		if (i == 1)
			row -= 1;
		if (i == 2)
			col += 1;
		if (i == 3)
			col -= 1;
		if (isValid(row, col))
		{
			if(search(row,col))
				return true;
		}
		if (i == 0)
			row -= 1;
		if (i == 1)
			row += 1;
		if (i == 2)
			col -= 1;
		if (i == 3)
			col += 1;
		num_board[row][col] = tmp;
		point = tmp_point;
	}
}

int	main()
{
	cin >> H >> W;

	vector<string> board(H);
	for (int i = 0; i < H; i++)
	{
		cin >> board.at(i);
	}
	num_board.resize(H, vector<int>(W));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j]=='.')
			{
				num_board[i][j] = 1;
			}
			if (board[i][j]=='#')
			{
				num_board[i][j] = -1;
			}
			if (board[i][j]=='S')
			{
				start_col = j;
				start_row = i;
			}
			if (board[i][j]=='T')
			{
				goal_col = j;
				goal_row = i;
			}
		}
	}
	cin >> N;
	// point_place.resize(N, 3);
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> point;
		num_board[y][x] == point;
	}
	point = 0;
	if (search(start_row, start_col) == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}