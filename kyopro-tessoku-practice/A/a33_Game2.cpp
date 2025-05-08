#include <iostream>

using namespace std;

int main()
{
	int N;
	int A[100009];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	// ニム和を求める
	int xor_sum = A[1];
	for (int i = 2; i <= N; i++) xor_sum = (xor_sum ^ A[i]);

	//出力
	if (xor_sum == 0) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}