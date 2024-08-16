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

int N, K;
int A[109];

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int count = 0;
	int current_empty = K;
	for (int i = 1; i <= N; i++)
	{
		if (current_empty >= A[i])
		{
			current_empty -= A[i];
		}
		else
		{
			current_empty = K;
			count++;
			current_empty -= A[i];
		}
	}
	if (current_empty != K) count++;
	cout << count << endl;
	return 0;
}

