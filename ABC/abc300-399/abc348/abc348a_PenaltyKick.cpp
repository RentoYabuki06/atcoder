#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	main()
{
	int	N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		if ((i + 1) % 3 == 0)
			cout << "x";
		else
			cout << "o";
	}
	cout <<endl;
	return 0;
}
