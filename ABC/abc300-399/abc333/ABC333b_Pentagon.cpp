#include <iostream>

using namespace std;

string S, T;

int	ft_diff(char a, char b)
{
	int ans = 0;
	if (a > b) ans = a - b;
	else ans = b - a;
	if (ans >= 3) ans = 5 - ans;
	return ans;
}

int main()
{
	cin >> S >> T;
	if (ft_diff(S[0], S[1]) == ft_diff(T[0], T[1])) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}