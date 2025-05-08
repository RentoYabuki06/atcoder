#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int N, M;
int A[100009];
int B[100009];
int C[100009];
vector<pair<int, int>> graph[100009];
int cur[100009];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        graph[A[i]].push_back(make_pair(B[i], C[i]));
        graph[B[i]].push_back(make_pair(A[i], C[i]));
    }

    // 配列の初期化
    for (int i = 1; i <= N; i++) {
        cur[i] = INF;
    }

    // スタート地点をキューに追加
    cur[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(cur[1], 1));

    // ダイクストラ法
    while (!Q.empty()) {
        pair<int, int> top = Q.top();
        int pos = top.second;
        Q.pop();

        // cur[pos]の値が更新されている場合は飛ばす
        if (cur[pos] < top.first) continue;

        for (int i = 0; i < graph[pos].size(); i++) {
            int next_place = graph[pos][i].first;
            int next_time = graph[pos][i].second;
            if (cur[next_place] > cur[pos] + next_time) {
                cur[next_place] = cur[pos] + next_time;
                Q.push(make_pair(cur[next_place], next_place));
            }
        }
    }

    // 出力
    for (int i = 1; i <= N; i++) {
        if (cur[i] == INF)
            cout << "-1" << endl;
        else
            cout << cur[i] << endl;
    }

    return 0;
}