#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

using namespace std;

long long N;
long long A[200009];
bool visited[200009];
long long depth[200009];
deque<long long> path_cycle;

bool ft_dfs(long long place) {
    visited[place] = true;
    path_cycle.push_back(place);
    long long new_place = A[place];
    if (new_place == place) {
        depth[place] = 1;
        path_cycle.pop_back();
        return false; // 自己ループは無視
    }
    if (!visited[new_place])
    {
        if(ft_dfs(new_place)) return true;
        else
        {
            path_cycle.clear();
            return false;
        }
    }
    auto it = find(path_cycle.begin(), path_cycle.end(), new_place);
    if (it != path_cycle.end()) {
        while (new_place != path_cycle.front()) path_cycle.pop_front();
        return true;
    }
    return false;
}

long long ft_depth(long long place) {
    long long new_place = A[place];
    if (new_place == place) return 1;
    if (depth[new_place] == -1) {
        depth[place] = ft_depth(new_place) + 1;
    } else {
        depth[place] = depth[new_place] + 1;
    }
    return depth[place];
}

int main() {
    // 入力
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    // 初期化
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
        depth[i] = -1;
    }
    // 唯一存在する閉路を見つける
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        if(ft_dfs(i)) break;
    }

    // 閉路の中の頂点から到達可能な頂点数はcircle_sizeとなる
    if (!path_cycle.empty())
    {
        long long circle_size = path_cycle.size();
        for (int v : path_cycle) depth[v] = circle_size;
    }
    for (int i = 1; i <= N; i++) 
    {
        if (i == A[i]) depth[i] = 1;
    }


    // 解を求める
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (i == A[i]) ans++;
        else if (depth[i] != -1) ans += depth[i];
        else ans += ft_depth(i);
    }
    cout << ans << endl;
    return 0;
}
