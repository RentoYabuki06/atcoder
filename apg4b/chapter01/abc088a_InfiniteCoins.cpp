#include <iostream>

using namespace std;

int main()
{
	int N, A;
	cin >> N >> A;
	int mod = N % 500;
	if (mod <= A)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}