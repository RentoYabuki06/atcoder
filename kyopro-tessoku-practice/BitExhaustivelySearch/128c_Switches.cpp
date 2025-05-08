#include <iostream>

using namespace std;

int N, M;
int k[20];
int s[20][20];
int p[20];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
		{
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < M; i++) cin >> p[i];

	int count = 0;
	int flag = 1;
	for (int i = 0; i < (1 << N); i++)
	{
		flag = 1;
		for (int j = 0; j < M; j++)
		{
			int onswitch = 0;
			for (int l = 0; l < k[j]; l++)
			{
				if ((i >> (s[j][l] - 1)) & 1)
				{
					onswitch++;
				}
			}
			if (onswitch % 2 != p[j])
			{
				flag = -1;
				break;
			}
		}
		if (flag == 1)
		{
			count++;
		}
	}
	cout << count << endl;
}