#include <iostream>

using namespace std;

long long a, b, lcm;

long long ft_GCD(long long A, long long B)
{
	while(A > 0 && B > 0)
	{
		if (A >= B) A = A % B;
		else B = B % A;
	}
	if (A != 0) return A;
	return B;
}

int main()
{
	cin >> a >> b;
	lcm = a * b / ft_GCD(a, b);
	cout << lcm << endl;
	return 0;
}