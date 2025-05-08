#include <iostream>

using namespace std;

int n, X;
int a[30];

int main()
{
	cin >> n >> X;
	for (int i = 0; i < n; i++) cin >> a[i];
	int price = 0;
	for (int i = n - 1 ; i >= 0; i--)
	{
		if (X / (1 << i) == 1)
		{
			price += a[i];
			X -= (1 << i);
		}
	}
	cout << price << endl;
	return 0;
}