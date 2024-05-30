#include <iostream>
#include <string>

using namespace std;

string S;
int alpha_count[26];

int main()
{
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        alpha_count[S[i] - 'a']++;
    }
    
    int mode_count = -1;
    int mode_alpha = -1;
    
    for (int i = 0; i < 26; i++)
    {
        if (alpha_count[i] > mode_count)
        {
            mode_count = alpha_count[i];
            mode_alpha = i;
        }
    }
    
    cout << char('a' + mode_alpha) << endl;
    return 0;
}
