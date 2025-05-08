#include <iostream>

using namespace std;

int T, N, L[500009], R[500009], change[500009], total[500009];

int main()
{
	cin >> T >> N;
	for(int i = 0; i < N; i++) cin >> L[i] >> R[i];
	for(int i = 0; i < N; i++)
	{
		change[L[i]]++;
		change[R[i]]--;
	}
	total[0] = change[0];
	cout << total[0] << endl;
	for(int i = 1; i < T; i++)
	{
		total[i] = total[i - 1] + change[i];
		cout << total[i] << endl;
	}
	return 0;
}