#include <iostream>

using namespace std;

int N;

int main()
{
	cin >> N;
	int count = 0;
	while(N % 2 == 0)
	{
		count++;
		N /= 2;
	}
	cout << count << endl;
	return 0;
}