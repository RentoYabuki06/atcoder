#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

ll H, W, Si, Sj;
string C[100];
string X;

int main()
{
    cin >> H >> W >> Si >> Sj;
    for (int i = 1; i <= H; i++)
    {
        cin >> C[i];
    }
    cin >> X;
    ll cx = Sj;
    ll cy = Si;
    for (int i = 0; i < X.size(); i++)
    {
        if (X[i] == 'L')
        {
            if (cx > 1 && C[cy][cx - 2] == '.') cx--;
        }
        if (X[i] == 'R')
        {
            if (cx < W && C[cy][cx] == '.') cx++;
        }
        if (X[i] == 'U')
        {
            if (cy > 1 && C[cy - 1][cx - 1] == '.') cy--;
        }
        if (X[i] == 'D')
        {
            if (cy < H && C[cy + 1][cx - 1] == '.') cy++;
        }
    }
    cout << cy << " " << cx << endl;
    return 0;
}
