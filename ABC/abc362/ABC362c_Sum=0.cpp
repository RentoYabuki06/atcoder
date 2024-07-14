#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    // 入力
    ll N;
    cin >> N;
    vector<pair<ll, ll>> intervals(N);
    ll min_sum = 0;
    ll max_sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll L, R;
        cin >> L >> R;
        intervals[i] = make_pair(L, R);
        min_sum += L;
        max_sum += R;
    }
    // Xの合計が0にできる場合
    if (min_sum <= 0 && max_sum >= 0)
    {
        cout << "Yes" << endl;
        vector<ll> result(N);
        // 一旦全ての左端を選択
        ll current_sum = min_sum;
        for (int i = 0; i < N; i++) result[i] = intervals[i].first;
        // current_sumが0になるまで右端を選択していく
        for (int i = 0; i < N && current_sum < 0; i++)
        {
            ll L = intervals[i].first;
            ll R = intervals[i].second;
            ll diff = min(R - L, -current_sum);
            result[i] += diff;
            current_sum += diff;
        }
        // 1つずつXを出力
        for (int i = 0; i < N; i++)
        {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    // Xの合計が0にできない場合
    else cout << "No" << endl;
    return 0;
}
