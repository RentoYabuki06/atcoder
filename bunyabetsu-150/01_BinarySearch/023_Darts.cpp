#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> points(N+1);
    // 投げなかった=0点の領域に投げたことにする
    points[0] = 0;
    for (int i = 1; i <= N; i++) cin >> points[i];
    
    // 半分全列挙：2本の矢で可能な点数を求める
    vector<int> point_pair((N + 1) * (N + 1));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++) point_pair[i * (N + 1) + j] = points[i] + points[j];
    }
    
    sort(point_pair.begin(), point_pair.end());
    
    // それぞれのpairに対する相手のペアを求める
    int ans = 0;
    for (int i = 0; i < (N + 1) * (N + 1); i++)
    {
        if (point_pair[i] > M) break;
        int remaining = M - point_pair[i];
        auto it = upper_bound(point_pair.begin(), point_pair.end(), remaining);
        if (it != point_pair.begin()) it--;
        ans = max(ans, point_pair[i] + *it);
    }
    
    cout << ans << endl;
    return 0;
}
