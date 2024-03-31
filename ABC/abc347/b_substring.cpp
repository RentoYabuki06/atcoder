#include <bits/stdc++.h>
using namespace std;

int	main()
{
	string S;
	string tmp;
	cin >> S;
	int length = S.length();
	int count = 0;

	unordered_set<string> A;
	for (int i = 1; i <= length; i++)
	{
		for (int j = 0; j <= length - i; j++)
		{
			tmp = S.substr(j, i);
			if (A.find(tmp) == A.end())
			{
				A.insert(tmp);
				count++;
			}
		}
	}
	cout << count << endl;
}