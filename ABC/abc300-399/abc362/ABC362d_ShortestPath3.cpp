#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

ll N, M;
ll A[200009];
ll U[200009];
ll V[200009];
ll B[200009];
const ll INF = 1e18;
vector<pair<ll, ll>> Graph[200009];
vector<ll> cur(200009, INF);
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= M; i++)
    {
        cin >> U[i] >> V[i] >> B[i];
        Graph[U[i]].push_back(make_pair(V[i], B[i] + A[V[i]]));
        Graph[V[i]].push_back(make_pair(U[i], B[i] + A[U[i]]));
    }
    // 初期値の設定
    for (int i = 1; i <= N; i++) cur[i] = INF;
    // スタート
    cur[1] = A[1];
    Q.push(make_pair(cur[1], 1));
    // ダイクストラ法
    while (!Q.empty())
    {
        pair<ll, ll> top = Q.top();
        Q.pop();
        ll pos = top.second;
        if (cur[pos] < top.first) continue;
        for (int i = 0; i < Graph[pos].size(); i++)
        {
            ll next_place = Graph[pos][i].first;
            ll next_time = Graph[pos][i].second;
            if (cur[next_place] > cur[pos] + next_time)
            {
                cur[next_place] = cur[pos] + next_time;
                Q.push(make_pair(cur[next_place], next_place));
            }
        }
    }
    // 出力
    for (int i = 2; i <= N; i++)
    {
        if (i > 2) cout << " ";
        cout << cur[i];
    }
    cout << endl;
    return 0;
}
