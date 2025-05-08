#include <iostream>

using namespace std;

int main()
{
	long long N;
	cin >> N;

	long long d3 = N / 3;
	long long d5 = N / 5;
	long long d7 = N / 7;
	long long d15 = N / 15;
	long long d35 = N / 35;
	long long d21 = N / 21;
	long long d105 = N / 105;

	long long ans = d3 + d5 + d7 -d15 - d21 -d35 + d105;
	cout << ans << endl;
	return 0;
}