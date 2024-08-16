#include <iostream>

using namespace std;

long long A, M, L, R;

long long left_tree(long long x)
{
	if (x % M == 0) return x / M;
	else if (x < 0) return (x / M) - 1;
	else return x / M;
}

int main()
{
	cin >> A >> M >> L >> R;
	// 木の一番右を求める
	R -= A;
	L -= A;
	long long count = 0;
	cout << left_tree(R) - left_tree(L - 1) << endl;
	return 0;
}