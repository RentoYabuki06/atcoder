#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> socks;
int A[200009];
long long pre_cumsum[200009];
long long suf_cumsum[200009];

int main()
{
	// 入力
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> A[i];
		socks.push_back(A[i]);
	}
	// ソートして前後累積和をとる
	sort(socks.begin(), socks.end());
	for (int i = 0; i < K; i++) A[i] = socks[i];
	pre_cumsum[0] = 0;
	for (int i = 1; i <= K; i++)
	{
		pre_cumsum[i] = pre_cumsum[i - 1];
		if (i % 2 == 0) pre_cumsum[i] += A[i - 1] - A[i - 2];
	}
	suf_cumsum[K] = 0;
	for (int i = K - 1; i >= 0; i--)
	{
		suf_cumsum[i] = suf_cumsum[i + 1];
		if ((K - i) % 2 == 0) suf_cumsum[i] += A[i + 1] - A[i];
	}
	// 累積和を用いて計算
	long long ans = 100000000000000;
	if (K == 1) ans = 0;
	for (int i = 0; i <= K; i += 2)	// 1ずつのインクリメントだと靴下が全て除れない場合があるので注意
	{
		ans = min(ans, pre_cumsum[i] + suf_cumsum[i]);
	}
	// // 検証用
	// for (int i = 0; i < K; i++) cout << pre_cumsum[i] << " " << suf_cumsum[i] << endl;
	cout << ans << endl;
	return 0;
}