#include <iostream>

using namespace std;

int main()
{
	int a,b, ave;
	cin >> a >> b;
	if ((a + b) % 2 == 0)
	{
		ave = (a + b) / 2;
	}
	else
	{
		ave = (a + b) / 2 + 1;
	}
	cout << ave << endl;
	return 0;
}