#include <iostream>

using namespace std;

int main()
{
	long long X, Y;
	long long A[1000009], B[1000009];
	cin >> X >> Y;
	long long count = 0;
	while (X > 1 || Y > 1)
	{
		A[count] = X;
		B[count] = Y;
		if (X > Y) X -= Y;
		else Y -= X;
		count++;
	}
	cout << count << endl;
	if (count > 0)
	{
		for (int i = count - 1; i >= 0; i--)
		{
			cout << A[i] << " " << B[i] << endl;
		}
	}
}