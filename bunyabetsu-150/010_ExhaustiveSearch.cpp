#include <iostream>

using namespace std;

int N;
int A[29];
int Q;
int M[209];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> M[i];
	// ビット全探索
	for (int i = 0; i < Q; i++)
	{
		for (int j = 0; j < (1 << N); j++)
		{
			int tmp = 0;
			int num = j;
			for (int k = 0; k < N; k++)
			{
				if (num % 2 == 0) tmp += A[k];
				num /= 2;
			}
			if (tmp == M[i])
			{
				cout << "Yes" << endl;
				break;
			}
			else if (j == (1 << N) - 1)
			{
				cout << "No" << endl;
			}
		}
	}
	return 0;
}