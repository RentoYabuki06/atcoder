#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int A, B, min_AB, ans;

int main()
{
	cin >> A >> B;
	min_AB = min(A, B);
	ans = 1;
	for (int i = 2; i <= min_AB; i++)
	{
		if (A % i == 0 && B % i == 0)
		{
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}