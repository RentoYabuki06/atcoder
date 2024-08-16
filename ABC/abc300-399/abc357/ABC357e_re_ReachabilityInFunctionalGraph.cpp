#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
int A[200009];
int depth[200009];
bool visited[200009];
bool in_stack[200009];
stack<int> stk;

void ft_dfs(int place) {
    visited[place] = true;
    in_stack[place] = true;
    stk.push(place);
    int next_place = A[place];
    // 未踏の地だったら探索
    if (!visited[next_place]) ft_dfs(next_place);
    // 閉路が見つかったら
    else if (in_stack[next_place]) {
        int cirle_size = 0;
        while (stk.top() != next_place) {
            in_stack[stk.top()] = false;
            stk.pop();
            cirle_size++;
        }
        in_stack[stk.top()] = false;
        stk.pop();
        cirle_size++;
        int start_place = next_place;
        for (int i = 0; i < cirle_size; i++) {
            depth[next_place] = cirle_size;
            next_place = A[next_place];
        }
    }
    if (!stk.empty() && depth[place] == -1) {
        depth[place] = depth[A[place]] + 1;
        in_stack[stk.top()] = false;
        stk.pop();
    }
}

int main() {
    // 入力と初期化
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        depth[i] = -1;
        visited[i] = false;
        in_stack[i] = false;
    }
    // 深さ優先探索
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) ft_dfs(i);
    }
    // 解を求める
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += depth[i];
    }
    cout << ans << endl;
    return 0;
}
