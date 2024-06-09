#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long N;
vector<long long> A;
vector<long long> depth;
vector<bool> visited, in_stack;

void dfs(long long v, stack<long long>& stk) {
    visited[v] = true;
    in_stack[v] = true;
    stk.push(v);
    
    long long new_place = A[v];
    if (!visited[new_place]) {
        dfs(new_place, stk);
    } else if (in_stack[new_place]) {
        // 閉路検出
        long long cycle_size = 0;
        while (stk.top() != new_place) {
            depth[stk.top()] = 0;
            in_stack[stk.top()] = false;
            stk.pop();
            cycle_size++;
        }
        depth[new_place] = 0;
        in_stack[new_place] = false;
        stk.pop();
        cycle_size++;
        for (int i = 0; i < cycle_size; ++i) {
            depth[new_place] = cycle_size;
            new_place = A[new_place];
        }
    }
    
    if (!stk.empty() && depth[v] == -1) {
        depth[v] = depth[A[v]] + 1;
        in_stack[v] = false;
        stk.pop();
    }
}

int main() {
    // 入力
    cin >> N;
    A.resize(N + 1);
    depth.resize(N + 1, -1);
    visited.resize(N + 1, false);
    in_stack.resize(N + 1, false);
    
    for (int i = 1; i <= N; i++) cin >> A[i];
    
    // DFSを用いて閉路を見つける
    stack<long long> stk;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, stk);
        }
    }
    
    // 解を求める
    long long ans = 0;
    for (int i = 1; i <= N; i++) ans += depth[i];
    cout << ans << endl;
    
    return 0;
}
