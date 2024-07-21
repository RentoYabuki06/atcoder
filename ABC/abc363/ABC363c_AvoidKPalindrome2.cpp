#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, K;
string S;

// 順列全探索ライブラリ
namespace PermutationSearch {
    // 全ての順列を生成して処理する関数
    template <typename T>
    void generatePermutations(vector<T>& elements, void (*process)(const vector<T>&, ll&), ll& count) {
        // ソートして最初の順列を準備
        sort(elements.begin(), elements.end());

        do {
            // 現在の順列を処理する
            process(elements, count);
        } while (next_permutation(elements.begin(), elements.end()));
    }
}

// 長さ K の回文が部分文字列として含まれているかをチェックする関数
bool containsPalindrome(const string& str, int K) {
    for (int i = 0; i <= (int)str.size() - K; ++i) {
        bool isPalindrome = true;
        for (int j = 0; j < K / 2; ++j) {
            if (str[i + j] != str[i + K - 1 - j]) {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome) {
            return true;
        }
    }
    return false;
}

// 順列を処理する関数
void processPermutation(const vector<char>& permutation, ll& count) {
    string permStr(permutation.begin(), permutation.end());
    if (!containsPalindrome(permStr, K)) {
        count++;
    }
}

int main() {
    cin >> N >> K >> S;

    vector<char> elements(S.begin(), S.end());
    ll count = 0;

    // 順列全探索を実行
    PermutationSearch::generatePermutations(elements, processPermutation, count);

    cout << count << endl;

    return 0;
}
