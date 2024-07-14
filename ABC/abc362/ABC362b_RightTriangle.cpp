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

ll xa, ya, xb, yb, xc, yc;

int main()
{
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	ll a = pow(xa - xb, 2) + pow(ya - yb, 2);
	ll b = pow(xc - xb, 2) + pow(yc - yb, 2);
	ll c = pow(xa - xc, 2) + pow(ya - yc, 2);
	if ((a + b == c) || (a + c == b) || (b + c == a)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}