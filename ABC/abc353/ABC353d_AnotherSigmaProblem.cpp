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

const long long INF = 998244353;

long long N;
long long A[200009];
long long digits[200009];
long long dig_mul[19];

int main()
{
	cin >> N;
	long long total = 0;
	for (int i = 0; i <= 10; i++) digits[i] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		digits[to_string(A[i]).size()]++; 
		total += A[i] * (i - 1);
		total %= INF;
	}
	// 10から10^9まで事前に計算しておく
	dig_mul[0] = 1;
	for (int i = 1; i <= 10; i++)
	{
		dig_mul[i] = 10 * dig_mul[i - 1];
		dig_mul[i] %= INF;
		digits[i] %= INF;
	}
	for (int i = 1; i <= N - 1; i++)
	{
		digits[to_string(A[i]).size()]--; 
		A[i] %= INF;
		for (int j = 1; j <= 10; j++)
		{
			long long tmp = digits[j] * dig_mul[j];
			tmp %= INF;
			total += A[i] * tmp;
			total %= INF;
		}
	}
	cout << total << endl;
	return 0;
}

