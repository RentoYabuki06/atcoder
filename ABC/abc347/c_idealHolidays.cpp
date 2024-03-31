#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, A, B, max = 0, min = 2000000000, D;
	cin >> N >> A >> B;

	for (int i = 0; i < N; i++)
	{
		cin >> D;
		if (max < D % (A + B)) max = D % (A + B);
		if (min > D % (A + B)) min = D % (A + B);
	} 
	if (max - min + 1 <= A) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}