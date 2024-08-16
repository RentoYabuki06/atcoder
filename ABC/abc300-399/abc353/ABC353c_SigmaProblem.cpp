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
long long A[300009];
long long R[300009];
vector<long long> Q;

const long long INF = 1e8;

int main()
{
	cin >> N;
	long long total = 0;
	for(int i = 1; i <= N; i++)
	{
		cin >> A[i];
		Q.push_back(A[i]);
		total += A[i] * (N - 1);
	}
	// 昇順に並べる
	sort(Q.begin(), Q.end());
	// しゃくとり法
	for (int i = 0; i < N - 1; i++)
	{
		if (i == 0) R[i] = 0;
		else R[i] = R[i - 1];
		// ギリギリまで増やす
		while (R[i] < N - 1 - i && Q[R[i]] + Q[N - 1 - i] < INF) R[i]++;
		total -= INF * ((N - 1 - i) - R[i]);
		if (R[i] == N - 1 - i) break;
	}
	cout << total << endl;
	return 0;
}

