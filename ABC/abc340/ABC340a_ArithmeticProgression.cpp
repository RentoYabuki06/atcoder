#include <iostream>

using namespace std;

int a, b, d;

int main()
{
	cin >> a >> b >> d;
	while (a != b)
	{
		cout << a << " ";
		a += d;
	}
	cout << b << endl;
	return 0;
}