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

int main()
{
	cin >> N;
	if (N % 400 == 0) cout << 366 << endl;
	else if (N % 100 == 0) cout << 365 << endl;
	else if (N % 4 == 0) cout << 366 << endl;
	else  cout << 365 << endl;
	return 0;
}