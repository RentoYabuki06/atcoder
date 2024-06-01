#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int X[209], Y[209];
// それぞれの議員の知り合いを格納
bool legislator[19][19];

int main()
{
	// 入力
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) legislator[i][j] = false;
	}
	// それぞれの知り合いを格納
	for (int i = 1; i <= M; i++)
	{
		cin >> X[i] >> Y[i];
		legislator[X[i]][Y[i]] = true;
		legislator[Y[i]][X[i]] = true;
	}
	// N 人の中でどのように選ぶかビット全探索
	int max_member = 1;
	bool tmp_legislator[19];
	for (int i = 0; i < (1 << N); i++)
	{
		int member = 0;
		int tmp = i;
		// 選ばれた人をtmp_legislator配列で保持
		for (int j = 1; j <= N; j++)
		{
			if (tmp % 2 == 1)
			{
				member++;
				tmp_legislator[j] = true;
			}
			else tmp_legislator[j] = false;
			tmp /= 2;
		}
		bool create_zaibatsu = true;
		// 候補者全員に対して交友関係をチェック
		for (int j = 1; j < N; j++)
		{
			if (tmp_legislator[j])
			{
				for (int k = j + 1; k <= N; k++)
				{
					if(tmp_legislator[k] && !legislator[j][k])
					{
						create_zaibatsu = false;
						break;
					}
				}
				if (create_zaibatsu == false) break;
			}
		}
		// これまでより大きな財閥ができるなら更新
		if (create_zaibatsu) max_member = max(max_member, member);
	}
	cout << max_member << endl;
	return 0;
}