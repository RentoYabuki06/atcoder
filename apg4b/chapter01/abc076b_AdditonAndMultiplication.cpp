#include <iostream>

using namespace std;

int main()
{
	int N , K;
	cin >> N >> K;
	int display = 1;
	for (int i = 0; i < N; i++)
	{
		if (display * 2 > display + K)
		{
			display += K;
		}
		else
		{
			display *= 2;	
		}
	}
	cout << display << endl;
	return 0;
}