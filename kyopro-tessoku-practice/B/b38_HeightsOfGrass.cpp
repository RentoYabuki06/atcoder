#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	int min_grass[3009];
	// それぞれの草の高さの最小値を初期化
	min_grass[0] = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (S[i] == 'A')
		{
			min_grass[i + 1] = min_grass[i] + 1;
		} 
		if (S[i] == 'B')
		{
			min_grass[i + 1] = 1;
			// もし1かつ右肩下がりだったら左側の要素も1追加
			if (min_grass[i] == 1)
			{
				int j = 0;
				while (min_grass[i - j] == min_grass[i + 1 - j])
				{
					min_grass[i - j]++;
					j++;
				}
			}
		} 
	}
	int ans = 0;
	for (int i = 0; i < N; i++) ans += min_grass[i];
	// // 検証用
	// for (int i = 0; i < N; i++) cout << min_grass[i] << " ";
	// cout << endl;
	cout << ans << endl;
	return 0;
}