#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    string S, T;
    cin >> N >> S >> T;
    S += "..";
    T += "..";
    // 幅優先探索の準備
    map<string, ll> dist;
    queue<string> Q;
    dist[S] = 0; Q.push(S);
    // 幅優先探索の実行
    while (!Q.empty())
    {
        string tmp = Q.front(); Q.pop();
        int index = 0;
        while (tmp[index] != '.') index++;
        for (int i = 0; i < N + 1; i++)
        {
            if (tmp[i] == '.' || tmp[i+1] == '.') continue;
            string nex = tmp;
            swap(nex[i], nex[index]);
            swap(nex[i+1], nex[index+1]);
            if (dist.count(nex)) continue;
            dist[nex] = dist[tmp] + 1; Q.push(nex);
        }
    }
    if (dist.count(T)) cout << dist[T] << endl;
    else cout << -1 << endl;
    return 0;
}
