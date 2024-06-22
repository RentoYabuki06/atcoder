#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M, K, S, P, Q;
const long long INF = 1e18;
set<int> zombi_place;
set<int> dangerous_place;
vector<int> Graph[200009];
vector<vector<pair<int, int>>> Graph_after;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Que;
vector<int> dist;
vector<bool> fixed_place;

// ゾンビの街からS本以内の道路を通って行ける場所を見つける
void bfs() {
    queue<int> Q;

    // 初期化
    fill(dist.begin(), dist.end(), -1);
    for (int i = 0; i < N; i++) {
        if (zombi_place.count(i)) {
            dist[i] = 0;
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        for (int i = 0; i < Graph[pos].size(); i++) {
            int next_place = Graph[pos][i];
            if (dist[next_place] == -1) {
                dist[next_place] = dist[pos] + 1;
                if (dist[next_place] <= S) {
                    Q.push(next_place);
                    dangerous_place.insert(next_place);
                }
            }
        }
    }
}

long long dijkstra(int start_place) {
    // 配列の初期化
    vector<long long> cur(N, INF);
    fill(fixed_place.begin(), fixed_place.end(), false);
    // スタート地点をキューに追加
    cur[start_place] = 0;
    Que.push({cur[start_place], start_place});
    // ダイクストラ法
    while (!Que.empty()) {
        int pos = Que.top().second;
        Que.pop();
        if (fixed_place[pos]) continue;
        fixed_place[pos] = true;
        for (int i = 0; i < Graph_after[pos].size(); i++) {
            int nex = Graph_after[pos][i].first;
            if (zombi_place.count(nex)) continue;
            long long cost = Graph_after[pos][i].second;
            if (cur[nex] > cur[pos] + cost) {
                cur[nex] = cur[pos] + cost;
                Que.push({cur[nex], nex});
            }
        }
    }
    if (fixed_place[N - 1]) {
        if (dangerous_place.count(N - 1)) {
            return cur[N - 1] - Q;
        } else {
            return cur[N - 1] - P;
        }
    }
    return -1;
}

int main() {
    // 入力
    cin >> N >> M >> K >> S >> P >> Q;
    Graph_after.resize(N);
    dist.resize(N);
    fixed_place.resize(N);
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        zombi_place.insert(tmp - 1);
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Graph[a - 1].push_back(b - 1);
        Graph[b - 1].push_back(a - 1);
    }
    // 危険な町を判定
    bfs();
    // 道の重みを判定
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Graph[i].size(); j++) {
            int pos = Graph[i][j];
            if (dangerous_place.count(pos)) {
                Graph_after[i].push_back({pos, Q});
            } else {
                Graph_after[i].push_back({pos, P});
            }
        }
    }
    // 最小金額で移動できる経路を探索
    cout << dijkstra(0) << endl;
    return 0;
}
