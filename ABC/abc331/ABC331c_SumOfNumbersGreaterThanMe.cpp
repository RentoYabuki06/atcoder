#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long N;
	cin >> N;
	long long A[N + 1];
	vector<int> num(N);
	for (int i = 0; i < N; i++) 
	{
		cin >> A[i];
		num[i] = A[i];
	}
	sort(num.begin(), num.end());
	long long cumsum[N + 1];
	cumsum[N - 1] = num[N - 1];
	for (int i = N - 2; i >= 0; i--) cumsum[i] = cumsum[i + 1] + num[i];
	for (int i = 0; i < N; i++) 
	{
		if (i > 0) cout << " ";
		long long pos = upper_bound(num.begin(), num.end(), A[i]) - num.begin();
		if (pos >= N) cout << 0;
		else cout << cumsum[pos];
	}
	cout << endl;
	return 0;
}