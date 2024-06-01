#include <iostream>

using namespace std;

long long N;
int digits[19];

int main()
{
    cin >> N;
    N--;
    for (int i = 0; i < 19; i++)
    {
        digits[i] = N % 5;
        N /= 5;
    }
    int i = 18;
    while (i >= 0 && digits[i] == 0) i--;
    if (i < 0)
    {
        cout << 0 << endl;
    }
    else
    {
        while (i >= 0)
        {
            cout << digits[i] * 2;
            i--;
        }
        cout << endl;
    }
    return 0;
}
