#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	if (((N / 10) % 111 == 0) || ((N % 1000) % 111 ==0))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}