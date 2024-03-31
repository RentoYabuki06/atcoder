#include <bits/stdc++.h>
using namespace std;


int N, K;
int A[100];

int	main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	bool first = true;
	for (int i = 0; i < N; i++)
	{
		if (A[i] % K == 0)
		{
			if (!first) cout << " ";
			cout << A[i] / K;
			first = false;
		}
	}
	cout << endl;
}