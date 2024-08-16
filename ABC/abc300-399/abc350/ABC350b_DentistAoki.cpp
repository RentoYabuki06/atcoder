#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N, Q;
int T[1009], dp[1009];

int main()
{
	cin >> N >> Q;

	for (int i = 1; i <= 1001; i++) dp[i] = 0;
	for (int i = 1; i <= Q; i++)
	{
		cin >> T[i];
		dp[T[i]]++;
	}
	int count = 0;
	for (int i = 1; i <= 1001; i++)
	{
		if (dp[i] > 0 && dp[i] % 2 == 1)
			count++;
	}
	cout << N - count << endl;
	return 0;
}