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
int A[200009], B[200009];
int C[200009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
	int diff_max = 0;
	int diff_max_place = 0;
	for (int i = 1; i <= N; i++)
	{
		C[i] =  B[i] - A[i];
		if (diff_max <= C[i])
		{
			diff_max = C[i];
			diff_max_place = i;
		}
	}
	long long total_height = B[diff_max_place];
	for (int i = 1; i <= N; i++)
	{
		if (i != diff_max_place) total_height += A[i];
	}
	cout << total_height << endl;
}

