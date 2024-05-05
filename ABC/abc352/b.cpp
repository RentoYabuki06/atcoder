#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

string S,T;	

int main()
{
	cin >> S >> T;
	for(int i = 0 ; i < S.size(); i++)
	{
		for(int j = 0 ; j < T.size(); j++)
		{
			if (S[i] == T[j])
			{
				cout << j+1;
				i++;
				cout << " ";
			}
		}
	}
	cout << endl;
	return 0;
}

