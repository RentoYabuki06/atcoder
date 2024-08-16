#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, S, M, L;
	cin >> N >> S >> M >> L;
	long long ans = 100000000000000;
	for (int i = 0; i <= 17; i++)
	{
		for (int j = 0; j <= 13; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				long long total = S * i + M * j + L * k;
				if (i * 6 + j * 8 + k * 12 >= N) ans = min(ans, total);
			}
		}
	}
	cout << ans << endl;
	return 0;
}