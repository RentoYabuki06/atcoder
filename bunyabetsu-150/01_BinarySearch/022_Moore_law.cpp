#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
long double P;

long double ft_function(long double x)
{
    return x + P * pow(2, -(x / 1.5));
}

int main()
{
    // 入力
    cin >> P;
    long double L = 0;
    long double R = pow(10, 18);
    while (L + pow(10, -9) < R)
    {
        long double mid01 = L + (R - L) / 3;
        long double mid02 = L + (R - L) * 2 / 3;
        if (ft_function(mid01) < ft_function(mid02)) R = mid02;
        else L = mid01;
    }
    // 小数点以下9桁まで表示
    cout << fixed << setprecision(9) << ft_function(L) << endl;
    return 0;
}
