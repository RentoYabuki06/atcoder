#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int D, N;
	int L[10009], R[10009], H[10009];
	int max_worktime[10009];
	cin >> D >> N;
	for (int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];
	for (int i = 1; i <= D; i++) max_worktime[i] = 24;
	for (int i = 1; i <= N; i++)
	{
		for (int j = L[i]; j <= R[i]; j++)
		{
			max_worktime[j] = min(max_worktime[j], H[i]);
		}
	}
	int total_worktime = 0;
	for (int i = 1; i <= D; i++) total_worktime += max_worktime[i];
	cout << total_worktime << endl;
	return 0;
}