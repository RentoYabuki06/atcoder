#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> city(N);
	for (int i = 0; i < 2 * M; i++)
	{
		int a;
		cin >> a;
		city.at(a - 1)++;
	}
	for (int i = 0; i < N; i++)
	{
		cout << city.at(i) << endl;
	}
	return 0;
}