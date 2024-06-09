#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string S;

int main()
{
    cin >> S;
    int up = 0;
    int low = 0;

    for (char c : S)
    {
        if (isupper(c)) up++;
        else if (islower(c)) low++;
    }

    if (up > low)
    {
        for (char &c : S) c = toupper(c);
    }
    else
    {
        for (char &c : S) c = tolower(c);
    }

    cout << S << endl;
    return 0;
}
