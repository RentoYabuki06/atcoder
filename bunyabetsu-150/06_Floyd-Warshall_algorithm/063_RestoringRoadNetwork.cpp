#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N;
ll A[309][309];
ll dist_city[309][309];

int main()
{
    // 入力と初期化
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist_city[i][j] = 1e18;
            if (i == j) dist_city[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            dist_city[i][j] = A[i][j];
        }
    }

    // ワーシャルフロイド法で最小距離を求める
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist_city[i][j] = min(dist_city[i][j], dist_city[i][k] + dist_city[k][j]);
            }
        }
    }

    // 条件を満たすかチェック
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist_city[i][j] != A[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // 最小の道路の長さの和を求める
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            bool isNeeded = true;
            for (int k = 0; k < N; k++)
            {
				// どこかの都市を経由する場合は直接道路は不要
                if (k != i && k != j && A[i][j] == A[i][k] + A[k][j])
                {
                    isNeeded = false;
                    break;
                }
            }
            if (isNeeded)
            {
                ans += A[i][j];
            }
        }
    }
	// 出力
    cout << ans << endl;
    return 0;
}
