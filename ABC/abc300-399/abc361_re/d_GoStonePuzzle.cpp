#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

int main()
{
	ll N;
	string S, T;
	cin >> N >> S >> T;
	S += "..";
	T += "..";
	// 幅優先探索（bfs）
	map<string, ll> board;
	queue<string> Q;
	board[S] = 0; Q.push(S);
	while (!Q.empty())
	{
		string tmp = Q.front(); Q.pop();
		ll empty_place = 0;
		while (tmp[empty_place] != '.') empty_place++; 
		for (int i = 0; i < N +  1; i++)
		{
			string nex = tmp;
			if (nex[i] == '.' || nex[i + 1] == '.') continue;
			swap(nex[i], nex[empty_place]);
			swap(nex[i + 1], nex[empty_place + 1]);
			if (board.count(nex)) continue;
			board[nex] = board[tmp] + 1;
			Q.push(nex);
		}
	}
	if (board.count(T)) cout << board[T] << endl;
	else cout << -1 << endl;
	return 0;
}