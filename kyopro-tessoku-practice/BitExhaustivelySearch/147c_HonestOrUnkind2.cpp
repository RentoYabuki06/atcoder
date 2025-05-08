#include <iostream>

using namespace std;

int N;
int A[20];
int info[20][20][20];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		for (int j = 0; j < A[i]; j++)
		{
			cin >> info[i][j][0] >> info[i][j][1];
		}
	}
	int max_person = 0;
	for (int i = 0; i < (1 << N); i++)
	{
		// int testimony[20] = {-1};
		int flag = 1;
		int count = 0;
		for (int j = N - 1; j >= 0; j--)
		{
			if ((i >> j) & 1)
			{
				// printf("i is [%d] j is [%d] max is[%d]\n", i , j, max_person);
				for (int k = 0; k < A[j]; k++)
				{
					int tmp_person = info[j][k][0] - 1;
					int tmp_num = info[j][k][1];
					// if (i == 3)
					// {
					// 	printf("j is [%d] k is[%d] person is [%d] tmp is[%d]\n",j, k, tmp_person , tmp_num);
					// }
					if (tmp_num == 0)
					{
						if (((i >> tmp_person) & 1))
						{
							flag = -1;
							break;
						}
					}
					if (tmp_num == 1)
					{
						if (!((i >> tmp_person) & 1))
						{
							flag = -1;
							break;
						}
					}
					// if (i == 3)
					// {
					// 	printf("j is [%d] person is [%d] tmp is[%d]flag is [%d]\n",j, tmp_person , tmp_num, flag);
					// }
					// if (testimony[tmp_person] == -1)
					// {
					// 	testimony[tmp_person] = tmp_num;
					// }
					// else if (testimony[tmp_person] != tmp_num)
					// {
					// 	flag = -1;
					// 	break;
					// }
				}
			}
			// if (i == 3)
			// {
			// 	printf("j is [%d] flag is [%d]\n",j, flag);
			// }
			if (flag == -1)
			{
				break;
			}
		}
		// printf("i is [%d]max is [%d] flag is[%d]\n",i, max_person, flag);
		if (flag == 1)
		{
			int bit_count = 0;
			int temp_i = i;
			while (temp_i != 0) {
				bit_count += temp_i & 1;
				temp_i >>= 1;
			}
			count = bit_count;

			if (max_person < count)
				max_person = count;
		}
	}
	cout << max_person << endl;
	return 0;
}