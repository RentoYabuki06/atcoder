#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int N;
string S, T;

int main()
{
	cin >> S >> T;
	for (int i = 1; i < S.size() ; i++)
	{
		for (int j = 1; j <= i ; j++)
		{
			string tmp;
			int sep = j - 1;
			while (sep < S.size())
			{
				tmp += S[sep];
				sep += i;
			}
			if (tmp == T)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
    return 0;
}
