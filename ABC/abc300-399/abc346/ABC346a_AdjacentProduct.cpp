#include <iostream>

using namespace std;

int main()
{
	int N;
	int A[109];
	cin >> N;
	for (int i= 1; i<= N; i++) cin >> A[i];
	for (int i= 1; i< N; i++)
	{
		if (i != 1) cout << " ";
		cout << A[i] * A[i + 1];
	}
	cout << endl;
	return 0;
}