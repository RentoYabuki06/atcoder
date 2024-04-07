#include <iostream>
#include <vector>
#include <string>

using namespace std;

int	main()
{
	int	N;
	cin >> N;

	int map[N][2];
	for (int i = 0; i < N; i++)
	{
		cin >> map[i][0] >> map[i][1];
	}
	for (int i = 0; i < N; i++)
	{
		int len = 0;
		int max = 0;
		int max_num = -1;
		for (int j = 0; j < N; j++)
		{
			len = (map[i][0] - map[j][0]) * (map[i][0] - map[j][0]) +  (map[i][1] - map[j][1]) *(map[i][1] - map[j][1]) ;
			if (len > max)
			{
				max = len;
				max_num = j;
			}
		
		}
		cout << max_num + 1 << endl;
	}
	return 0;
}