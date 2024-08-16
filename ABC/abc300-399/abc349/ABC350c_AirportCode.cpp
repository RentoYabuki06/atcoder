#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

string S, T, t;

int main()
{
	cin >> S >> T;
	t.resize(3);
	for (int i = 0; i < 3; i++)
	{
		t[i] = tolower(T[i]);
		// cout << t[i] << endl;
	}
	if (T[2]=='X')
	{
		int place = 0;
		int i = -1;
		while(1)
		{
			int flag = 0;
			i++;
			if (i == 2)
			{
				cout << "Yes" << endl;
				return 0;
			}
			for (int j = place; j < (int)S.size(); j++)
			{
				if (S[j] == t[i])
				{
					flag = 1;
					place = j +1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "No" << endl;
				return 0;
			}
		}

	}
	else
	{
		int i = -1;
		int place = 0;
		while(1)
		{
			int flag = 0;
			i++;
			if (i == 3)
			{
				cout << "Yes" << endl;
				return 0;
			}
			for (int j = place; j < (int)S.size(); j++)
			{
				if (S[j] == t[i])
				{
					place = j + 1;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << "No" << endl;
				return 0;
			}
		}

	}
	
	return 0;
}