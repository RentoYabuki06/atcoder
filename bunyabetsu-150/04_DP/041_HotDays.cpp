#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;

ll D, N;
ll T[209];
ll A[209];
ll B[209];
ll C[209];
ll dp[209][9];

int main() {
    // 入力
    cin >> D >> N;
    for (int i = 1; i <= D; i++) cin >> T[i];
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];
 	// 着れるもののうち、派手さが最大or最小のものを選んでいく
	dp[0][0] = 0;
	dp[0][1] = 0;
	ll last_max = 0;
	ll last_min = 0;
	// D日分の服を動的計画法で決めていく
	for (int i = 1; i <= D; i++)
	{ 
		ll max_cloth = 0;
		ll min_cloth = 100;
		for (int j = 1; j <= N; j++)
		{
			if (A[j] <= T[i] && T[i] <= B[j])
			{
				max_cloth = max(max_cloth, C[j]);	// 着れる服のうち、最大の派手さ
				min_cloth = min(min_cloth, C[j]);	// 着れる服のうち、最小の派手さ
			}
		}
		if (i > 1)
		{
            dp[i][0] = max(dp[i-1][0] + abs(last_min - min_cloth), dp[i-1][1] + abs(last_max - min_cloth));
            dp[i][1] = max(dp[i-1][0] + abs(last_min - max_cloth), dp[i-1][1] + abs(last_max - max_cloth));
		}
		last_max = max_cloth;
		last_min = min_cloth;
	}
	cout << max(dp[D][0], dp[D][1]) << endl;
    return 0;
}
