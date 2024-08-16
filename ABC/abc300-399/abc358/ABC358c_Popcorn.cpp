#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string S[19];
    for (int i = 0; i< N; i++) cin >> S[i];
    bool pop[19][19];
    for (int i = 0; i< N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            if (S[i][j] == 'o') pop[i][j] = true;
            else pop[i][j] = false;
        }
    }
    int ans = INT_MAX;
    for (int k = 0; k < (1 << N); k++) 
    {
        int num = 0;
        vector<bool> tmp_pop(M, false);
        for (int i = 0; i < N; i++)
        {
            if ((k >> i) & 1)
            {
                for (int j = 0; j < M; j++)
                {
                    if (pop[i][j]) tmp_pop[j] = true;
                }
                num++;
            }
        }
        bool ok = true;
        for (int j = 0; j < M; j++)
        {
            if (!tmp_pop[j])
            {
                ok = false;
                break;
            }
        }
        if (ok) ans = min(ans, num);
    }
    cout << ans << endl;
    return 0;
}
