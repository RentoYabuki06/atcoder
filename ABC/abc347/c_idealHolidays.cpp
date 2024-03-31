#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, A, B;
	int D[200000];
	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) cin >> D[i];

	sort(D, D + N);
	if ((D[N - 1] - D[0]) > A) cout << "Yes" << endl;
	else cout << "No" << endl;
}