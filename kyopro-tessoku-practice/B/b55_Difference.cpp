#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int Q;
int Query[100009];
int Card[100009];
set<int> ondesk_card;

int main()
{
	// 入力
	cin >> Q;
	for (int i = 1; i <= Q; i++)
	{
		cin >> Query[i] >> Card[i];
	}
	// クエリ処理
	for (int i = 1; i <= Q; i++)
	{
		if (Query[i] == 1)
		{
			ondesk_card.insert(Card[i]);
		}
		if (Query[i] == 2)
		{
			if (ondesk_card.empty())
				cout << "-1" << endl;
			else
			{	
				auto itr = ondesk_card.lower_bound(Card[i]);
                int minDiff = INT_MAX;
				if (ondesk_card.size() == 1)
					minDiff = abs(Card[i] - *ondesk_card.begin());
                if (itr != ondesk_card.end())
                {
                    minDiff = abs(Card[i] - *itr);
                }
                if (itr != ondesk_card.begin())
                {
                    itr--;
                    minDiff = min(minDiff, abs(Card[i] - *itr));
                }
				cout << minDiff << endl;
			}
		}
	}
}
