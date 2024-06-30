#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
ll A[44859];
ll B[44859];
ll D[44859];
ll dist_graph[309][309];
vector<pair<ll, ll>> Graph[100009];

int main()
{
    // 入力と初期化
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) dist_graph[i][j] = 0;
            else dist_graph[i][j] = 1e18;
		}
    }
    for (int i = 0; i < M; i++)
    {
        cin >> A[i] >> B[i] >> D[i];
        dist_graph[--A[i]][--B[i]] = D[i];
        dist_graph[B[i]][A[i]] = D[i];
    }
    // ワーシャルフロイド法
    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
				dist_graph[i][j] = min(dist_graph[i][j], dist_graph[i][k] + dist_graph[k][j]);
            }
        }
    }
    // 出力
	ll ans = 1e18;
	for (int i = 0; i < N; i++)
	{
		ll tmp = 0;
		for (int j = 0; j < N; j++)
		{
			if (i == j) continue;
			tmp = max(tmp, dist_graph[i][j]);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
    return 0;
}
