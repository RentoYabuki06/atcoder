#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int N;
int A[100009];
int W[100009];
vector<int> boxex[100009];

int main()
{
	cin >> N;
	for (int i = 1; i <= N ; i++) cin >> A[i];
	for (int i = 1; i <= N ; i++) cin >> W[i];
	for (int i = 1; i <= N ; i++)
	{
		boxex[A[i]].push_back(W[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= N ; i++)
	{
		if (boxex[i].size() > 0)
		{
			sort(boxex[i].begin(), boxex[i].end());
			for (int j = 0; j < boxex[i].size()-1; j++)
			{
				ans += boxex[i][j];
			}
		}
	}
	cout << ans << endl;
    return 0;
}
