#include <iostream>

using namespace std;

int main()
{
	int M, D, y, m, d;
	cin >> M >> D >> y >> m >> d;
	d++;
	if (d == D + 1)
	{
		m++;
		d = 1;
	}
	if (m == M + 1)
	{
		y++;
		m = 1;
	}
	cout << y << " " << m << " " << d << endl;
	return 0;
}