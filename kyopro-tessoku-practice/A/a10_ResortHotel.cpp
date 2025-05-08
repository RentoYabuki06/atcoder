#include <iostream>

using namespace std;

int N, A[100009], D, L[100009], R[100009], left_maxroom[100009], right_maxroom[100009];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> D;
	for (int i = 0; i < D; i++) cin >> L[i] >> R[i];
	left_maxroom[0] = A[0];
	right_maxroom[N - 1] = A[N - 1];
	for (int i = 1; i < N; i++)
	{
		if (A[i] > left_maxroom[i - 1])
		{
			left_maxroom[i] = A[i];
		}
		else
		{
			left_maxroom[i] = left_maxroom[i - 1];
		}
		if (A[N - 1 - i] > right_maxroom[N - i])
		{
			right_maxroom[N - 1 - i] = A[N - 1 - i];
		}
		else
		{
			right_maxroom[N - 1 - i] = right_maxroom[N - i];
		}
	}
	for (int i = 0; i < D; i++)
	{
		if (right_maxroom[R[i]] > left_maxroom[L[i] - 2])
		{
			cout << right_maxroom[R[i]] << endl;
		}
		else
		{
			cout << left_maxroom[L[i] - 2] << endl;
		}
	}
	return 0;
}