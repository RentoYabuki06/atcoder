#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int tmp = N % 5;
	if (tmp > 5- tmp) cout << N - tmp + 5 << endl;
	else cout << N  + tmp << endl;
	return 0;
}