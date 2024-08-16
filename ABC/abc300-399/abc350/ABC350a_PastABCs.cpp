#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string S, a, b;

int main()
{
    cin >> S;
    if (S.length() != 6)
    {
        cout << "No" << endl;
        return 0;
    }
    a = S.substr(0, 3);
    b = S.substr(3, 3);
    if (a != "ABC")
    {
        cout << "No" << endl;
        return 0;
    }
    int num = stoi(b);
    if (num == 316)
    {
        cout << "No" << endl;
        return 0;
    }

    if (num < 1 || num > 349)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
