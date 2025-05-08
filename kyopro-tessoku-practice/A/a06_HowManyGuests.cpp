#include <iostream>

using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	int A[1000009], L[1000009], R[1000009], cum[1000009];
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < Q; i++) cin >> L[i] >> R[i];
	cum[0] = A[0];
	for (int i = 1; i < N; i++) cum[i] = cum[i - 1] + A[i];
	for (int i = 0; i < Q; i++)
	{
		if (L[i] == 1)
		{
			cout << cum[R[i] - 1] << endl;
		}
		else
		{
			cout << cum[R[i] - 1] - cum[L[i] - 2] << endl;
		}
	}
	return 0;
}