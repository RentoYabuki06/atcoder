#include <iostream>
#include <queue>

using namespace std;

long long N;
queue<long long> q;

int main()
{
    cin >> N;
    q.push(N);
    long long ans = 0;
    while(!q.empty())
    {
        long long tmp = q.front(); // 先頭の要素を取得
        q.pop(); // 先頭の要素を削除
		if (tmp < 2) continue;
        ans += tmp;
		if (tmp % 2 == 0)
		{
			q.push(tmp / 2);
			q.push(tmp / 2);
		}
		else
		{
			q.push(tmp / 2);
			q.push(tmp / 2 + 1);
		}
    }
    cout << ans << endl;
    return 0;
}
