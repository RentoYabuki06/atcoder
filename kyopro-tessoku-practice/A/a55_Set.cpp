#include <iostream>
#include <set>

using namespace std;

int Q;
int Query[100009];
int Card[100009];
set<int> S;

int main()
{
	// 入力
	cin >> Q;
	for (int i = 1; i <= Q; i++)
		cin >> Query[i] >> Card[i];
	for (int i = 1; i <= Q; i++)
	{
		if (Query[i] == 1)
			S.insert(Card[i]);
		if (Query[i] == 2)
			S.erase(Card[i]);
		if (Query[i] == 3)
		{
			auto itr = S.lower_bound(Card[i]);
			if (itr == S.end())
				cout << "-1" << endl;
			else
				cout << (*itr) << endl;
		}
	}
	return 0;
}

