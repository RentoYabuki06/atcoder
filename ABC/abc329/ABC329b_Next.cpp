#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int A[109];
	int ans = 0;
	int top = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		if (A[i] > top)
		{
			ans = top;
			top = A[i];
		}
		else if (A[i] > ans && A[i] < top)
		{
			ans = A[i];
		}
	}
	cout << ans << endl;
	return 0;
}