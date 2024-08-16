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

ll R,G,B;
string C;

int main()
{
	cin >> R >> G >> B >> C;
	if (C == "Red") cout << min(B, G) << endl;
	if (C == "Blue") cout << min(R, G) << endl;
	if (C == "Green") cout << min(B, R) << endl;
	return 0;
}