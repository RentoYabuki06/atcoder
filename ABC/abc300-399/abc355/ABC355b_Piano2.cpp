# include <iostream>
# include <vector>
#include <algorithm>

using namespace std;

int N,M;
int A[109];
int B[109];
vector<pair<int, int>> c;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		c.push_back(make_pair(A[i], 1));
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
		c.push_back(make_pair(B[i], 2));
	}
	
	sort(c.begin(), c.end());
	for (int i = 1; i < c.size(); i++)
	{
		if (c[i].second == 1 &&  c[i-1].second == 1)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
