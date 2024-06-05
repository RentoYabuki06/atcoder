#include <iostream>

using namespace std;

int N, S, K;
int P[109];
int Q[109];

int main()
{
	cin >> N >> S >> K;
	int total_price = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[i] >> Q[i];
		total_price += P[i] * Q[i];
	}
	if (total_price < S) total_price += K;
	cout << total_price << endl;
	return 0;
}