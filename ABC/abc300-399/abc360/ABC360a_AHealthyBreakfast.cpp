#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

string S;

int main()
{
	cin >> S;
	for (int i = 0; i < S.size() ; i++)
	{
		if (S[i] == 'R')
		{
			cout << "Yes" << endl;
			return 0;
		}
		if (S[i] == 'M')
		{
			cout << "No" << endl;
			return 0;
		}
	}
    return 0;
}
