#include <iostream>
#include <vector>
#include <string>

int	main()
{
	int	N;
	cin >> N;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num.at(i);
	}
	vector<string> str(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num.at(i);
	}
	cout << endl;
	return 0;
}
