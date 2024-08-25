#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<set<int>> edge(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--; // 0-indexed に変換
        b--; // 0-indexed に変換
        edge[a].insert(b);
        edge[b].insert(a);
    }

    set<int> V;
    for (int i = 0; i < K; ++i) {
        int v;
        cin >> v;
        V.insert(v - 1); // 0-indexed に変換
    }

    vector<int> deg(N);
    for (int i = 0; i < N; ++i) {
        deg[i] = edge[i].size();
    }

    queue<int> q;
    for (int i = 0; i < N; ++i) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    int ans = N;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (V.find(v) != V.end()) continue;

        int vv = *edge[v].begin();
        edge[vv].erase(v);
        ans--;

        if (edge[vv].size() == 1) {
            q.push(vv);
        }
    }

    cout << ans << endl;

    return 0;
}
