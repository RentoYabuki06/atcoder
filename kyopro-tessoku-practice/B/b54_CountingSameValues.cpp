#include <iostream>
#include <map>

using namespace std;

long long N;
long long A[100009];
map<long long, long long> count_num;

long long	ft_count(long long n)
{
	if (n < 2)
		return 0;
	return (n * (n - 1)) / 2;
}

int main()
{
	// 入力
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	// カウント
	for (int i = 0; i < N; i++) count_num[A[i]]++;

	// 合計
	long long ans = 0;
	for (auto& pair : count_num) {
		ans += ft_count(pair.second);
	}

	// 出力
	cout << ans << endl;
	return 0;
}
