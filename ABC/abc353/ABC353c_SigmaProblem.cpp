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
long long A[300009];
vector<long long> Q;

const long long INF = 100000000;

int main()
{
	cin >> N;
	long long total = 0;
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
		Q.push_back(A[i]);
		total += A[i];
	}
	total *= (N - 1);
	sort(Q.begin(), Q.end());
	int count = 0;
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			auto tmp = lower_bound(Q.begin(), Q.end(), INF - Q[i]);
			count += tmp - Q.begin();
		}
	}
	total -= count * INF;
	cout << total << endl;
	return 0;
}

