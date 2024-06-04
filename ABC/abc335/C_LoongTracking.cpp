#include <iostream>
#include <deque>

using namespace std;

int N, Q, tmp;
deque<pair<int, int>> dragon;
int query_num;
char query_char;

int main()
{
	// 入力
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		dragon.push_back(make_pair(i, 0));
	}
	int move_count = N;
	for (int i = 1; i <= Q; i++)
	{
		cin >> query_num;
		if (query_num == 1)
		{
			move_count++;
			cin >> query_char;
			auto x = dragon[0].first;
			auto y = dragon[0].second;
			if (query_char == 'R') dragon.push_front(make_pair(x+1, y));
			else if (query_char == 'L') dragon.push_front(make_pair(x-1, y));
			else if (query_char == 'U') dragon.push_front(make_pair(x, y+1));
			else dragon.push_front(make_pair(x, y-1));
		}
		else
		{
			cin >> tmp;
			cout << dragon[tmp - 1].first << " " << dragon[tmp - 1].second << endl;
		}
	}
	return 0;
}