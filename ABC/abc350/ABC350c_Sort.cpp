#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int N, Q;
int A[200009];
vector<int> B;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int count = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		while (A[i] != i)
		{
			B.push_back(i);
			B.push_back(A[i]);
			int tmp = A[A[i]];
			A[A[i]] = A[i];
			A[i] = tmp;
			count++;
		}
	}
	cout << count << endl;
	for (int i = 0; i < B.size(); i += 2) cout << B[i] << " " << B[i + 1] << endl;
	return 0;
}