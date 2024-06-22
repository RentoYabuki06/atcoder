#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
const int INF = 1e9;
vector<vector<pair<int, int>>> Graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
vector<int> cur;
vector<bool> fixed_place;

void ft_daikusutora(int start_place)
{
    // 配列の初期化
    fill(cur.begin(), cur.end(), INF);
    fill(fixed_place.begin(), fixed_place.end(), false);
    // スタート地点をキューに追加
    cur[start_place] = 0;
    Q.push(make_pair(cur[start_place], start_place));
    // ダイクストラ法
    while (!Q.empty())
    {
        int pos = Q.top().second;
        Q.pop();
        if (fixed_place[pos]) continue;
        fixed_place[pos] = true;
        for (int i = 0; i < Graph[pos].size(); i++)
        {
            int nex = Graph[pos][i].first;
            int cost = Graph[pos][i].second;
            if (cur[nex] > cur[pos] + cost)
            {
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex], nex));
            }
        }
    }
}

int main()
{
    // 入力
    cin >> N >> K;
    Graph.resize(N + 1);
    cur.resize(N + 1);
    fixed_place.resize(N + 1);
    for (int i = 0; i < K; i++)
    {
        bool tmp;
        cin >> tmp;
        if (tmp)
        {
            int c, d, e;
            cin >> c >> d >> e;
            Graph[c].push_back(make_pair(d, e));
            Graph[d].push_back(make_pair(c, e));
        }
        else
        {
            int a, b;
            cin >> a >> b;
            ft_daikusutora(a);
            if (cur[b] == INF) cout << -1 << endl;
            else cout << cur[b] << endl;
        }
    }
    return 0;
}
