#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
	ll N, K, X;
	ll A[109];
	cin >> N >> K >> X;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << A[i];
		if (i == K - 1) cout << " " << X;
	}
	return 0;
}