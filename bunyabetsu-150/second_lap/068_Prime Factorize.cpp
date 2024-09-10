#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	ll tmp;
	cin >> N;
	cout << N << ":";
	tmp = N;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (tmp % i == 0)
		{
			cout << " " << i;
			tmp /= i;
			i--;
		}
	}
	if (tmp > 1) cout << " " << tmp;
	cout << endl;
	return 0;
}
