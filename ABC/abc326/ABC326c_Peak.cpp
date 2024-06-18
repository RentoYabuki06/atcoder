#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	// 入力
	int N, M;
	cin >> N >> M;
	vector<int> boxes(N);
	for (int i = 0; i < N; i++) cin >> boxes[i];
	// 昇順でソート
	sort(boxes.begin(), boxes.end());
	long long ans = 0;
	queue<int> q;
	int count_box = 0;
	for (int i = 0; i < N; i++)
	{
		q.push(boxes[i]);
		count_box++;
		while (boxes[i] - M + 0.1 > q.front())
		{
			q.pop();
			count_box--;
		}
		if (count_box > ans) ans = count_box;
	}
	cout << ans << endl;
	return 0;
}