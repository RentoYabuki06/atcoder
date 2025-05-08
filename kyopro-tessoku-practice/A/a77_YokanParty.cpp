#include <iostream>

using namespace std;

int N, L, K;
int A[100009];

bool ft_check(int dist)
{
	int cut_count = 0;
	int last_cut_point = 0;
	for (int i = 1; i <= N; i++)
	{
		if (A[i] - last_cut_point >= dist && L - A[i] >= dist)
		{
			cut_count++;
			last_cut_point = A[i];
		}
	}
	if (cut_count >= K) return true;
	return false;
}

int main()
{
	// 入力
	cin >> N >> L >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	// 切れる数を二分探索
	long long left = 0;
	long long right = 1e9;
	while (left < right)
	{
		// +1を入れないとずっとwhile文を回ってしまう時がある
		long long mid = (left + right + 1) / 2;
		if (ft_check(mid)) left = mid;
		else right = mid - 1;
	}
	// 出力
	cout << left << endl;
	return 0;
}