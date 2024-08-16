#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

long long N, tmp;
bool board[730][730];

bool ft_check(int i, int j, int size)
{
    if (size == 1) return false;
    
    int newSize = size / 3;
    if ((i / newSize) % 3 == 1 && (j / newSize) % 3 == 1) return true;
    return ft_check(i, j, newSize);
}

int main()
{
    cin >> N;
    tmp = 1;
    for (int i = 1; i <= N; i++) tmp *= 3;
    
    for (int i = 0; i < tmp; i++)
    {
        for (int j = 0; j < tmp; j++)
        {
            board[i][j] = ft_check(i, j, tmp);
        }
    }
    
    for (int i = 0; i < tmp; i++)
    {
        for (int j = 0; j < tmp; j++)
        {
            if (board[i][j] == false) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    
    return 0;
}
