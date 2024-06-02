#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 順列全探索ライブラリ
namespace PermutationSearch {
    // 全ての順列を生成して処理する関数
    template <typename T>
    void generatePermutations(vector<T>& elements, void (*process)(const vector<T>&)) {
        // ソートして最初の順列を準備
        sort(elements.begin(), elements.end());

        do {
            // 現在の順列を処理する
            process(elements);
        } while (next_permutation(elements.begin(), elements.end()));
    }
}

// 順列を処理する例の関数
void printPermutation(const vector<int>& permutation) {
    for (int num : permutation) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    vector<int> elements(N);
    for (int i = 0; i < N; ++i) {
        elements[i] = i + 1;
    }

    // 順列全探索を実行
    PermutationSearch::generatePermutations(elements, printPermutation);

    return 0;
}
