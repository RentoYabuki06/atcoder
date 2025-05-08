#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	float L = 1;
	float R = 100;
	for (int i = 0; i < 10000; i++)
	{
		float mid = (L + R) / 2;
		if ((mid * mid * mid) + mid > N) R = mid;
		else L = mid;
	}
	cout << L << endl;
	return 0;
}