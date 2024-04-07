#include <bits/stdc++.h>
using namespace std;

int	main()
{
	int	N, A, B, D;
	cin >> N >> A >> B;
	int array[A + B] = {0};
	for (int i = 0; i < N; i++)
	{
		cin >> D;
		array[D % (A + B)] = 1; 
	}
	int flag = 0;
	int first = 0;
	int first_flag = 0;
	int count = 1;
	int max = 0;
	for (int i = 0; i < A + B; i++)
	{
		if (array[i] == 0 && flag == 1)
			count++;
		else if (array[i] == 0)
		{
			flag = 1;
			count = 1;
		}
		else
		{
			if (first_flag == 0 && max > 0)
			{
				first_flag = 1;
				first = max;
			}
			else flag = 0;
		}
		if (max < count) max = count; 
	}
	if (flag == 1) count += first;
	int i = 0;
	while (array[i] == 0)
	{
		count++;
		i++;
	}
	if (max < count) max = count; 
	if (max >= B) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}