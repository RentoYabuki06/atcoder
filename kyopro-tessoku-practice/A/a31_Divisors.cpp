#include <iostream>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long d3 = N / 3;
	long long d5 = N / 5;
	long long d15 = N / 15;

	long long ans = d3 + d5 -d15;
	cout << ans << endl;
	return 0;
}