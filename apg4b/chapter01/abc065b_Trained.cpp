#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int count = 1;
	vector<int> button(N);
	for (int i = 1; i <= N; i++) cin >> button.at(i);
	int next = 1;
	for (int i = 0; i < 100100; i++)
	{
		next = button.at(next);
		if (next == 2)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}
