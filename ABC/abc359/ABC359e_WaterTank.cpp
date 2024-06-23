#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

ll N;
ll H[200009];
vector<pair<ll, ll>> L;

int main()
{
    cin >> N;
    for (int i = 1; i <= N ; i++) cin >> H[i];

    // 動的計画法
    ll total = 1;
    // 一つ一つ壁を越えていく
    for (int i = 1; i <= N ; i++)
    {
        ll count = 1;
        while(!L.empty() && L.back().first < H[i])
        {
            total -= L.back().first * L.back().second;
            count += L.back().second;
            L.pop_back();
        }
        total += H[i] * count;
        L.push_back(make_pair(H[i], count));
        if (i > 1) cout << " ";
        cout << total;
    }
    return 0;
}
