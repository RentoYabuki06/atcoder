#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

long long N;

int main()
{
	cin >> N;
	long long height = 1;
	for (int i = 1; i <= N;i++)
	{
		height *= 2;
		height += 1;
		if (height > N)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << 2 << endl;
	return 0;
}

