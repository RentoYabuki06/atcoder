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

int N;
int A[200009];
int C[200009];
vector<pair<int, int>> cards;
bool trash[200009];

int main()
{
	cin >> N;
	int count_cards = N;
	for (int i = 1; i <= N; i++) trash[i] = false;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i] >> C[i];
		cards.push_back(make_pair(C[i], i));
	}
	sort(cards.begin(), cards.end());
	int highest_card = 0;
	for (int i = 0; i < N; i++)
	{
		int idx = cards[i].second;
		if (highest_card > A[idx])
		{
			count_cards--;
			trash[idx] = true;
		}
		else highest_card = A[idx];
	}
	cout << count_cards << endl;
	bool tmp = false;
	for (int i = 1; i <= N; i++)
	{
		if(trash[i] == false)
		{
			if (tmp) cout << " ";
			cout << i;
			tmp = true;
		}
	}
	cout << endl;
	return 0;
}

