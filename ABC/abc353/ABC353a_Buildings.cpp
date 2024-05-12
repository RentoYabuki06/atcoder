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

int N;
int A[100009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		if (A[1] < A[i])
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

