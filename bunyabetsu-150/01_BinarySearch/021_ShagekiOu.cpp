#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> baloons;

bool ft_check(long long place)
{
    vector<long long> left_min(N);
    // 残りの時間を計算
    for (int i = 0; i < N; i++)
    {
        if (place < baloons[i].second) return false;
        left_min[i] = (place - baloons[i].second) / baloons[i].first;
    }
    // 残りの時間が短い順にソート
    sort(left_min.begin(), left_min.end());
    for (int i = 0; i < N; i++)
    {
        if (left_min[i] < i) return false;
    }
    return true;
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long height, speed;
        cin >> height >> speed;
        baloons.push_back(make_pair(speed, height));
    }
    // 2分探索で秒数を決める
    long long L = 0;
    long long R = 1e18;
    long long ans = R;
    while (L <= R)
    {
        long long mid = (L + R) / 2;
        if (ft_check(mid))
        {
            ans = mid;
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    cout << ans << endl;
    return 0; 
}
