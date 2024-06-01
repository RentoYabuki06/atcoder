#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int P[9];
int Q[9];
int a = 0;
int b = 0;
bool p_bool;
bool q_bool;

// 順列全探索ライブラリ
namespace PermutationSearch {
    // 全ての順列を生成して処理する関数
    template <typename T>
    void generatePermutations(vector<T>& elements, void (*process)(const vector<T>&)) {
        // ソートして最初の順列を準備
        sort(elements.begin(), elements.end());
        int count = 1;
        do {
            // 現在の順列を処理する
            p_bool = true;
            q_bool = true;
            process(elements);
            if (p_bool) a = count;
            if (q_bool) b = count;
            count++;
        } while (next_permutation(elements.begin(), elements.end()));
    }
}

// 順列を処理する例の関数
void checkPermutation(const vector<int>& permutation) {
    for (int i = 0; i < permutation.size(); ++i) {
        if (P[i] != permutation[i]) p_bool = false;
        if (Q[i] != permutation[i]) q_bool = false;
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];

    vector<int> elements(N);
    for (int i = 0; i < N; ++i) {
        elements[i] = i + 1;
    }

    // 順列全探索を実行
    PermutationSearch::generatePermutations(elements, checkPermutation);
    cout << abs(a - b) << endl;
    return 0;
}
