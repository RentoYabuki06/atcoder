#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int A[19];

int main()
{
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 見えるべき建物をK個選定(一番左の建物は確定)
	long long min_cost = 100000000000000000LL;
	for (int i = 0; i < (1 << (N - 1)); i++)
	{
		vector<bool> selected(N + 1, false);
		int tmp = i;
		int count_buildings = 1;
		selected[1] = true;
		for (int j = 2; j <= N; j++)
		{
			if (tmp % 2 == 1 || j == 1)
			{
				count_buildings++;
				selected[j] = true;
			}
			tmp /= 2;
		}
		// 選ばれたビルがK個ではなかったら飛ばす
		if (count_buildings != K) continue;
		// 選んだビルを見えるようにするためのコストを計算
		long long cost = 0;
		int current_highest = 0;
		for (int i = 1; i <= N; i++)
		{
			if (selected[i])
			{
				if (current_highest >= A[i])
				{
					cost += current_highest - A[i] + 1;
					current_highest++;
				}
				else current_highest = A[i];
			}
			// もし選ばなくていい建物が背がデカかったら、前の建物を無駄に大きくしないといけない
			else
			{
				if (current_highest < A[i])
				{
					cost += A[i] - current_highest;
					current_highest = A[i];
				}
			}
		}
		min_cost = min(min_cost, cost);
	}
	cout << min_cost << endl;
    return 0;
}
