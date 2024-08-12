#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	string S, T;
	cin >> N >> S >> T;
	S += "..";
	T += "..";
	map<string, ll> board;
	queue<string> Q;
	board[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		ll index = 0;
		string tmp = Q.front();
		Q.pop();
		while(tmp[index] != '.') index++;
		for (int i = 0; i < N + 1; i++)
		{
			if (tmp[i] == '.' || tmp[i + 1] == '.') continue;
			string nex = tmp;
			swap(nex[i], nex[index]);
			swap(nex[i + 1], nex[index + 1]);
			if (board.count(nex)) continue;
			board[nex] = board[tmp] + 1;
			Q.push(nex);
		}
	}
	if (board.count(T)) cout << board[T] << endl;
	else cout << -1 << endl;
	return 0;
}