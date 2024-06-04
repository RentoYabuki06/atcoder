#include <iostream>

using namespace std;

int B, G;

int main()
{
	cin >> B >> G;
	if (B > G)
	{
		cout << "Bat" << endl;
		return 0;
	}
	else
	{
		cout << "Glove" << endl;
		return 0;
	}
}