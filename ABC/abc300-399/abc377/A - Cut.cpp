#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;

ll N,K;
ll A[1000009];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = N - K ; i < N; i++)
	{
		if (i != N - K) cout << " ";
		cout << A[i];
	}
	for (int i = 0; i < N - K; i++) cout << " " << A[i];
	cout << endl;
	return 0;
}