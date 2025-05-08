#include <iostream>

using namespace std;

int	N, A[100009], Q, L[100009], R[100009], hit[100009], miss[100009];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> L[i] >> R[i];
	if (A[0] == 0)
	{
		hit[0] = 0;
		miss[0] = 1;
	}
	else
	{
		hit[0] = 1;
		miss[0] = 0;
	}
	for (int i = 1; i < N; i++)
	{
		if (A[i] == 0)
		{
			hit[i] = hit[i - 1];
			miss[i] = miss[i - 1] + 1;
		}
		else
		{
			hit[i] = hit[i - 1] + 1;
			miss[i] = miss[i - 1];
		}
	}
	for (int i = 0; i < Q; i++)
	{
		if (L[i] == 1)
		{
			if (hit[R[i] - 1] > miss[R[i] - 1])
			{
				cout << "win" << endl;
			}
			else if (hit[R[i] - 1] < miss[R[i] - 1])
			{
				cout << "lose" << endl;
			}
			else{
				cout << "draw" << endl;
			}
		}
		else
		{
			if (hit[R[i] - 1] - hit[L[i] - 2] > miss[R[i] - 1] - miss[L[i] - 2])
			{
				cout << "win" << endl;
			}
			else if (hit[R[i] - 1] - hit[L[i] - 2] < miss[R[i] - 1] - miss[L[i] - 2])
			{
				cout << "lose" << endl;
			}
			else{
				cout << "draw" << endl;
			}
		}
	}
}