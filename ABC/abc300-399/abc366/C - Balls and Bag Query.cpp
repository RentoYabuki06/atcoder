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

ll Q;
ll A[1000009];
string S;
vector<vector<ll>> dp;
set<ll> st;

int main()
{
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		ll query;
		ll num;
		cin >> query;
		if (query == 1)
		{
			cin >> num;
			A[num]++;
			if (A[num] == 1)
			{
				st.insert(num);
			}
		}
		else if (query == 2)
		{
			cin >> num;
			A[num]--;
			if (A[num] == 0)
			{
				st.erase(num);
			}
		}
		else
		{
			cout << st.size() << endl;
		}
	}
	return 0;
}