#include <iostream>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	if (!(A % 3 == 0) && A == B - 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}