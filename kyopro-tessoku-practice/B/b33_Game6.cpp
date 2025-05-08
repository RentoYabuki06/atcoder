#include <iostream>

using namespace std;

int main()
{
	int N, H , W;
	int A[100009];
	int B[100009];
	cin >> N >> H >> W;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> B[i];
		A[i] -= 1;
		B[i] -= 1;
	}

	// ニム和を求める
	int xor_sum_a = A[1];
	for (int i = 2; i <= N; i++) xor_sum_a = (xor_sum_a ^ A[i]);
	int xor_sum_b = B[1];
	for (int i = 2; i <= N; i++) xor_sum_b = (xor_sum_b ^ B[i]);
	// 出力
	int xor_sum = xor_sum_a ^ xor_sum_b;
	if (xor_sum == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}