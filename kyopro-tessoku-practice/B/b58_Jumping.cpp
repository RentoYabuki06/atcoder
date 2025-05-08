#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, INT_MAX);
    }

    void update(int idx, int value, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (start == end) {
			// 基底ケース：葉ノードの更新
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node, start, mid);		// 左側の子ノードの更新
            } else {
                update(idx, value, 2 * node + 1, mid + 1, end);	// 右側の子ノードの更新
            }
			// 現在のノードの値を更新
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int L, int R, int node = 1, int start = 0, int end = -1) {
        if (end == -1) end = n - 1;
        if (R < start || L > end) return INT_MAX;		// 範囲外へはみだす場合
        if (L <= start && end <= R) return tree[node];	// 完全に範囲外の場合
        int mid = (start + end) / 2;
		// 左右の子ノードに再起的にクエリを行い、その結果の最小値を返す
        return min(query(L, R, 2 * node, start, mid), query(L, R, 2 * node + 1, mid + 1, end));
    }
};


int main() {
	// 入力
	int N, L, R;
    cin >> N >> L >> R;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

	// 配列の初期化
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;

    SegmentTree seg(N);
    seg.update(0, 0);

	// セグメント木を用いた動的計画法
    for (int i = 1; i < N; i++) {
        int left = lower_bound(X.begin(), X.end(), X[i] - R) - X.begin();
        int right = upper_bound(X.begin(), X.end(), X[i] - L) - X.begin() - 1;
        if (left <= right) {
			// 範囲内の最小ジャンプ数を取得
            int min_jump = seg.query(left, right);
            if (min_jump != INT_MAX) {
                dp[i] = min_jump + 1;
            }
        }
        seg.update(i, dp[i]);
    }

	// 最終地点までの最小ステップ数を出力
    cout << dp[N - 1] << endl;

    return 0;
}
