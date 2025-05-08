#include <iostream>

using namespace std;

int main()
{
	long long N, M, B;
	long long A[200009];
	long long C[200009];
	cin >> N >> M >> B;
	int sum_time_routeA = 0;
	int sum_time_routeC = 0;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) cin >> C[i];
	for (int i = 1; i <= N; i++) sum_time_routeA += A[i];
	for (int i = 1; i <= M; i++) sum_time_routeC += C[i];
	long long total_time = sum_time_routeA * M + sum_time_routeC * N + B * N * M; 
	cout << total_time << endl;
	return 0;
}