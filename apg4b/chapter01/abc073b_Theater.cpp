#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> l >> r;
		count += r - l + 1;
	}
	cout << count << endl;
	return 0;
}