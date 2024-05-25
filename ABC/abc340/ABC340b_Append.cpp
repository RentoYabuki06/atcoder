#include <iostream>

using namespace std;

int Q;
int A[109];
int B[109];
int C[109];

int main()
{
	cin >> Q;
	int j = 0;
	for (int i = 0; i < Q; i++)
	{
		cin >> A[i] >> B[i];
		if (A[i] == 1)
		{
			C[j] = B[i];
			j++;
		}
		else if (A[i] == 2)
		{
			cout << C[j - B[i]] << endl;
		}
	}
	return 0;
}