#include <iostream>

using namespace std;

int N, L, R;
int A[200009];

int main()
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		if (L > A[i]) cout << L;
		else if (R < A[i]) cout << R;
		else cout << A[i];
	}
	cout << endl;
	return 0;
}