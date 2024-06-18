#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> num_member(N);
	vector<int> time_kyoten(N);
	for (int i = 0; i < N; i++) cin >> num_member[i] >> time_kyoten[i];
	// それぞれの時間で参加可能な人数を求める
	int max_num = 0;
	for (int k = 0; k < 24; k++)
	{
		int tmp = 0;
		for (int i = 0; i < N; i++)
		{
			int tmp_time = (time_kyoten[i] + k) % 24;
			if (tmp_time >= 9 && tmp_time < 18) tmp += num_member[i];
		}
		max_num = max(max_num, tmp);
	}
	cout << max_num << endl;
	return 0;
}