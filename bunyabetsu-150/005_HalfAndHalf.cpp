#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, X, Y;

int main()
{
	cin >> A >> B >> C >> X >> Y;
	long long ans = 0;
	if (A + B > 2 * C)
	{
		int minXY = min(X, Y);
		ans += 2 * minXY * C;
		X -= minXY;
		Y -= minXY;
	}
	if (A > 2 * C) ans += 2 * X * C;
	else ans += A * X;
	if (B > 2 * C) ans += 2 * Y * C;
	else ans += B * Y;
	cout << ans << endl;
	return 0;
}