#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int deci = 0;
	for (int i = 0; N > 0; i++)
	{
		deci += (N % 2) * (1 << i);
		N /= 10;
	}
	cout << deci << endl;
}