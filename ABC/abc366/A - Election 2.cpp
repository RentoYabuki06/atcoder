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

ll N, T, A;
string S;
vector<vector<ll>> dp;

int main()
{
	cin >> N >> T >> A;
	if (T > N / 2 || A > N / 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}