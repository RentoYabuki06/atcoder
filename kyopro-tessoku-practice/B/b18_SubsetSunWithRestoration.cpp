#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, A[69];
bool dp[69][10009];
vector<int> Answer;

int main()
{
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	dp[0][0] = true;
	for (int i = 1; i <= S; i++) dp[0][i] = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= S; j++)
		{
			if (j >= A[i])
			{
				if (dp[i - 1][j] == true || dp[i - 1][j - A[i]] == true)
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
			else
			{
				if (dp[i - 1][j] == true)
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
		}
	}
	if (dp[N][S] == true)
	{
		int place = N;
		int num = S;
		while (1)
		{
			if (place == 0)
				break;
			if (dp[place - 1][num] == true)
			{
				place -= 1;
			}
			else
			{
				Answer.push_back(place);
				num -= A[place];
				place -= 1;
			}
		}
		reverse(Answer.begin(), Answer.end());
		cout << Answer.size() << endl;
		for (int i = 0; i < Answer.size(); i++)
		{
			if (i > 0) cout << " ";
			cout << Answer[i];
		}
		cout << endl;
	}
	else cout << "-1" << endl;
	return 0;
}