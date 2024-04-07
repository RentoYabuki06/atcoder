#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    int64_t N;
    cin >> N;

    map<int64_t, int64_t> min_taste; // 各色の最小のおいしさを記録するマップ

    for (int64_t i = 0; i < N; i++) {
        int64_t A, C;
        cin >> A >> C;

        // 同じ色のビーンズのおいしさがより小さい場合に更新
        if (min_taste.find(C) == min_taste.end() || A < min_taste[C]) {
            min_taste[C] = A;
        }
    }

    // 最小のおいしさの中で最大のものを選択
    int64_t max_min_taste = 0;
    for (auto& pair : min_taste) {
        max_min_taste = max(max_min_taste, pair.second);
    }

    cout << max_min_taste << endl;

    return 0;
}
