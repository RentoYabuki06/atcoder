#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int N,K;
int P[200009];
int num_place[200009];
vector<vector<int>> num_distance;

int main()
{
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
		num_place[P[i]] = i;
	}
	// K離れたものたちの距離を調べていく
	num_distance.resize(N+1);
	for (int i = 1; i <= N - K; i++)
	{
		int distance = abs(num_place[i] - num_place[i + K]);
		num_distance[distance].push_back(i);
	}
	// 差が小さい組から調べていく
	for (int i = K; i <= N; i++)
	{
		// i の差の組みがなければ飛ばす
		if (num_distance[i].empty()) continue;
		// iの組み全てを探索
		for (auto num :num_distance[i])
		{
			if (num + i > N) continue;
			int min_place = 10000000000;
			int max_place = -1;
			for (int j = 0; j < i; j++)
			{
				min_place = min(min_place, num_place[num + j]);
				max_place = max(max_place, num_place[num + j]);
				if (max_place - min_place ==)
				{
					cout << i << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

