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
set<int> group;

int main()
{
	// 入力
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
		num_place[P[i]] = i;
		if (P[i] >= 1 && P[i] <= K) group.insert(i);
	}
	// ik - i1の暫定値
	int min_distance = *group.rbegin() -  *group.begin();
	// 全てのパターン探索して最小値を更新
	for (int i = 1; i <= N - K ; i++)
	{
		group.erase(num_place[i]);
		group.insert(num_place[K  + i]);
		int distance = *group.rbegin() -  *group.begin();
		min_distance = min(min_distance, distance);
	}
	// 最小値を出力
	cout << min_distance << endl;
	return 0;
}

