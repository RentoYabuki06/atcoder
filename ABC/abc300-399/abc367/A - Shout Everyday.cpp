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

ll A, B, C;

int main()
{
	cin >> A >> B >> C;
	if (B < C)
	{
		if (!(B < A && A < C))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	else
	{
		if (!(A < C || B < A))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}