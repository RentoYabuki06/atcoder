#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	int total = 0;
	for (int i = 0; i < N; i++) total += A[i] * B[i];
	cout << total << endl;
	return 0;
}