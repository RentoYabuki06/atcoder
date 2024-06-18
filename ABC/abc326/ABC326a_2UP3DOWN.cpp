#include <iostream>

using namespace std;

int main()
{
	int X, Y;
	cin >> X >> Y;
	if (Y - X >= -3 && Y - X <= 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}