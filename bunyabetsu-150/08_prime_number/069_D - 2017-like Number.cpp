#include <iostream>
#include <cmath>

using namespace std;

const int INF = 100000;

bool like_num[100009];
int cum_like_num[100009];

bool ft_check_prime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0) return false;
    }
    return true;
}

void ft_judge()
{
    for (int i = 1; i <= INF; i++)
    {
		if (i % 2 == 0) like_num[i] = false;
        else if (ft_check_prime(i) && ft_check_prime((i + 1) / 2)) like_num[i] = true;
        else like_num[i] = false;
    }
}

int main()
{
    int Q;
    cin >> Q;
    ft_judge();
    cum_like_num[0] = 0;
    for (int i = 1; i <= INF; i++)
    {
        cum_like_num[i] = cum_like_num[i - 1];
        if (like_num[i]) cum_like_num[i]++;
    }
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l > 1)
            cout << cum_like_num[r] - cum_like_num[l - 1] << endl;
        else
            cout << cum_like_num[r] << endl;
    }
    return 0;
}
