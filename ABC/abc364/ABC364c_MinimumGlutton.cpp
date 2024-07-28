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

ll N, Y, X;
vector<ll> A;
vector<ll> B;

int main()
{
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++)
    {
		ll a, b;
        cin >> a;
		A.push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
		ll b;
        cin >> b;
		B.push_back(b);
    }
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	ll amasa = 0;
	ll karasa = 0;
	for (int i = 1; i <= N; i++)
	{
		amasa += A[i - 1];
		karasa += B[i - 1];
		if (amasa > X || karasa > Y)
		{
			cout  << i << endl;
			return 0;
		}
	}
	cout << N << endl;
    return 0;
}
