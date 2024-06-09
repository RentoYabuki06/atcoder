#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int H[109];

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = 1; i <= N; i++)
	{
		M -= H[i];
		if (M < 0)
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	cout << N << endl;
	return 0;
}