#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, K;
ll C[10009];
ll R[10009];
ll A[10009];
ll B[10009];
vector<ll> Graph[5009];
vector<ll> cur_cost;
vector<bool> fixed_town;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

int main()
{
    // 入力
    cin >> N >> K;
    fixed_town.resize(N);
    cur_cost.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i] >> R[i];
    for (int i = 0; i < K; i++)
    {
        cin >> A[i] >> B[i];
        Graph[--A[i]].push_back(--B[i]);
        Graph[B[i]].push_back(A[i]);
    }
    // 配列の初期化
    for (int i = 0; i < N; i++)
    {
        fixed_town[i] = false;
        cur_cost[i] = 1e18;
    }
    // スタート地点をキューに追加
    cur_cost[0] = 0;
    Q.push(make_pair(cur_cost[0], 0));
    // ダイクストラ法
    while (!Q.empty())
    {
        ll cost = Q.top().first;
        ll place = Q.top().second;
        Q.pop();
        // 確定済みの場所はスキップ
        if (fixed_town[place]) continue;
        fixed_town[place] = true;

		// 幅優先探索（BFS）でplaceからいける範囲の街がcur[place] + cost よりも安かったら更新
        queue<ll> que;
        que.push(place);
		// placeからの距離を格納するdistance
        vector<ll> distance(N, -1);
        distance[place] = 0;
        while (!que.empty())
        {
            ll current = que.front();
            que.pop();
            if (distance[current] == R[place]) continue;
            for (ll neighbor : Graph[current])
            {
				// 次の街が未到達だったら
                if (distance[neighbor] == -1)
                {
                    distance[neighbor] = distance[current] + 1;
                    que.push(neighbor);
					// もし最安値を更新した場所があればQに追加
                    if (cur_cost[neighbor] > cost + C[place])
                    {
                        cur_cost[neighbor] = cost + C[place];
                        Q.push(make_pair(cur_cost[neighbor], neighbor));
                    }
                }
            }
        }
    }
    // 出力
    cout << cur_cost[N - 1] << endl;
    return 0;
}
