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

ll N;
string S[1000];
vector<vector<ll>> dp;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		if (i > 1)
		{
			if (S[i-1] == S[i] && S[i] == "sweet")
			{
				if (i == N) continue;
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}