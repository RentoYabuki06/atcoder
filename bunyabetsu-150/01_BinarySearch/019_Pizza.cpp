#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int store[100009];
int dest[10009];

int main()
{
	// 入力
	ll d, n, m;
	cin >> d >> n >> m;
	vector<ll> store(n+1, 0);
	for (int i = 1; i < n; i++) cin >> store[i];
	// ストアをソート
	store[n] = d;	// 番兵の役割
	sort(store.begin(), store.end());
	// 一番近いストアを2分探索で求める
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		ll dest = 0;
		cin >> dest;
		int pos = lower_bound(store.begin(), store.end(), dest) - store.begin();
		ll tmp = abs(store[pos] - dest);
		// ストアの位置が0でない場合、前後のストアの距離を比較して近い方を選択
		if (pos > 0) 
			tmp = min(abs(store[pos] - dest), abs(store[pos - 1] - dest));
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}