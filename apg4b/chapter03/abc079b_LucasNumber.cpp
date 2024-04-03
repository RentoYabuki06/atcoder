#include <iostream>
using namespace std;

int ft_lucas(int N)
{
	if (N == 0)
		return 2;
	if (N == 1)
		return 1;
	return (ft_lucas(N - 1) + ft_lucas(N - 2));
}

int main(void)
{
	int N;
	cin >> N;
	int ans = 0;
	ans = ft_lucas(N);
	cout << ans << endl;
	return 0;
}