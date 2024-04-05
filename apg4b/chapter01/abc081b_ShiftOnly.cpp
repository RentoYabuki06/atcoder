#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> num(N);
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		num.at(i) = A;
	}
	int count = 0;
	while (1)
	{
		for (int i = 0; i < N; i++)
		{
			if (num.at(i) % 2 != 0 || num.at(i) < 2)
			{
				cout << count << endl;
				return 0;
			}
			num.at(i) /= 2;
		}
		count++;
	}
	return 0;
}