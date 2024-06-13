#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int D[109];
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> D[i];
		if (i < 10)
		{
			if (i <= D[i]) ans++;
			if (i * 10 + i  <= D[i]) ans ++;
		}
		else
		{
			if (i / 10 == i % 10)
			{
				int tmp = i / 10;
				if (tmp <= D[i]) ans++;
				if (tmp * 10 + tmp  <= D[i]) ans ++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}