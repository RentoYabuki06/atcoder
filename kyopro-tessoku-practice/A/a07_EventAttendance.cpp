#include <iostream>

using namespace std;

int D, N, L[100009], R[100009], change[100009], total[100009];

int main()
{
	cin >> D >> N;
	for (int i = 0; i < N; i++) cin >> L[i] >> R[i];
	for (int i = 0; i < N; i++)
	{
		change[L[i] - 1]++;
		change[R[i]]--;
	}
	total[0] = change[0];
	for (int i = 1; i < D; i++)
	{
		total[i] = total[i - 1] + change[i];
	}
	for (int i = 0; i < D; i++) cout << total[i] << endl;
}