#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, P, Q;
	cin >> N >> P >> Q;
	vector<int> D(N);
	for (int i = 0; i < N; i++) cin >> D[i];
	sort(D.begin(), D.end());
	if (D[0] + Q > P) cout << P << endl;
	else cout << D[0] + Q << endl;
	return 0;
}