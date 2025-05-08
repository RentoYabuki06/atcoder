#include <iostream>
#include <cmath>

using namespace std;

int N, h[100009], min_cost[100009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> h[i];
	min_cost[1] = 0;
	min_cost[2] = abs(h[2] - h[1]);
	for (int i = 3; i <= N; i++)
	{
		min_cost[i] = min(min_cost[i - 1] + abs(h[i] - h[i - 1]), min_cost[i - 2] + abs(h[i] - h[i - 2]));
 	}
	cout << min_cost[N] << endl;
	return 0;
}