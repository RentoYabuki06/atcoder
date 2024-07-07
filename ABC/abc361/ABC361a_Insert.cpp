#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;
typedef long long ll;

ll N, K , X;
ll A[109];

int main()
{
	cin >> N >> K >> X;
	for (int i = 0; i < N ; i++) cin >> A[i];
	for (int i = 0; i < N ; i++)
	{
		if (i > 0) cout <<  " ";
		cout <<  A[i];
		if (i + 1 == K ) cout << " " << X;
	}
    return 0;
}
