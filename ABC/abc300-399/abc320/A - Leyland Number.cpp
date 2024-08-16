#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	ll A,B;
	cin >> A >> B; 
	cout << ll(pow(A, B) + pow(B, A)) << endl;
	return 0;
}