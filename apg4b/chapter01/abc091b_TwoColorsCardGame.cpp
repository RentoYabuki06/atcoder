#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compare(string a, string b)
{
    int i = 0;
	if (a.length() != b.length())
		return -1;
    while (i < a.length() - 1 && a.at(i) == b.at(i))
    {
        i++;
    }
	return a.at(i) - b.at(i);
}

int main()
{
	int N, M;
	cin >> N;
	vector<string> blue(N);
	for (int i = 0; i < N; i++) cin >> blue.at(i);
	cin >> M;
	vector<string> red(M);
	for (int i = 0; i < M; i++) cin >> red.at(i);
	vector<int> num(N);
	for (int i = 0; i < N; i++) num.at(i) = 1;
	for (int i = 0; i < N; i++)
	{
		if (num.at(i) == 0)
		{
			continue;
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				if (compare(blue.at(i), blue.at(j)) == 0 && i < j)
				{
					num.at(i)++;
					num.at(j) = 0;
				}
			}
			for (int j = 0; j < M; j++)
			{
				if (compare(blue.at(i), red.at(j)) == 0)
				{
					num.at(i)--;
				}
			}
		}
	}
	int maximam = 0;
	for (int i = 0; i < N; i++)
	{
		if (num.at(i) > maximam)
		{
			maximam = num.at(i);
		}
	}
	cout << maximam << endl;
	return 0;
}