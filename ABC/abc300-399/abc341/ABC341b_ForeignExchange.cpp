#include <iostream>

using namespace std;

int N;
long long A[200009];
long long S[200009];
long long T[200009];

int main()
{
	// 入力
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N - 1; i++) cin >> S[i] >> T[i];
	// 両替
	for (int i = 1; i <= N - 1; i++)
	{
		A[i + 1] += (A[i] / S[i]) * T[i]; 
	}
	// 出力
	cout << A[N] << endl;
}