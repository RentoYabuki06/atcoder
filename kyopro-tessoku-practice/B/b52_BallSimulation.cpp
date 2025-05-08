#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N , X;
string A;
int ball_color[100009];
queue<int> ball;

int main()
{
	// 入力
	cin >> N >> X >> A;
	for (int i = 1; i <= N; i++)
	{
		if (A[i - 1] == '#')
			ball_color[i] = 1;
		if (A[i - 1] == '.')
			ball_color[i] = 2;
	}
	// 初期値の設定
	ball_color[X] = 3;
	ball.push(X);
	// クエリ処理
	while(!ball.empty())
	{
		int pos = ball.front();
		ball.pop();
		if (ball_color[pos - 1] == 2 && pos - 1 > 0)
		{
			ball_color[pos - 1] = 3;
			ball.push(pos - 1);
		}
		if (ball_color[pos + 1] == 2 && pos + 1 <= N)
		{
			ball_color[pos + 1] = 3;
			ball.push(pos + 1);
		}
	}
	// 出力
	for (int i = 1; i <= N; i++)
	{
		if (ball_color[i] == 1) cout << "#";
		if (ball_color[i] == 2) cout << ".";
		if (ball_color[i] == 3) cout << "@";
	}
	cout << endl;
	return 0;
}