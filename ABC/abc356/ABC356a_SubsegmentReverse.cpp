#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int L, R,N,tmp;

int main()
{
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		if (L == i) tmp = i;
		if (L <= i && R >= i) cout << tmp + R  - i;
		else cout << i;
	}
	cout << endl;
	return 0;
}