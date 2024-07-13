#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void ft_solve(string a, string b)
{
    ll len_a = a.size();
    ll len_b = b.size();
    vector<vector<ll>> dp(len_a + 1, vector<ll>(len_b + 1, 0));

    for (int i = 1; i <= len_a; i++)
    {
        for (int j = 1; j <= len_b; j++)
        {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[len_a][len_b] << endl;
}

int main()
{
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;
        ft_solve(a, b);
    }
    return 0;
}
