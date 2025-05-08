#include <iostream>
#include <algorithm>

using namespace std;

int N, A[100009], Q, X;

int	main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	sort(A, A + N);
	for (int i = 0; i < Q; i++)
	{
		cin >> X;
		int pos = lower_bound(A, A + N, X) - A;
		cout << pos << endl;
	}
	return 0;
}