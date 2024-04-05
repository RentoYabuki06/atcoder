#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int H ,W;
	cin >> H >> W;
	vector<string> board(H);
	for (int i = 0; i < H; i++)
	{
		string S;
		cin >> S;
		board.at(i) = S;
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board.at(i).at(j) == '.')
			{
				int count = 0;
				if (i != 0)
				{
					if (j != 0)
					{
						if (board.at(i - 1).at(j - 1) == '#')
							count++;
					}
					if (board.at(i - 1).at(j) == '#')
						count++;
					if (j != W - 1)
					{
						if (board.at(i - 1).at(j + 1) == '#')
							count++;
					}
				}
				if (i != H - 1)
				{
					if (j != 0)
					{
						if (board.at(i + 1).at(j - 1) == '#')
							count++;
					}
					if (j != W - 1)
					{
						if (board.at(i + 1).at(j + 1) == '#')
							count++;
					}
					if (board.at(i + 1).at(j) == '#')
						count++;
				}
				if (j != W -1)
				{
					if (board.at(i).at(j + 1) == '#')
						count++;
				}
				if (j != 0)
				{
					if (board.at(i).at(j - 1) == '#')
						count++;
				}
				board.at(i).at(j) = count + '0';
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		cout << board.at(i) << endl;
	}
	return 0;
}