#include <iostream>
#include <set>

using namespace std;

int M, N;
long x_constellation[209];
long y_constellation[209];
long x_star[1009];
long y_star[1009];
set<long long> constellation;
set<long long> star;

// (x, y)だけ移動した時に星座として成立しうるか(星座に必要な星が適切な位置に)
bool Validation_constellation(int x, int y)
{
    long long diff = x + 1e6 * y;
    for (auto it = constellation.begin(); it != constellation.end(); ++it)
    {
        long long new_pos = *it + diff;
        if (!star.count(new_pos)) return false;
    }
    return true;
}

int main()
{
    cin >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> x_constellation[i] >> y_constellation[i];
        constellation.insert(x_constellation[i] + 1e6 * y_constellation[i]);
    }
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> x_star[i] >> y_star[i];
        star.insert(x_star[i] + 1e6 * y_star[i]);
    }
    // 平行移動量を探索
    for (int i = 1; i <= N; i++)
    {
        int x_diff = x_star[i] - x_constellation[1];
        int y_diff = y_star[i] - y_constellation[1];
        if (Validation_constellation(x_diff, y_diff))
        {
            cout << x_diff << " " << y_diff << endl;
            return 0; // 見つけたら終了
        }
    }
    return 0;
}
