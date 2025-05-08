#include <iostream>

using namespace std;

int N, A[100009], B[100009], min_time[100009];

int main()
{
	cin >> N;
	for (int i = 2; i <= N; i++) cin >> A[i];
	for (int i = 3; i <= N; i++) cin >> B[i];
	min_time[1] = 0;
	min_time[2] = A[2];
	for (int i = 3; i <= N; i++)
	{
		min_time[i] = min(min_time[i - 1] + A[i], min_time[i - 2] + B[i]);
	}
	cout << min_time[N] << endl;
}