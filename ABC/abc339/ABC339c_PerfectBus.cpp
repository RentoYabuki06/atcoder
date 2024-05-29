#include <iostream>

using namespace std;

int N;
long long A[200009];
long long Cpassenger;

int main()
{
	// 入力
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	// 途中で負の数にならないように注意
	Cpassenger = 0;
	for (int i = 0; i < N; i++)
	{
		Cpassenger += A[i];
		if (Cpassenger < 0)
		{
			Cpassenger = 0;
		}
	}
	cout << Cpassenger << endl;
	return 0;
}