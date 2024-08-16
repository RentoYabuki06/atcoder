#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int P[N];
	cin >> P[0];
	int max_power = P[0];
	bool is_max = true;
	for (int i = 1; i < N; i++)
	{
		cin >> P[i];
		if (max_power <= P[i])
		{
			max_power = P[i];
			is_max = false;
		}
	}
	if (is_max) cout << 0 << endl;
	else cout << max_power - P[0] + 1 << endl;
	return 0;
}