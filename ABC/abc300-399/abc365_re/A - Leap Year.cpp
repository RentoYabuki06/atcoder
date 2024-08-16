#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
	ll Y;
	cin >> Y;
	if (Y % 400 == 0)
	{
		cout << 366 << endl;
	}
	else if (Y % 100 == 0)
	{
		cout << 365 << endl;
	}
	else if (Y % 4 == 0)
	{
		cout << 366 << endl;
	}
	else
	{
		cout << 365 << endl;
	}
	return 0;
}