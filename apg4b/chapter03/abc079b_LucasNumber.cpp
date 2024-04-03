#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int64_t N;
	cin >> N;
	vector<int64_t> lucasnum(N + 1);
	lucasnum.at(0) = 2;
	lucasnum.at(1) = 1;
	for (int i = 3; i <= N; i++)
	{
		lucasnum.at(i) = lucasnum.at(i - 1) + lucasnum.at(i - 2);
	}
	cout << lucasnum.at(N) << endl;
	return 0;
}

// //再帰関数ではタイムエラーに
// #include <iostream>
// using namespace std;

// int ft_lucas(int64_t N)
// {
// 	if (N == 0)
// 		return 2;
// 	if (N == 1)
// 		return 1;
// 	return (ft_lucas(N - 1) + ft_lucas(N - 2));
// }

// int main(void)
// {
// 	int64_t N;
// 	cin >> N;
// 	int64_t ans = 0;
// 	ans = ft_lucas(N);
// 	cout << ans << endl;
// 	return 0;
// }