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
ll A[1000009];
string S;
vector<vector<ll>> dp;

int main()
{
	cin >> N;
	if (N >= 300) cout << 400 - N << endl;
	else if (N >= 200) cout << 300 - N << endl;
	else if (N >= 100) cout << 200 - N << endl;
	else cout << 100 - N << endl;
}