#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 比較関数
bool customSort(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) { // first が同じ場合
        return a.second > b.second; // second を降順で比較
    }
    return a.first < b.first; // first を昇順で比較
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> boxes(N);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].first >> boxes[i].second;
    }

    // カスタムの比較関数を使ってソート
    sort(boxes.begin(), boxes.end(), customSort);

    int ans = 0;
    vector<int> height;
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(height.begin(), height.end(), boxes[i].second);
        int index = it - height.begin();
        if (it == height.end() || *it != boxes[i].second) {
            if (index == height.size()) {
                height.push_back(boxes[i].second);
            } else {
                height[index] = boxes[i].second;
            }
        }
        ans = max(ans, index + 1);
    }

    cout << ans << endl;

    return 0;
}
