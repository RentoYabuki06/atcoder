#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
	ll a, b, c, d, e,f, g, h, i , j, k, l;
	cin >> a >> b >> c >> d >> e >>f >> g >> h >> i  >> j >> k >> l;
	if (j <= a || d <= g || e <= h || k <= b || f <= i || l <= c) cout << "No";
	else cout << "Yes";
	cout << endl;
	return 0;
}