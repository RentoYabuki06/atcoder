#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
int S[100009];
int T[50009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> S[i];
	cin >> Q;
	int count = 0;
	for (int i = 1; i <= Q; i++)
	{
		cin >> T[i];
		int pos = lower_bound(S + 1, S + N + 1, T[i]) - S; // indexが1から始まっていることに注意
		if (pos <= N && S[pos] == T[i]) count++;
	}
	cout << count << endl;
	return 0;
}