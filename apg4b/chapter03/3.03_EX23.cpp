#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A.at(i);
	}

	map<int, int> mode;
	for (int i = 0; i < N; i++)
	{
		int x = A.at(i);
		if (mode.count(x))
		{
			mode.at(x)++;
		}
		else
		{
			mode[x] = 1; //要素追加
		}
	}

	int max_mode = 0;
	int max_index = -1;
	for (int i = 0; i < N; i++)
	{
		if (max_mode < mode.at(i))
		{
			max_mode = mode.at(i);
			max_index = i;
		}	
	}
	cout << max_mode << " " << max_index << endl;
}