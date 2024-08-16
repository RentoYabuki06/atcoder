#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long long N;
unordered_map<long long, long long> memo;

// メモ化再起関数
long long ft_solve(long long x)
{
	if (x == 1) return 0;
	// メモに結果があればそれを返す
	if (memo.find(x) != memo.end()) return memo[x];
	long long cost = x;
	if (x % 2 == 0)
		cost += ft_solve(x / 2) * 2;
	else
	{
		cost += ft_solve(x / 2);
		cost += ft_solve((x / 2) + 1);
	}
	memo[x] = cost;
	return cost;
}

int main()
{
	long long x;
	cin >> x;
	ft_solve(x);
	cout << memo[x] << endl;
	return 0;
}


// TLEになったコード

// long long N;
// queue<long long> q;

// int main()
// {
//     cin >> N;
//     q.push(N);
//     long long ans = 0;
//     while(!q.empty())
//     {
//         long long tmp = q.front(); // 先頭の要素を取得
//         q.pop(); // 先頭の要素を削除
// 		if (tmp < 2) continue;
//         ans += tmp;
// 		if (tmp % 2 == 0)
// 		{
// 			q.push(tmp / 2);
// 			q.push(tmp / 2);
// 		}
// 		else
// 		{
// 			q.push(tmp / 2);
// 			q.push(tmp / 2 + 1);
// 		}
//     }
//     cout << ans << endl;
//     return 0;
// }
