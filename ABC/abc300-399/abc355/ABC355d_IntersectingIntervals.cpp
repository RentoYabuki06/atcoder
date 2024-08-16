#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, l, r;
vector<int> c;
vector<int> d;

int main()
{
    cin >> N;
    c.reserve(N);
    d.reserve(N);
    for (int i = 0; i < N; i++)
    {
        cin >> l >> r;
        c.push_back(l);
        d.push_back(r);
    }
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    long long ans = 0;
    int tmp = 0;
    int i = 0, j = 0;

    while (i < N && j < N)
    {
        if (c[i] > d[j])
        {
            tmp--;
            j++;
        }
        else
        {
            ans += tmp;
            tmp++;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
