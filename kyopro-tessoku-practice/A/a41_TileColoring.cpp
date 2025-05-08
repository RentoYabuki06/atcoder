#include <iostream>

using namespace std;

int main()
{
	int N;
	int count_blue = 0;
	int count_red = 0;
	char S;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> S;
		if (S == 'B')
		{
			count_blue++;
			count_red = 0;
		}
		else
		{
			count_blue = 0;
			count_red++;
		}
		if (count_blue >= 3 || count_red >= 3)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}