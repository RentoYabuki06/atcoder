#include <iostream>	
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	string S;
	cin >> N >> S;
	ll rock = 0;
	ll paper = 0;
	ll scissors = 0;
	for (int i = 0; i < N; i++)
	{
		ll new_paper = max(rock, scissors);
		ll new_scissors = max(rock, paper);
		ll new_rock = max(paper, scissors);
		if (S[i] == 'R')
		{
			new_scissors = 0;
			new_paper++;
		}
		if (S[i] == 'P')
		{
			new_rock = 0;
			new_scissors++;
		}
		if (S[i] == 'S')
		{
			new_paper = 0;
			new_rock++;
		}
		rock = new_rock;
		paper = new_paper;
		scissors = new_scissors;
	}
	cout << max({rock, paper, scissors}) << endl;
	return 0;
}